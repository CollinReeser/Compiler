

all:	tests

tests:	testLex testParse

testLex:	testLex.o lexer.o ../utilities/MiscTextUtil.o \
			../utilities/ShuntingYard.o ../utilities/SourceRead.o \
			../utilities/StripComments.o
	g++ -o testLex testLex.o lexer.o ../utilities/ShuntingYard.o \
	../utilities/MiscTextUtil.o ../utilities/SourceRead.o \
	../utilities/StripComments.o
	
testParse:	testParse.o lexer.o parser.o TopLevelContainer.o ClassContainer.o \
			FunctionContainer.o ParseContainer.o ../utilities/MiscTextUtil.o \
			../utilities/ShuntingYard.o ../utilities/SourceRead.o \
			../utilities/StripComments.o
	g++ -o testParse testParse.o lexer.o parser.o TopLevelContainer.o \
	ClassContainer.o FunctionContainer.o ParseContainer.o \
	../utilities/MiscTextUtil.o ../utilities/ShuntingYard.o \
	../utilities/SourceRead.o ../utilities/StripComments.o

testLex.o:	testLex.cpp
	g++ -c testLex.cpp
	
testParse.o:	testParse.cpp
	g++ -c testParse.cpp
	
lexer.o:	lexer.cpp lexer.h
	g++ -c lexer.cpp
	
parser.o:	parser.cpp parser.h ParseContainer.h TopLevelContainer.h \
			ClassContainer.h FunctionContainer.h
	g++ -c parser.cpp
	
TopLevelContainer.o:	TopLevelContainer.cpp TopLevelContainer.h \
						ClassContainer.h FunctionContainer.h ParseContainer.h
	g++ -c TopLevelContainer.cpp
	
ClassContainer.o:	ClassContainer.cpp ClassContainer.h FunctionContainer.h \
					ParseContainer.h
	g++ -c ClassContainer.cpp
	
FunctionContainer.o:	FunctionContainer.cpp FunctionContainer.h \
						ParseContainer.h
	g++ -c FunctionContainer.cpp
	
ParseContainer.o:	ParseContainer.cpp ParseContainer.h
	g++ -c ParseContainer.cpp
	
ForContainer.o: ForContainer.cpp ForContainer.h ScopeContainer.h
	g++ -c ForContainer.cpp

IfContainer.o:	IfContainer.cpp IfContainer.h ScopeContainer.h
	g++ -c IfContainer.cpp
	
SwitchContainer.o:	SwitchContainer.cpp SwitchContainer.h ScopeContainer.h
	g++ -c SwitchContainer.cpp

WhileContainer.o:	WhileContainer.cpp WhileContainer.h ScopeContainer.h
	g++ -c WhileContainer.cpp

StatementContainer.o:	StatementContainer.h
	g++ -c StatementContainer.cpp
	
clean:
	rm ClassContainer.o
	rm FunctionContainer.o
	rm lexer.o
	rm parser.o
	rm testLex.o
	rm testParse.o
	rm ParseContainer.o
	rm TopLevelContainer.o
	
realclean:	clean
	rm testLex
	rm testParse
	
