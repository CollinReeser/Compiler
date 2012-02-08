


all:	
		g++ -o test ../utilities/RPNNotation.o ../utilities/ShuntingYard.o compCRPNExpression.cpp compCRPNTest.cpp
		g++ -o test2 ../utilities/RPNNotation.o ../utilities/ShuntingYard.o compCRPNExpression.cpp compCRPNTestF.cpp
		gcc -S CAssembleExpression.c
		./test2 > test2.asm
		nasm -f elf32 -o test2asm.o test2.asm
		gcc -o test2asm test2asm.o -m32
