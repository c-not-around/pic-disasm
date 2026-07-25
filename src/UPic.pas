unit UPic;


{$reference Newtonsoft.Json.dll}
{$reference System.IntelHex.dll}


uses System;
uses System.IO;
uses System.Text;
uses System.Text.RegularExpressions;
uses System.Collections.Generic;
uses System.IntelHex;
uses Newtonsoft.Json;


type
  PicIdLocations = class
    public auto property Offset : integer;
    public auto property Count  : integer;
    public auto property Mask   : byte;
  end;
  
  PicConfigFieldValue = class
    public auto property Value    : integer;
    public auto property Mnemonic : string;
  end;
  
  PicConfigFieldValues = array of PicConfigFieldValue;
  
  PicConfigField = class
    public auto property Name   : string;
    public auto property Mask   : integer;
    public auto property Values : PicConfigFieldValues;
    
    public function Format(w: word): string;
    begin
      var field := w and Mask;
      var value := Values.Find(v -> v.Value = field);
      result := value.Mnemonic;
    end;
  end;
  
  PicConfigFields = array of PicConfigField;
  
  PicConfigWord = class
    public auto property Offset : integer;
    public auto property Bits   : PicConfigFields;
  end;
  
  PicConfigWords = array of PicConfigWord;
  
  EepromInfo = class
    public auto property Offset : integer;
    public auto property Size   : integer;
  end;
  
  PicInfo = class;
  
  PicInfos = array of PicInfo;
  
  PicInfo = class
    {$region Fields}
    private [JsonIgnoreAttribute] _CoreRegisters: List<byte>;
    private [JsonIgnoreAttribute] _DumpInfo: array of IntelHexSegmentInfo;
    {$endregion}
    
    {$region Properties}
    public auto property Processor   : string;
    public auto property RomSize     : integer;
  	public auto property RamBanks    : integer;
  	public auto property RamOffset   : byte;
  	public auto property ComOffset   : byte;
  	public auto property CoreRegs    : string;
  	public auto property IdLocations : PicIdLocations;
  	public auto property ConfigWords : PicConfigWords;
  	public auto property Eeprom      : EepromInfo;
  	
  	public [JsonIgnoreAttribute] property CoreRegisters: List<byte> read _CoreRegisters;
  	public [JsonIgnoreAttribute] property ConfigWordsCount: integer read (ConfigWords.Length);
  	public [JsonIgnoreAttribute] property IsCoreRegister[reg: byte]: boolean read (_CoreRegisters.IndexOf(reg) <> -1);
  	public [JsonIgnoreAttribute] property DumpInfo: array of IntelHexSegmentInfo read _DumpInfo;
    {$endregion}
    
    {$region Methods}
    private procedure MakeDumpInfo();
    begin
      _DumpInfo    := new IntelHexSegmentInfo[4];
      _DumpInfo[0] := new IntelHexSegmentInfo($0000,                 RomSize,           IntelHexSegmentType.Word, $3FFF); // Flash
      _DumpInfo[1] := new IntelHexSegmentInfo(IdLocations.Offset,    IdLocations.Count, IntelHexSegmentType.Word, $3FFF); // UserIds
      _DumpInfo[2] := new IntelHexSegmentInfo(ConfigWords[0].Offset, ConfigWordsCount,  IntelHexSegmentType.Word, $3FFF); // Config
      _DumpInfo[3] := new IntelHexSegmentInfo(Eeprom.Offset,         Eeprom.Size,       IntelHexSegmentType.Word, $3FFF); // Eeprom
    end;
    {$endregion}
    
    {$region Static}
    public static function Load(fname: string): PicInfos;
    begin
      result := JsonConvert.DeserializeObject&<PicInfos>(&File.ReadAllText(fname));
      
      var CoreRegex := new Regex('([0-9A-Fa-f]{2})(?:-([0-9A-Fa-f]{2}))?');
      
      for var i := 0 to result.Length-1 do
        begin
          result[i]._CoreRegisters := new List<byte>();
          
          foreach var m: &Match in CoreRegex.Matches(result[i].CoreRegs) do
            begin
              var head := Convert.ToByte(m.Groups[1].Value, 16);
              
              if m.Groups[2].Success then
                begin
                  var tail := Convert.ToByte(m.Groups[2].Value, 16);
                  
                  for var reg := head to tail do
                    result[i]._CoreRegisters.Add(reg);
                end
              else
                result[i]._CoreRegisters.Add(head);
            end;
          
          result[i].MakeDumpInfo();
        end;
    end;
    {$endregion}
  end;


end.