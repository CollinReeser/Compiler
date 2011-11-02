#include <stdarg.h>

// FOR TESTING PURPOSES
#include <stdio.h>


#define CC '%'
#define STR 's'
#define NUM 'd'
#define FLT 'f'
#define CHR 'c'
#define DUB 'b'

// Need defines for flags that go along with the different command directives,
// and to implement a parsing system

extern void fputs_cr(char* str);
extern void putchar_cr(char x);
extern int fltBitsToInt(float num);
void printI(int num);
void printF(double num);
void printDbl(double num);


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
					case DUB:
						printDbl(va_arg(args, double));
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

void printL(long long num)
{
	char zeroTrip = '1';
	long long divisor;
	char mod;
	// First print a negative sign if needed
	if ( num < 0 )
	{
		putchar_cr('-');
		num *= -1;
	}
	if (sizeof(long long) == 8)
	{
		// Max val of int is 2147483647
		divisor = 1000000000000000000;
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
	char floatSec[10];
	floatSec[9] = 0;
	float fVal = (float)num;
	//printf("%f << Original value\n",fVal);
	unsigned int intRep = fltBitsToInt(fVal);
	//printf("\nINTEGER BITS OF FLOAT:%d\n",intRep);
	unsigned int sign = intRep >> 31;
	//printf("Sign:%u\n",sign);
	unsigned int mantissa = ( intRep << 1 ) >> 24;
	//printf("Mantissa:Octal:%o\nMantissa:Dec:%u\n",mantissa,mantissa);
	unsigned int floating = ( ( intRep << 9 ) >> 9 );// | 0b100000000000000000000000;
	//printf("Float:%u\n",floating);
	//printf("Float:%o\n",floating);
	if ( sign != 0 )
	{
		putchar_cr('-');
	}
	// 0 condition
	if ( floating == 0 && mantissa == 0 )
	{
		floatSec[0] = '0';
		floatSec[1] = '.';
		floatSec[2] = '0';
		floatSec[3] = '0';
		floatSec[4] = '0';
		floatSec[5] = '0';
		floatSec[6] = '0';
		floatSec[7] = '0';
		floatSec[8] = 0;
		fputs_cr(floatSec);
		return;
	}
	// Infinite, and NaN
	if ( mantissa == 0b11111111 )
	{
		// Infinite
		if ( floating == 0 )
		{
			floatSec[0] = 'i';
			floatSec[1] = 'n';
			floatSec[2] = 'f';
			floatSec[3] = 'i';
			floatSec[4] = 'n';
			floatSec[5] = 'i';
			floatSec[6] = 't';
			floatSec[7] = 'e';
			floatSec[8] = 0;
			fputs_cr(floatSec);
			return;
		}
		// NaN, for undefined operations or uninitialized values
		else
		{
			floatSec[0] = 'N';
			floatSec[1] = 'a';
			floatSec[2] = 'N';
			floatSec[3] = 0;
			fputs_cr(floatSec);
			return;
		}
	}
	floating |= 0b100000000000000000000000;
	//floating |= 0b000000000000000000000000;
	int exponent = mantissa - 127;
	printf("Floating: %u\n",floating);
	printf("Exponent: %d\n",exponent);
	int integerComponent;
	unsigned int floatComponent;
	if ( exponent < 24 )
	{
		integerComponent = (floating >> (23 - exponent));
		floatComponent = ( floating << ( 9 + exponent ) );
	}
	else if ( exponent > 23  && exponent < 32)
	{
		integerComponent = (floating << (exponent - 23));
		floatComponent = ( floating << ( 9 + exponent ) );
	}
	printf("Integer component: %d\n",integerComponent);
	printf("Float component: %u\n",floatComponent);
	(integerComponent) ? printI(integerComponent) : putchar_cr('0');
	//printf("Float component:%o\n",floatComponent);
	//printI(integerComponent);
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
	for ( i = 5; i > -1; i-- )
	{
		if ( floatSec[i] == ':')
		{
			floatSec[i] = '0';
			floatSec[i-1] += 1; 
		}
	}
	//printf("floatSec: %s\n",floatSec);
	fputs_cr(floatSec);
	return;
}

union convertU
{
	double first;
	long long second;
} convert;

void printDbl(double num)
{
	char floatSec[10];
	floatSec[9] = 0;
	double fVal = num;
	//printf("%f << Original value\n",fVal);
	convert.first = fVal;
	unsigned long long intRep = convert.second;
	//printf("\nINTEGER BITS OF FLOAT:%d\n",intRep);
	unsigned long long sign = intRep >> 63;
	//printf("Sign:%u\n",sign);
	unsigned long long mantissa = ( intRep << 1 ) >> 53;
	//printf("Mantissa:Octal:%o\nMantissa:Dec:%u\n",mantissa,mantissa);
	unsigned long long floating = ( ( intRep << 12 ) >> 12 );// | 0b100000000000000000000000;
	//printf("Float:%u\n",floating);
	//printf("Float:%o\n",floating);
	if ( sign != 0 )
	{
		putchar_cr('-');
	}
	// 0 condition
	if ( floating == 0 && mantissa == 0 )
	{
		floatSec[0] = '0';
		floatSec[1] = '.';
		floatSec[2] = '0';
		floatSec[3] = '0';
		floatSec[4] = '0';
		floatSec[5] = '0';
		floatSec[6] = '0';
		floatSec[7] = '0';
		floatSec[8] = 0;
		fputs_cr(floatSec);
		return;
	}
	// Infinite, and NaN
	if ( mantissa == 0b11111111 )
	{
		// Infinite
		if ( floating == 0 )
		{
			floatSec[0] = 'i';
			floatSec[1] = 'n';
			floatSec[2] = 'f';
			floatSec[3] = 'i';
			floatSec[4] = 'n';
			floatSec[5] = 'i';
			floatSec[6] = 't';
			floatSec[7] = 'e';
			floatSec[8] = 0;
			fputs_cr(floatSec);
			return;
		}
		// NaN, for undefined operations or uninitialized values
		else
		{
			floatSec[0] = 'N';
			floatSec[1] = 'a';
			floatSec[2] = 'N';
			floatSec[3] = 0;
			fputs_cr(floatSec);
			return;
		}
	}
	floating |= 0b10000000000000000000000000000000000000000000000000000;
	//floating |= 0b000000000000000000000000;
	long long exponent = mantissa - 1023;
	printf("Floating: %llu\n",floating);
	printf("Exponent: %lld\n",exponent);
	unsigned long long integerComponent;
	unsigned long long floatComponent;
	if ( exponent < 53 )
	{
		integerComponent = (floating >> (52 - exponent));
		floatComponent = ( floating << ( 12 + exponent ) );
		printf("<Integer component: %lld\n",integerComponent);
		printf("<Float component: %llu\n",floatComponent);
	}
	else if ( exponent > 52  && exponent < 64)
	{
		integerComponent = (floating << (exponent - 52));
		floatComponent = ( floating << ( 12 + exponent ) );
		printf("><Integer component: %llu\n",integerComponent);
		printf("><Float component: %llu\n",floatComponent);
	}
	else if ( exponent > 62 )
	{
		printf(">Integer component: %lld\n",integerComponent);
		printf(">Float component: %llu\n",floatComponent);
	}
	(integerComponent) ? printL(integerComponent) : putchar_cr('0');
	//printf("Float component:%o\n",floatComponent);
	//printI(integerComponent);
	// Print the decimal point
	putchar_cr('.');
	unsigned long long total = 0;
	long long divvy = 5000000000000000000;
	unsigned long long mask = 0b1000000000000000000000000000000000000000000000000000000000000000;
	//printf("\nMask:%o\n",mask);
	int i;
	for ( i = 0; i < 52; i++ )
	{
		if ( ( ( mask >> i ) & floatComponent ) != 0 )
		{
			total += divvy;
		}
		divvy = divvy / 2;
	}
	//printf("Total: %u\n",total);
	
	
	long long divisor = 1000000000000000000;
	long long mod;
	for ( i = 0; divisor >= 1; divisor /= 10, i++ )
	{
		mod = total / divisor;
		total %= divisor;
		floatSec[i] = mod + '0';
	}
	//printf("floatSec: %s\n",floatSec);
	char promote = 0;
	// Rounding algorithm
	for ( i = 18; i > 5; i-- )
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
	for ( i = 5; i > -1; i-- )
	{
		if ( floatSec[i] == ':')
		{
			floatSec[i] = '0';
			floatSec[i-1] += 1; 
		}
	}
	//printf("floatSec: %s\n",floatSec);
	fputs_cr(floatSec);
	return;
}
