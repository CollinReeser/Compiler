

all:	tests

tests:	testLex testParse

testLex:	testLex.o lexer.o ../utilities/MiscTextUtil.o \
			../utilities/ShuntingYard.o ../utilities/SourceRead.o \
			../utilities/StripComments.o
	g++ -o testLex testLex.o lexer.o ../utilities/ShuntingYard.o \
	../utilities/MiscTextUtil.o ../utilities/SourceRead.o \
	../utilities/StripComments.o
	
testParse:	testParse.o lexer.o parser.o TopLevelContainer.o \
			ParseContainer.o ../utilities/MiscTextUtil.o \
			../utilities/ShuntingYard.o ../utilities/SourceRead.o \
			../utilities/StripComments.o
	g++ -o testParse testParse.o lexer.o parser.o TopLevelContainer.o \
	ParseContainer.o \
	../utilities/MiscTextUtil.o ../utilities/ShuntingYard.o \
	../utilities/SourceRead.o ../utilities/StripComments.o

testLex.o:	testLex.cpp
	g++ -c testLex.cpp
	
testParse.o:	testParse.cpp
	g++ -c testParse.cpp
	
lexer.o:	lexer.cpp lexer.h
	g++ -c lexer.cpp
	
parser.o:	parser.cpp parser.h ParseContainer.h TopLevelContainer.h
	g++ -c parser.cpp
	
TopLevelContainer.o:	TopLevelContainer.cpp TopLevelContainer.h \
							ParseContainer.h
	g++ -c TopLevelContainer.cpp

ParseContainer.o:	ParseContainer.cpp ParseContainer.h
	g++ -c ParseContainer.cpp
	
clean:
	rm lexer.o parser.o testLex.o testParse.o ParseContainer.o\
		TopLevelContainer.o testLex testParse
	
