# PIC microcontrollers disassembler

A console utility for disassembling hex dumps of PIC microcontrollers. Can convert an input hex dump file into an output disassembled listing file (`.ist`) or into an assembly code file (`.asm`) (in HI-TECH PICC assembler format), or both simultaneously.

## Supported

* MidRange PIC12/PIC16
* Enhanced MidRange PIC12/PIC16

## Command line options

| Option            | Descroption                                                              |
| :---------------- | :----------------------------------------------------------------------- |
| `-h=<source.hex>` | Source IntelHex (`*.hex`) file                                           |
| `-p=<processor>`  | Crystal type: PIC16F628A -> `16f628a`, PIC12F1840 -> `12f1840`, ... etc. |
| `-o=<outfile>`    | Specify out-file path without extension: e.g. `-o=C:\Temp\p16f628a_dump` |
| `-l`              | Save listing to file `<outfile>.lst`                                     |
| `-a`              | Save asm-code to file `<outfile>.asm`                                    |

## Configuration files

* The file `p16is.json` contains a description of the command system of the MidRange PIC12/PIC16 family of microcontrollers.
* The file `p16db.json` contains descriptions (of parameters required for disassembling) of some microcontrollers.