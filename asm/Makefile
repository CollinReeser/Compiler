


all:	printfAsm.o puts.o printfasmTest printfC.o

printfAsm.o:	printfAsm.asm
		nasm -f elf32 printfAsm.asm
		
printfC.o:		printfC.c
		gcc -c printfC.c -m32
		
puts.o:		puts.asm
		nasm -f elf32 puts.asm
		
printfasmTest:	printfasmTest.c printfAsm.o puts.o printfC.o
		gcc -o printfasmTest printfAsm.o printfasmTest.c printfC.o -m32 puts.o
