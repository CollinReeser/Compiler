#include <stdarg.h>

// FOR TESTING PURPOSES
#include <stdio.h>


#define CC '%'
#define STR 's'
#define NUM 'd'
#define FLT 'f'
#define CHR 'c'

// Need defines for flags that go along with the different command directives,
// and to implement a parsing system

extern void fputs_cr(char* str);
extern int fltBitsToInt(float num);
void printI(int num);
void printF(double num);


// Dammit. Well. I guess I can do this in C then, jerks.
void printf_cr(char* buf , ...)
{
	va_list args;
	va_start(args, buf);
	//va_arg(args, /*type: ie double*/);
	char str[2];
	str[1] = 0;
	char c = buf[0];
	char i = 0;
	while ( c != 0 )
	{
		switch ( c )
		{
			// Handle the control code
			case CC:
				switch( buf[i + 1] )
				{
					case STR:
						break;
					case NUM:
						printI(va_arg(args, int));
						break;
					case FLT:
						printF(va_arg(args, double));
						break;
					case CHR:
						break;
					default:
						break;
				}
				// Increment i to skip the next character as well, because
				// it was part of the control code
				i++;
				break;
			// Simply print the character
			default:
				str[0] = c;
				fputs_cr(str);
				break;
		}
		i++;
		c = buf[i];
	}
	va_end(args);
	// End of format string
	return;
}


void printI(int num)
{
	char zeroTrip = '1';
	int divisor;
	char str[2];
	str[1] = 0;
	char mod;
	// First print a negative sign if needed
	if ( num < 0 )
	{
		str[0] = '-';
		fputs_cr(str);
		num *= -1;
	}
	if (sizeof(int) == 4)
	{
		// Max val of int is 2147483647
		divisor = 1000000000;
	}
	else if (sizeof(int) == 2)
	{
	}
	else if (sizeof(int) == 8)
	{
	}
	// Using decreasing divisors, divide the num by the divisor, where the
	// quotient must be the digit to print. Ignore leading zeros. The remainder
	// of each operation is the number without its most significant digit,
	// meaning we can iteratively print each digit in the number from left to
	// right
	for ( ; divisor >= 1; divisor /= 10)
	{
		mod = num / divisor;
		num %= divisor;
		if ( mod == 0 )
		{
			if ( zeroTrip != '1' )
			{
				str[0] = mod + '0';
				fputs_cr(str);
			}
		}
		else
		{
			zeroTrip = '0';
			str[0] = mod + '0';
			fputs_cr(str);
		}
	}
	return;
}




void printF(double num)
{
	float fVal = (float)num;
	unsigned int intRep = fltBitsToInt(fVal);
	printf("\nINTEGER BITS OF FLOAT:%d\n",intRep);
	char str[2];
	str[1] = 0;
	unsigned int sign = intRep >> 31;
	printf("Sign:%u\n",sign);
	unsigned int mantissa = ( intRep << 1 ) >> 24;
	printf("Mantissa:Octal:%o\nMantissa:Dec:%u\n",mantissa);
	unsigned int floating = ( ( intRep << 9 ) >> 9 ) | 0b100000000000000000000000;
	printf("Float:%u\n",floating);
	if ( sign != 0 )
	{
		str[0] = '-';
		fputs_cr(str);
	}
	unsigned int exponent = mantissa - 127;
	printf("Exponent:%d\n",exponent);
	int integerComponent = (floating >> (23 - exponent));
	printf("Integer component:%d\n",integerComponent);
	printI(integerComponent);
	// Print the decimal point
	str[0] = '.';
	fputs_cr(str);
	return;
}
