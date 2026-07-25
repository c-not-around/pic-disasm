unit UArgsParser;


uses System;
uses System.Collections.Generic;
uses System.Globalization;
uses System.Text.RegularExpressions;


type
  ArgumentType =
  (
    StringArg  = 0,
    IntegerArg = 1,
    BooleanArg = 2,
    DoubleArg  = 3
  );
  
  ArgumentInfo = class
    {$region Fields}
    private _FullName : string;
    private _Type     : ArgumentType;
    private _Default  : object;
    private _Desc     : string;
    {$endregion}
    
    {$region Ctors}
    public constructor (name: string; &type: ArgumentType; &default: object; desc: string);
    begin
      _FullName := name;
      _Type     := &type;
      _Default  := &default;
      _Desc     := desc;
    end;
    {$endregion}
    
    {$region Properties}
    public property FullName   : string       read _FullName;
    
    public property &Type      : ArgumentType read _Type;
    
    public property &Default   : object       read _Default;
    
    public property Description: string       read _Desc;
    {$endregion}
  end;
  
  ArgsParser = class
    {$region Fields}
    private _Arguments : Dictionary<string,ArgumentInfo>;
    private _Values    : Dictionary<string,object>;
    private _IsEmpty   : boolean;
    {$endregion}
    
    {$region Ctors}
    public constructor ();
    begin
      _Arguments := new Dictionary<string,ArgumentInfo>();
      _Values    := new Dictionary<string,object>();
      _IsEmpty   := true;
    end;
    {$endregion}
    
    {$region Properties}
    public property ArgumentsIsEmpty: boolean read _IsEmpty;
    
    public property HelpText: string read (GetDescription());
    
    public property Overrides: string read (GetOverrides());
    
    public property ArgumentsShortNames: List<string> read (_Arguments.Keys.ToList());
    
    public property ArgumentsFullNames: List<string> read (GetArgumentsNames());
    
    public property ArgumentValue[name: string]: object read (GetArgumentValue(name)); default;
    
    public property StringArgumentValue[name: string]: string read (GetStringArgumentValue(name));
    
    public property IntegerArgumentValue[name: string]: integer read (GetIntegerArgumentValue(name));
    
    public property BooleanArgumentValue[name: string]: boolean read (GetBooleanArgumentValue(name));
    
    public property DoubleArgumentValue[name: string]: double read (GetDoubleArgumentValue(name));
    {$endregion}
    
    {$region Methods}
    public function AddArg(full, short: string; &type: ArgumentType; &default: object := nil; desc: string := ''): boolean;
    begin
      result := not _Arguments.ContainsKey(short);
      
      if result then
        _Arguments.Add(short, new ArgumentInfo(full, &type, &default, desc));
    end;
    
    private function TryParseInteger(image: string; var value: integer): boolean;
    begin
      if String.IsNullOrWhiteSpace(image) then
        exit(false);
      
      image  := image.Trim().ToLower();
      result := Int32.TryParse(image, NumberStyles.Integer, nil, value);
      
      if not result then
        begin
          if image.StartsWith('0x') then
            image := image.Substring(2)
          else if image.StartsWith('$') then
            image := image.Substring(1)
          else if image.EndsWith('h') then
            image := image.TrimEnd('h');
          
          result := Int32.TryParse(image, NumberStyles.HexNumber, nil, value);
        end;
    end;
    
    private function TryParseDouble(image: string; var value: double): boolean;
    begin
      if String.IsNullOrWhiteSpace(image) then
        exit(false);
      
      image  := image.Trim().Replace(',', '.');
      result := Double.TryParse(image, NumberStyles.Float, nil, value);
    end;
    
    public procedure Parse(args: array of string);
    begin
      _IsEmpty := args.Length < 2;
      
      if _IsEmpty then
        exit;
      
      foreach var name in _Arguments.Keys do
        begin
          var EscName := Regex.Escape(name);
          var ArgExp  := $'((-|/){EscName}|--{_Arguments[name].FullName})';
          var ArgType := _Arguments[name].Type;
          
          if ArgType <> ArgumentType.BooleanArg then
            ArgExp += $'=(?<val>.+)';
          
          var OptionRegex := new Regex(ArgExp, RegexOptions.IgnoreCase);
          
          foreach var arg in args do
            begin
              var option := OptionRegex.Match(arg);
              
              if option.Success then
                begin
                  var s := option.Groups.Count > 3 ? option.Groups[3].Value : '';
                  
                  case ArgType of
                    ArgumentType.BooleanArg:
                      begin
                        _Values.Add(name, true);
                      end;
                    ArgumentType.StringArg:
                      begin
                        if not String.IsNullOrEmpty(s) then
                          _Values.Add(name, s);
                      end;
                    ArgumentType.IntegerArg:
                      begin
                        var i: integer;
                        if TryParseInteger(s, i) then
                          _Values.Add(name, i);
                      end;
                    ArgumentType.DoubleArg:
                      begin
                        var d: double;
                        if TryParseDouble(s, d) then
                          _Values.Add(name, d);
                      end;
                  end;
                  
                  break;
                end;
            end;
          
          if not _Values.ContainsKey(name) then
            _Values.Add(name, _Arguments[name].Default);
          
          OptionRegex := nil;
        end;
    end;
    
    public function GetDescription(): string;
    begin
      result := '';
      
      var MaxLenFull := 0;
      var MaxLenDef  := 0;
      foreach var name in _Arguments.Keys do
        begin
          var FullLen := _Arguments[name].FullName.Length;
          var DefLen  := _Arguments[name].Default.ToString().Length;
          
          if _Arguments[name].Type = ArgumentType.StringArg then
            DefLen += 2;
          
          if FullLen > MaxLenFull then
            MaxLenFull := FullLen;
          
          if DefLen > MaxLenDef then
            MaxLenDef := DefLen;
        end;
      
      foreach var name in _Arguments.Keys do
        begin
          var full  := _Arguments[name].FullName;
          var def   := _Arguments[name].Default.ToString();
          var desc  := _Arguments[name].Description;
          
          if _Arguments[name].Type = ArgumentType.StringArg then
            def := '"' + def + '"';
          
          var afull := new string(' ', MaxLenFull-full.Length);
          var adef  := new string(' ', MaxLenDef-def.Length);
          
          result += $'-{name}=<{full}>{afull} default={def}{adef} {desc}{#13#10}';
        end;
    end;
    
    public function GetOverrides(): string;
    begin
      result := '';
      
      foreach var name in _Arguments.Keys do
        begin
          var val  := _Values[name];
          var def  := _Arguments[name].Default;
          var full := _Arguments[name].FullName;
          
          if val <> def then
            result += $'{full}={val}{#13#10}';
        end;
    end;
    
    public function GetArgumentsNames(): List<string>;
    begin
      result := new List<string>();
      
      foreach var name in _Arguments.Keys do
        result.Add(_Arguments[name].FullName);
    end;
    
    public function GetArgumentValue(name: string): object;
    begin
      if _Values.ContainsKey(name) then
        exit(_Values[name]);
      
      foreach var key in _Arguments.Keys do
        if _Arguments[key].FullName = name then
          exit(_Values[key]);
      
      result := nil;
    end;
    
    public function GetStringArgumentValue(name: string) := string(GetArgumentValue(name));
    
    public function GetIntegerArgumentValue(name: string) := integer(GetArgumentValue(name));
    
    public function GetBooleanArgumentValue(name: string) := boolean(GetArgumentValue(name));
    
    public function GetDoubleArgumentValue(name: string) := double(GetArgumentValue(name));
    {$endregion}
  end;


end.