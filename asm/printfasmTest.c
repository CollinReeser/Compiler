#include <stdio.h>

//extern printf_cr(char* buf);
extern printf_cr(char* buf , ...);

int main(int argc , char** argv)
{
	char* str = "Hello\n%d\n%f\n";
	/*
	printf("int: %d long: %d float: %d double: %d\n",sizeof(int),sizeof(long),sizeof(float),sizeof(double));
	double x = 54.2345678235;
	printf("x:%f\n",x);
	float y = (float)x;
	printf("y:%f\n",y);
	*/
	int i;
	for ( i = 0; i < 1; i++ )
	{
		printf_cr(str,123456,2.123456789);
		//printf(str,123456,2.123456789);
	}
	return 0;
}
