all:	utilities tests

utilities:	ShuntingYard.o SourceRead.o SimpleTextUtil.h StripComments.o RPNNotation.o MiscTextUtil.o RPNCollapse.o

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
		
RPNCollapse.o:	RPNCollapse.cpp RPNNotation.h SimpleTextUtil.h
		g++ -c RPNCollapse.cpp

tests:	utilities shunt sourceReadTest rpnTest collapseTest

shuntingYardTest.o:	shuntingYardTest.cpp
		g++ -c shuntingYardTest.cpp

sourceReadTest.o:	sourceReadTest.cpp
		g++ -c sourceReadTest.cpp 

rpnNotationTest.o:	rpnNotationTest.cpp
		g++ -c rpnNotationTest.cpp
		
RPNCollapseTest.o:	RPNCollapseTest.cpp
		g++ -c RPNCollapseTest.cpp

shunt:	ShuntingYard.o shuntingYardTest.o
		g++ -o shunt shuntingYardTest.o ShuntingYard.o

sourceReadTest: sourceReadTest.o SourceRead.o StripComments.o
		g++ -o sourceReadTest sourceReadTest.o SourceRead.o StripComments.o

rpnTest:	RPNNotation.o rpnNotationTest.o ShuntingYard.o
		g++ -o rpnTest rpnNotationTest.o RPNNotation.o ShuntingYard.o
		
collapseTest:	RPNCollapse.o RPNCollapseTest.o ShuntingYard.o RPNNotation.o RPNCollapse.o
		g++ -o rpnCollapseTest RPNCollapseTest.o ShuntingYard.o RPNNotation.o RPNCollapse.o

clean:
		rm ShuntingYard.o
		rm SourceRead.o
		rm sourceReadTest.o
		rm shuntingYardTest.o
		rm StripComments.o

realclean:	clean
		rm shunt
		rm sourceReadTest

