#include <stdio.h>

//extern printf_cr(char* buf);
extern printf_cr(char* buf , ...);

int main(int argc , char** argv)
{
	char* str = "Hello%d\n%f\n";
	printf("int: %d long: %d float: %d double: %d\n",sizeof(int),sizeof(long),sizeof(float),sizeof(double));
	double x = 54.2345678235;
	printf("x:%f\n",x);
	float y = (float)x;
	printf("y:%f\n",y);
	printf_cr(str,123456,2.125);
	return 0;
}
