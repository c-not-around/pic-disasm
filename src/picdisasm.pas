uses System;
uses System.IO;
uses Disassembly;


begin
  var args := Environment.GetCommandLineArgs();
  
  var source    := '';
  var processor := '';
  var outfile   := '';
  var listing   := false;
  var asmfile   := false;
  var helptext  := args.Length = 1;
  
  var OptionRegex := new Regex('-(?<opt>[hpola?])(=(?<val>.+))?', RegexOptions.IgnoreCase);
  
  foreach var arg in args do
    begin
      var option := OptionRegex.Match(arg);
      
      if option.Success then
        begin
          var s := option.Groups.Count > 2 ? option.Groups[3].Value : '';
        
          case option.Groups[2].Value.ToLower() of
            'h': source    := s;
            'p': processor := s;
            'o': outfile   := s;
            'l': listing   := true;
            'a': asmfile   := true;
            '?': helptext  := true;
          end;
        end;
    end;
  
  if helptext then
    Console.WriteLine
    (
      '-h=<source.hex>  Source IntelHex (*.hex) file'#13#10 +
      '-p=<processor>   Crystal type: PIC16F628A -> 16f628a, PIC12F1840 -> 12f1840, ... etc.'#13#10 +
      '-o=<outfile>     Specify out-file path without extension: e.g. -o=C:\Temp\p16f628a_dump'#13#10 +
      '-l               Save listing to file "<outfile>.lst"'#13#10 +
      '-a               Save asm-code to file "<outfile>.asm"'
    );
  
  if not ((args.Length = 1) or (args.Length = 2) and (helptext))  then
    if (source <> '') and (processor <> '') and (listing or asmfile) then
      begin
        try
          var path   := AppDomain.CurrentDomain.BaseDirectory;
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
      end
    else
      Console.WriteLine('Invalid arguments.');
end.