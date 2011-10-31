
#define CC '%'
#define STR 's'
#define NUM 'd'
#define FLT 'f'
#define CHR 'c'

extern fputs_cr(char* str);

// Dammit. Well. I guess I can do this in C then, jerks.
void printf_cr(char* buf , ...)
{
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
				}
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
	// End of format string
	return;
}
