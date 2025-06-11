#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;

	/* read standard input until the EOF */
	while( (ch = fgetc(stdin)) != EOF )
	{
		/* affect only alphabet characters */
		if( isalpha(ch) )
		{
			if( toupper(ch)>='A' && toupper(ch)<='M' )
				ch += 13;	/* shift A-M to O-Z */
			else
				ch -= 13;	/* shift O-Z to A-M */
		}
		fputc(ch,stdout);	/* send to standard output */
	}

	return 0;
}
