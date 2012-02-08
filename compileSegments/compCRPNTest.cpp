// This file is a test for the compCRPNSegmentI function, which produces an
// assembly segment that computes the arithmetic result of an infix expression
// consisting entirely of integer constants. Uses forked nasm and gcc processes
// to produce the final executable


#include <string>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include "../utilities/SimpleTextUtil.h"
#include "../utilities/RPNNotation.h"

std::string compFullCRPNSegment( RPNNotation RPN );

int main(int argc , char** argv)
{
	std::string infix = "(14+(19*8+(2*56+(-304-2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12";
	SimpleTextUtil util;
	std::string postfix = util.convertInfixToPostfix( infix );
	// This will be the file that we write the compiled output to
	std::ofstream outfile;
	outfile.open("test.asm");
	outfile << "; " << postfix << std::endl;
	outfile << "; " << ( (14+(19*8+(2*56+(-304-2*(1001+(17-(16+(-22*(3+3*12)))))))))+60/12 ) << std::endl;
	RPNNotation note;
	note.convertStrToRPN( postfix );
	std::string full = compFullCRPNSegment( note );
	// Write assembled code to a file
	outfile << full;
	// Close the file, which allows the forked processes access
	outfile.close();
	// Fork the process. We will do it twice, first to assemble, then to link
	pid_t pid = fork();
	// Run this block if we are the child
	if ( pid == 0 )
	{
		std::cout << "Assembling compiled output..." << std::endl;
		// Exec nasm. The arguments are: The path to the executable we want
		// to run, the name of the executable itself (redundant but needed),
		// then all the arguments to the executable, all in the way they would
		// be expected on the terminal
		int ret = execl ("/usr/bin/nasm", "nasm", "-f", "elf32" , "-o" , 
			"testasm.o" , "test.asm" , (char *)0 );
		std::cout << "Child process failed to exec \"nasm\"" << std::endl;
	}
	// Run this block if we are the parent
	else
	{
		// Wait for the nasm process to exit
		waitpid( pid , 0 , 0 );
		// Fork the process to run gcc
		pid = fork();
		// We run this block if we are the child
		if ( pid == 0 )
		{
			std::cout << "Linking assembled output..." << std::endl;
			int ret = execl ("/usr/bin/gcc", "gcc", "-o", "testasm" , 
				"testasm.o" , "-m32" , (char *)0 );
			std::cout << "Child process failed to exec \"gcc\"" << std::endl;
		}
		// We run this block if we are the parent
		else
		{
			// Wait for the gcc process to exit
			waitpid( pid , 0 , 0 );
			std::cout << "Executable created with name: testasm" << std::endl;
		}
	}
	return 0;
}
