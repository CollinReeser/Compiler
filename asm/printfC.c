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
extern void putchar_cr(char x);
extern int fltBitsToInt(float num);
void printI(int num);
void printF(double num);


// Dammit. Well. I guess I can do this in C then, jerks.
void printf_cr(char* buf , ...)
{
	va_list args;
	va_start(args, buf);
	//va_arg(args, /*type: ie double*/);
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
				putchar_cr(c);
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
	char mod;
	// First print a negative sign if needed
	if ( num < 0 )
	{
		putchar_cr('-');
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
				putchar_cr(mod + '0');
			}
		}
		else
		{
			zeroTrip = '0';
			putchar_cr(mod + '0');
		}
	}
	return;
}




void printF(double num)
{
	float fVal = (float)num;
	//printf("%f << Original value\n",fVal);
	unsigned int intRep = fltBitsToInt(fVal);
	//printf("\nINTEGER BITS OF FLOAT:%d\n",intRep);
	unsigned int sign = intRep >> 31;
	//printf("Sign:%u\n",sign);
	unsigned int mantissa = ( intRep << 1 ) >> 24;
	//printf("Mantissa:Octal:%o\nMantissa:Dec:%u\n",mantissa);
	unsigned int floating = ( ( intRep << 9 ) >> 9 ) | 0b100000000000000000000000;
	//printf("Float:%u\n",floating);
	if ( sign != 0 )
	{
		putchar_cr('-');
	}
	unsigned int exponent = mantissa - 127;
	//printf("Exponent:%d\n",exponent);
	int integerComponent = (floating >> (23 - exponent));
	unsigned int floatComponent = floating << ( 9 + exponent );
	//printf("Integer component:%d\n",integerComponent);
	//printf("Float component:%o\n",floatComponent);
	printI(integerComponent);
	// Print the decimal point
	putchar_cr('.');
	unsigned int total = 0;
	int divvy = 500000000;
	unsigned int mask = 0b10000000000000000000000000000000;
	//printf("\nMask:%o\n",mask);
	int i;
	for ( i = 0; i < 23; i++ )
	{
		if ( ( ( mask >> i ) & floatComponent ) != 0 )
		{
			total += divvy;
		}
		divvy = divvy / 2;
	}
	//printf("Total: %u\n",total);
	char floatSec[10];
	floatSec[9] = 0;
	
	
	int divisor = 100000000;
	int mod;
	for ( i = 0; divisor >= 1; divisor /= 10, i++ )
	{
		mod = total / divisor;
		total %= divisor;
		floatSec[i] = mod + '0';
	}
	//printf("floatSec: %s\n",floatSec);
	char promote = 0;
	// Rounding algorithm
	for ( i = 9; i > 5; i-- )
	{
		promote = 0;
		if ( floatSec[i] > '4' )
		{
			promote = 1;
		}
		if ( promote == 1 )
		{
			floatSec[i-1] += 1;
		}
		floatSec[i] = 0;
	}
	//printf("floatSec: %s\n",floatSec);
	fputs_cr(floatSec);
	return;
}
