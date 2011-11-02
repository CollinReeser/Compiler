


all:	printfAsm.o puts.o printfasmTest printfC.o castlessConvert.o putchar.o \
		putcharTest

printfAsm.o:	printfAsm.asm
		nasm -f elf32 printfAsm.asm
		
printfC.o:		printfC.c putchar.o puts.o
		gcc -c printfC.c -m32
		
puts.o:		puts.asm
		nasm -f elf32 puts.asm
	
putchar.o:	putchar.asm
		nasm -f elf32 putchar.asm
		
putcharTest:	putcharTest.c putchar.o
		gcc -o putcharTest putcharTest.c putchar.o -m32
		
castlessConvert.o:	castlessConvert.asm
		nasm -f elf32 castlessConvert.asm
		
printfasmTest:	printfasmTest.c printfAsm.o puts.o printfC.o castlessConvert.o 
		gcc -o printfasmTest printfAsm.o printfasmTest.c printfC.o castlessConvert.o putchar.o puts.o -m32
