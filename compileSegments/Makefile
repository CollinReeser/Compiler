


all:	test test2 test2asm CAssembleExpression.s

test:	../utilities/RPNNotation.o ../utilities/ShuntingYard.o \
			compCRPNExpression.cpp compCRPNTest.cpp
	g++ -o test ../utilities/RPNNotation.o ../utilities/ShuntingYard.o \
		compCRPNExpression.cpp compCRPNTest.cpp

test2:	../utilities/RPNNotation.o ../utilities/ShuntingYard.o \
			compCRPNExpression.cpp compCRPNTestF.cpp
	g++ -o test2 ../utilities/RPNNotation.o ../utilities/ShuntingYard.o \
		compCRPNExpression.cpp compCRPNTestF.cpp

test2.asm:	test2
	./test2 > test2.asm

test2asm.o:	test2.asm
	nasm -f elf32 -o test2asm.o test2.asm

test2asm:	test2asm.o
	gcc -o test2asm test2asm.o -m32

CAssembleExpression.s:	CAssembleExpression.c
	gcc -S CAssembleExpression.c

clean:
	rm test2.asm test2asm.o CAssembleExpression.s test test2 test2asm\
		test2.asm