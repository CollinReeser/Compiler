

all:	tests

tests:	testLex

testLex:	testLex.o lexer.o
	g++ -o testLex testLex.o lexer.o ../utilities/ShuntingYard.o ../utilities/MiscTextUtil.o ../utilities/SourceRead.o

testLex.o:	testLex.cpp
	g++ -c testLex.cpp
	
lexer.o:	lexer.cpp lexer.h
	g++ -c lexer.cpp
