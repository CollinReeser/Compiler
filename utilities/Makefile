

all:	utilities tests

utilities:	ShuntingYard.o SourceRead.o SimpleTextUtil.h StripComments.o RPNNotation.o MiscTextUtil.o
		
ShuntingYard.o:	ShuntingYard.cpp SimpleTextUtil.h
		g++ -c ShuntingYard.cpp
		
MiscTextUtil.o:	MiscTextUtil.cpp SimpleTextUtil.h
		g++ -c MiscTextUtil.cpp
		
SourceRead.o:	SourceRead.cpp SimpleTextUtil.h
		g++ -c SourceRead.cpp
		
StripComments.o:	StripComments.cpp SimpleTextUtil.h
		g++ -c StripComments.cpp
		
RPNNotation.o:	RPNNotation.cpp RPNNotation.h
		g++ -c RPNNotation.cpp
		
tests:	utilities shunt sourceReadTest rpnTest

shuntingYardTest.o:	shuntingYardTest.cpp
		g++ -c shuntingYardTest.cpp
		
sourceReadTest.o:	sourceReadTest.cpp
		g++ -c sourceReadTest.cpp 
		
rpnNotationTest.o:	rpnNotationTest.cpp
		g++ -c rpnNotationTest.cpp
		
shunt:	ShuntingYard.o shuntingYardTest.o
		g++ -o shunt shuntingYardTest.o ShuntingYard.o
		
sourceReadTest: sourceReadTest.o SourceRead.o StripComments.o
		g++ -o sourceReadTest sourceReadTest.o SourceRead.o StripComments.o
		
rpnTest:	RPNNotation.o rpnNotationTest.o
		g++ -o rpnTest rpnNotationTest.o RPNNotation.o ShuntingYard.o
		
clean:
		rm ShuntingYard.o
		rm SourceRead.o
		rm sourceReadTest.o
		shuntingYardTest.o
		StripComments.o
		
realclean:	clean
		rm shunt
		rm sourceReadTest
