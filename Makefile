all: 
	cd LexParse && $(MAKE)
	cd asm && $(MAKE)
	cd compileSegments && $(MAKE)
	cd utilities && $(MAKE)

clean:
	cd LexParse && $(MAKE) clean
	cd asm && $(MAKE) clean
	cd compileSegments && $(MAKE) clean
	cd utilities && $(MAKE) clean