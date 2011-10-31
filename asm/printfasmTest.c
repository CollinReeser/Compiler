#include <stdio.h>

//extern printf_cr(char* buf);
extern printf_cr(char* buf , ...);

int main(int argc , char** argv)
{
	char* str = "Hello\n";
	//printf(str);
	printf_cr(str);
	return 0;
}
