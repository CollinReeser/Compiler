


all:	
		g++ -o test ../utilities/RPNNotation.o ../utilities/ShuntingYard.o compCRPNExpression.cpp compCRPNTest.cpp
		g++ -o test2 ../utilities/RPNNotation.o ../utilities/ShuntingYard.o compCRPNExpression.cpp compCRPNTestF.cpp
		gcc -S CAssembleExpression.c
		./test > test.asm
		./test2 > test2.asm
		nasm -f elf32 -o testasm.o test.asm
		gcc -o testasm testasm.o -m32
		nasm -f elf32 -o test2asm.o test2.asm
		gcc -o test2asm test2asm.o -m32
