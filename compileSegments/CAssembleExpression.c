// This C program is meant to be compiled using the -S flag, such that the
// resulting assembly file can then be analyzed.
// RESULT: GCC, rather predictably, does indeed evaluate the entire expression
// and then merely use the final result in the actual assembly file, as a very
// easy way to optimize the code

int main( int argc , char** argv )
{
	float result = 1.0/2.0*3.0+4.5-6.0/3.0+8.625*3.0-(2.5+3.4/1.25)+8.2;
	return 0;
}
