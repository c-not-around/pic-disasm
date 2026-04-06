unit Disassembly;


{$reference Newtonsoft.Json.dll}
{$reference System.IntelHex.dll}


uses System;
uses System.IO;
uses System.Text;
uses System.Text.RegularExpressions;
uses System.Collections.Generic;
uses System.IntelHex;
uses Newtonsoft.Json;
uses Pic;


type
  ParameterInfo = class
    {$region Properties}
    public auto property Name   : string;
    public auto property Mask   : word;
    public auto property Offset : integer;
    {$endregion}
    
    {$region Methods}
    public function GetValue(command: word) := word((command and self.Mask) shr self.Offset);
    {$endregion}
  end;
  
  InstructionInfo = class
    {$region Properties}
    public auto property Format      : string;
    public auto property Mnemonic    : string;
    public auto property Opcode      : word;
    public auto property OpcodeMask  : word;
    public auto property Parameters  : array of ParameterInfo;
    public auto property Cycles      : string;
    public auto property Description : string;
    {$endregion}
    
    {$region Methods}
    public function GetParameter(name: string) := Parameters.Find(p -> p.Name = name);
    {$endregion}
  end;
  
  AssemlyInfo = array of InstructionInfo;
  
  RegInfo = class
    {$region Fields}
    private _Name    : string;
    private _Address : word;
    {$endregion}
    
    {$region Ctors}
    public constructor (name: string; adr: string);
    begin
      _Name    := name;
      _Address := Convert.ToUInt16(adr, 16);
    end;
    {$endregion}
    
    {$region Properties}
    public property Name    : string read _Name;
    
    public property Address : word   read _Address;
    {$endregion}
  end;
  
  BitInfo = class
    {$region Fields}
    private _Name    : string;
    private _NameReg : string;
    private _Number  : integer;
    {$endregion}
    
    {$region Ctors}
    public constructor (name: string; reg: string; bit: string);
    begin
      _Name    := name;
      _NameReg := reg;
      _Number  := Convert.ToInt32(bit) and 7;
    end;
    {$endregion}
    
    {$region Properties}
    public property Name    : string  read _Name;
    
    public property NameReg : string  read _NameReg;
    
    public property Number  : integer read _Number;
    {$endregion}
  end;
  
  RegisterInfo = class
    {$region Fields}
    private _IsRam : boolean;
    private _Name  : string;
    private _Bits  : Dictionary<integer,string>;
    {$endregion}
    
    {$region Ctors}
    public constructor (name: string);
    begin
      _IsRam := false;
      _Name  := name;
    end;
    
    private constructor ();
    begin
      _IsRam := true;
    end;
    {$endregion}
    
    {$region Properties}
    public property Name : string read _Name;
    
    public property Bits[b: integer]: string read (_Bits.ContainsKey(b) ? _Bits[b] : b.ToString());
    {$endregion}
    
    {$region Methods}
    public function Format(value: word; com: byte) := _IsRam ? string.Format('{1}_{0:X2}h', value, value < com ? 'ram' : 'com') : _Name;
    
    public function FormatBit(value: word) := _IsRam ? $'{value}' : Bits[value];
    {$endregion}
    
    {$region Static}
    private static _RamRegister := new RegisterInfo();
    
    public static property RamRegisterInfo: RegisterInfo read _RamRegister;
    
    private static function NameSelect(s1, s2: string): string;
    begin
      var c1 := s1.IndexOf('1') = -1;
      var c2 := s1.IndexOf('1') = -1;
      
      if c1 = c2 then
        begin
          c1 := s1[s1.Length] = 'L';
          c2 := s2[s2.Length] = 'L';
          
          if c1 = c2 then
            begin
              c1 := s1.Length < s2.Length;
              c2 := s2.Length < s1.Length;
            end
        end;
      
      result := c1 ? s1 : s2;
    end;
    
    public static function Load(fname: string): Dictionary<word,RegisterInfo>;
    begin
      var RegRegex := new Regex('(?<reg>\w+)\W+equ\W+\((?<value>[0-9a-fA-F]{1,4})h\W+&\W+07Fh\)', RegexOptions.IgnoreCase);
      var BitRegex := new Regex('(?<bit>\w+)\W+equ\W+(?<value>\d)\W+;\W+(?<reg>\w+)', RegexOptions.IgnoreCase);
      
      var regs := new List<RegInfo>();
      var bits := new List<BitInfo>();
      
      foreach var line in &File.ReadAllLines(fname) do
        begin
          var reg := RegRegex.Match(line);
          if reg.Success then
            begin
              regs.Add(new RegInfo(reg.Groups[1].Value, reg.Groups[2].Value));
              continue;
            end;
          
          var bit := BitRegex.Match(line);
          if bit.Success then
            bits.Add(new BitInfo(bit.Groups[1].Value, bit.Groups[3].Value, bit.Groups[2].Value));
        end;
      
      result := new Dictionary<word,RegisterInfo>();
      
      foreach var reg in regs do
        begin
          if result.ContainsKey(reg.Address) then
            begin
              var name := NameSelect(result[reg.Address].Name, reg.Name);
              if name = reg.Name then
                result.Remove(reg.Address)
              else
                continue;
            end;
          
          var sfr   := new RegisterInfo(reg.Name);
          sfr._Bits := new Dictionary<integer, string>();
          
          var map := bits.FindAll(b -> b.NameReg = reg.Name);
          foreach var info in map do
            begin
              if sfr._Bits.ContainsKey(info.Number) then
                begin
                  if info.Name.Length < sfr._Bits[info.Number].Length then
                    sfr._Bits.Remove(info.Number)
                  else
                    continue;
                end;
              
              sfr._Bits.Add(info.Number, info.Name);
            end;
          
          result.Add(reg.Address, sfr);
        end;
    end;
    {$endregion}
  end;
  
  Pic16DisassemblyResult = record
    public Listing: string;
    public AsmFile: string;
  end;
  
  Pic16DisAssembler = class
    {$region Fields}
    private _AssemlyInfo : AssemlyInfo;
    private _PicInfos    : PicInfos;
    private _InfoIndex   : integer;
    private _RegisterMap : Dictionary<word,RegisterInfo>;
    private _LastBank    : integer;
    private _LastPclath  : integer;
    private _LabelList   : List<word>;
    {$endregion}
    
    {$region Ctors}
    public constructor (IsInfo, McuInfo: string);
    begin
      _AssemlyInfo := JsonConvert.DeserializeObject&<AssemlyInfo>(&File.ReadAllText(IsInfo));
      _PicInfos    := PicInfo.Load(McuInfo);
      _RegisterMap := nil;
    end;
    {$endregion}
    
    {$region Properties}
    public static property DummyWord : word read ($3FFF);
    
    public auto property IncludePath: string;
    
    private property CurrentPicInfo: PicInfo read (_PicInfos[_InfoIndex]);
    {$endregion}
    
    {$region Methods}
    private static function GetSignedLiteralValue(value: word; bits: integer): integer;
    begin
      var mask := 1 shl bits;
      result := (value and mask) = 0 ? value : -((mask shl 1) - value);
    end;
    
    private function FindRegisterName(address: word): RegisterInfo;
    begin
      var info := CurrentPicInfo;
      var reg  := address and $7F;
      
      if (_RegisterMap <> nil) and (reg < info.RamOffset) then
        begin
          if (_LastBank <> -1) and (not info.IsCoreRegister[reg]) then
            reg += $80 * _LastBank;
          
          for var i := 0 to info.RamBanks-1 do
            begin
              if _RegisterMap.ContainsKey(reg) then
                exit(_RegisterMap[reg]);
              
              reg += $80;
            end;
        end;
      
      result := RegisterInfo.RamRegisterInfo;
    end;
    
    private function DecodeInstruction(command: word; address: integer): string;
    begin
      var op := _AssemlyInfo.Find(o -> (command and o.OpcodeMask) = o.Opcode);
  
      result := '';
      
      if (op = nil) or (command = DummyWord) then
        exit;
      
      var line := Regex.Replace(op.Format, '\s{1,4}', #9);
      
      if op.Parameters.Length > 0 then
        begin
          var Fparam := op.GetParameter('f');
          
          if Fparam <> nil then
            begin
              var Fvalue := Fparam.GetValue(command);
              
              if op.Mnemonic = 'TRIS' then
                begin
                  var tris := 'TRIS' + ((Fvalue > 4) and (Fvalue < 8) ? 'ABC'.Substring(Fvalue-5) : $'_{Fvalue}');
                  line := line.Replace(Fparam.Name, tris);
                end
              else
                begin
                  var Fname := FindRegisterName(Fvalue);
                  
                  line := line.Replace(Fparam.Name, Fname.Format(Fvalue, CurrentPicInfo.ComOffset));
                  
                  var Dparam := op.GetParameter('d');
                  var Bparam := op.GetParameter('b');
                  
                  if Dparam <> nil then
                    begin
                      var Dvalue := Dparam.GetValue(command);
                      line := line.Replace(Dparam.Name, Dvalue = 0 ? 'W' : (Dvalue = 1 ? 'F' : $'{Dvalue}'));
                    end
                  else if Bparam <> nil then
                    begin
                      var Bvalue := Bparam.GetValue(command);
                      line := line.Replace(Bparam.Name, Fname.FormatBit(Bvalue));
                    end;
                end;
            end;
          
          var Kparam := op.GetParameter('k');
          
          if Kparam <> nil then
            begin
              var Kvalue := Kparam.GetValue(command);
              var formatted: string;
              
              case op.Mnemonic of
                'MOVLB' : begin
                            _LastBank := Kvalue;
                            formatted := $'BANK{_LastBank}';
                          end;
                'MOVLP' :  begin
                            _LastPclath := Kvalue;
                            formatted   := $'0x{Kvalue:X2}';
                          end;
                'BRA'   : begin
                            var pc := address + 1 + GetSignedLiteralValue(Kvalue, 8);
                            formatted := $'l_{pc:X4}';
                            if not _LabelList.Contains(pc) then
                              _LabelList.Add(pc);
                          end;
                'CALL',
                'GOTO'  : begin
                            var pc := Kvalue and $07FF;
                            if _LastPclath <> -1 then
                              pc := pc or ((_LastPclath shl 8) and  $7800);
                            formatted := $'l_{pc:X4}';
                            if not _LabelList.Contains(pc) then
                              _LabelList.Add(pc);
                          end;
                'ADDFSR',
                'MOVIW', 
                'MOVWI' : begin
                            var k := GetSignedLiteralValue(Kvalue, 5);
                            formatted := k.ToString();
                          end;
                else formatted := $'0x{Kvalue:X2}';
              end;
              
              line := line.Replace(Kparam.Name, formatted);
            end;
          
          var Nparam := op.GetParameter('n');
          
          if Nparam <> nil then
            begin
              var fsr := $'FSR{Nparam.GetValue(command)}';
              
              var Mparam := op.GetParameter('m');
              
              if Mparam <> nil then
                begin
                  case Mparam.GetValue(command) of
                    0: fsr := '++' + fsr;
                    1: fsr := '--' + fsr;
                    2: fsr := fsr + '++';
                    3: fsr := fsr + '--';
                  end;
                  
                  line := line.Replace(','+Mparam.Name, '');
                end;
              
              line := line.Replace(Nparam.Name, fsr);
            end;
        end;
      
      result += line;
    end;
    
    private function DecodeInstructions(flash: array of word): array of string; 
    begin
      _RegisterMap := RegisterInfo.Load($'{IncludePath}\{CurrentPicInfo.Processor}.inc');
      
      _LastBank   := -1;
      _LastPclath := -1;
      _LabelList  := new List<word>();
      
      var length := flash.Length;
      
      result := new string[length];
      
      for var i := 0 to length-1 do
        result[i] := DecodeInstruction(flash[i], i);
    end;
    
    private procedure MakeHeader(dump: List<IntelHexSegment>; builder: StringBuilder);
    begin
      var info := CurrentPicInfo;
      var uids := dump[1].Words;
      var conf := dump[2].Words;
      var eep  := dump[3].Words;
      
      builder.Append(#9#9'processor'#9);
      builder.AppendLine(info.Processor);
      builder.Append(#9#9'include'#9#9'"');
      builder.Append(info.Processor.ToLower());
      builder.AppendLine('.inc"');
      builder.AppendLine(#9#9);
      
      if conf.Sum(w -> (w and DummyWord) = DummyWord ? 0 : 1) > 0 then
        begin
          builder.AppendLine(#9#9'; Configuration words');
          builder.AppendLine(#9#9'psect'#9#9'config_words,class=CONFIG,delta=2');
          for var i := 0 to info.ConfigWordsCount-1 do
            begin
              builder.Append(#9#9'DW'#9#9#9);
              var bits := info.ConfigWords[i].Bits;
              for var b := bits.Length-1 downto 0 do
                begin
                  builder.Append(bits[b].Format(conf[i]));
                  if b > 0 then
                    builder.Append(' & ');
                end;
              builder.AppendLine();
            end;
          builder.AppendLine(#9#9);
        end;
      
      if uids.Sum(w -> (w and info.IdLocations.Mask) = info.IdLocations.Mask ? 0 : 1) > 0 then
        begin
          builder.AppendLine(#9#9'; User IDs');
          builder.AppendLine(#9#9'psect'#9#9'userid_words,class=IDLOC,delta=2');
          builder.Append(#9#9'DW'#9#9#9);
          for var i := 0 to uids.Length-1 do
            builder.AppendFormat('{1}0x{0:X2}', uids[i] and info.IdLocations.Mask, i > 0 ? ', ' : '');
          builder.AppendLine(#13#10#9#9);
        end;
      
      if eep.Sum(w -> (w and $FF) = $FF ? 0 : 1) > 0 then
        begin
          builder.AppendLine(#9#9'; Eeprom initialization');
          builder.AppendLine(#9#9'psect'#9#9'eeprom_bytes,class=EEDATA,space=2,delta=2');
          var index := 0;
          repeat
            if (index and $7) = 0 then
              builder.Append(#9#9'DB'#9#9#9);
            builder.AppendFormat('0x{0:X2}', eep[index] and $FF);
            builder.Append((index and $7) = $7 ? #13#10 : ', ');
            index += 1;
          until index >= info.Eeprom.Size;
          builder.AppendLine(#9#9);
        end;
      
      builder.AppendLine(#9#9'global'#9#9'_main');
      builder.AppendLine(#9#9'global'#9#9'start_initialization');
      builder.AppendLine(#9#9);
      builder.AppendLine(#9#9'psect'#9#9'program_code,class=CODE,delta=2');
      builder.AppendLine(#9#9);
      builder.AppendLine(#9#9);
      builder.AppendLine('start_initialization:');
      builder.AppendLine(#9#9);
      builder.AppendLine(#9#9);
      
      for var reg := info.RamOffset to info.ComOffset-1 do
        builder.AppendFormat('ram_{0:X2}h'#9#9'EQU'#9'0x{0:X2}'#13#10, reg);
      for var reg := info.ComOffset to $7F do
        builder.AppendFormat('com_{0:X2}h'#9#9'EQU'#9'0x{0:X2}'#13#10, reg);
      builder.AppendLine(#9#9);
      builder.AppendLine(#9#9);
    end;
    
    public function Disassembly(mcu: string; hex: string): Pic16DisassemblyResult;
    begin
      mcu := mcu.ToUpper();
      
      _InfoIndex := _PicInfos.FindIndex(p -> p.Processor.ToUpper() = mcu);
      
      var info  := CurrentPicInfo;
      var dump  := IntelHex.ReadDump(hex, info.DumpInfo);
      var flash := dump[0].Words;
      var lines := DecodeInstructions(flash);
      
      var ListingBuilder := new StringBuilder();
      var AsmFileBuilder := new StringBuilder();
      
      MakeHeader(dump, AsmFileBuilder);
      
      var LastInstruction := DummyWord;
      
      for var address := 0 to lines.Length-1 do
        begin
          var instruction := flash[address];
          
          // Listing
          ListingBuilder.AppendFormat('{0:X4}:  {1:X4} ', address, instruction);
          
          if (instruction <> DummyWord) and _LabelList.Contains(address) then
            ListingBuilder.AppendFormat('l_{0:X4} ', address)
          else
            ListingBuilder.Append(' ', 7);
          
          ListingBuilder.AppendLine(lines[address]);
          
          // AsmFile
          if instruction <> DummyWord then
            begin
              if LastInstruction = DummyWord then
                AsmFileBuilder.AppendFormat(#9#9#13#10#9#9'ORG'#9#9'0x{0:X4}'#13#10, address);
              
              if _LabelList.Contains(address) then
                AsmFileBuilder.AppendFormat('l_{0:X4}:'#13#10, address);
              
              var command := lines[address];
              
              AsmFileBuilder.Append(#9#9);
              AsmFileBuilder.AppendLine(command);
              
              (*if (address > 1) and Regex.IsMatch(command, '(RET(URN|FIE))|GOTO', RegexOptions.IgnoreCase) then
                begin
                  var prev := lines[address-1] + lines[address-2];
                  
                  if not Regex.IsMatch(prev, 'CFSZ|BTFS', RegexOptions.IgnoreCase) then
                    AsmFileBuilder.AppendLine();
                end;*)
            end;
          
          LastInstruction := instruction;
        end;
      
      AsmFileBuilder.AppendLine(#9#9'END');
      
      result.Listing := ListingBuilder.ToString();
      result.AsmFile := AsmFileBuilder.ToString();
    end;
    {$endregion}
  end;


end.