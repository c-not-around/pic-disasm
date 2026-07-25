uses System;
uses System.IO;
uses UArgsParser;
uses UDisassembly;


procedure ErrorExit(text: string);
begin
  Console.WriteLine(text);
  Environment.Exit(0);
end;

begin
  var ArgParser := new ArgsParser();
  ArgParser.AddArg('help',      '?', ArgumentType.BooleanArg, false,       'Display this help text.');
  ArgParser.AddArg('processor', 'p', ArgumentType.StringArg,  '',          'Specify the processor type.');
  ArgParser.AddArg('source',    'h', ArgumentType.StringArg,  '',          'Specify the source IntelHex (*.hex) file.');
  ArgParser.AddArg('outfile',   'o', ArgumentType.StringArg,  '',          'Specify out-file path without extension: e.g. -o=C:\Temp\p16f628a_dump.');
  ArgParser.AddArg('listing',   'l', ArgumentType.BooleanArg, false,       'Save listing to file "<outfile>.lst".');
  ArgParser.AddArg('asmfile',   'a', ArgumentType.BooleanArg, false,       'Save asm-code to file "<outfile>.asm".');
  
  ArgParser.Parse(Environment.GetCommandLineArgs());
  
  if ArgParser.ArgumentsIsEmpty or ArgParser.BooleanArgumentValue['help'] then
    ErrorExit(ArgParser.HelpText);
  
  Console.WriteLine('Overriden options:');
  Console.WriteLine(ArgParser.Overrides);
  
  var processor := ArgParser.StringArgumentValue['processor'];
  var source    := ArgParser.StringArgumentValue['source'];
  var outfile   := ArgParser.StringArgumentValue['outfile'];
  var listing   := ArgParser.BooleanArgumentValue['listing'];
  var asmfile   := ArgParser.BooleanArgumentValue['asmfile'];
  
  try
    var path := AppDomain.CurrentDomain.BaseDirectory;
    
    var disasm := new Pic16DisAssembler(path + 'p16is.json', path + 'p16db.json');
    disasm.IncludePath := path + 'include'; 
    
    var res := disasm.Disassembly(processor, source);
    
    if outfile = '' then
      outfile := source;
    
    outfile := System.IO.Path.GetFileNameWithoutExtension(outfile);
    
    if listing then
      &File.WriteAllText(outfile + '.lst', res.Listing);
    
    if asmfile then
      &File.WriteAllText(outfile + '.asm', res.AsmFile);
  except on ex: Exception do
    Console.WriteLine($'fail: {ex.Message}{#13#10#13#10}{ex.StackTrace}');
  end;
end.