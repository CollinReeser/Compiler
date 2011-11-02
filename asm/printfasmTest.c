#include <stdio.h>

//extern printf_cr(char* buf);
extern printf_cr(char* buf , ...);

union infinite
{
	float infin;
	int infin2;
} infinite;

int main(int argc , char** argv)
{
	int j = 0b01111111100000000000000000000000;
	infinite.infin2 = j;
	char* str = "Hello\n%d\n%f\n";
	//printf("Size of long int: %d\n",sizeof(long long));
	long long test = 0x7FFFFFFFFFFFFFFF;
	int test2 = 0x7FFFFFFF;
	//printf("digits: %lld\n",test);
	//printf("digits: %d\n",test2);
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
		//printf_cr(str,-123456,infinite.infin);
		//printf(str,-123456,infinite.infin);
	}
	//printf_cr(str,-123456,1234567.1234);
	//printf(str,-123456,1234567.1234);
	//printf_cr("-----------------------\n");
	//printf_cr(str,-123456,.12345678);
	//printf(str,-123456,.12345678);
	//printf_cr("-----------------------\n");
	printf_cr("Dubs: %b\n",12345678901234500000.111);
	printf("Dubs: %f\n",12345678901234500000.111);
	printf_cr("-----------------------\n");
	printf_cr("Dubs: %b\n",123456789.111222333444555666777888999000111222333444555);
	printf("Dubs: %f\n",123456789.111222333444555666777888999000111222333444555);
	return 0;
}
