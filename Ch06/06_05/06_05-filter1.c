#include <stdio.h>

int main()
{
	int ch;

	/* read standard input until the EOF */
	while( (ch = fgetc(stdin)) != EOF )
	{
		fputc(ch,stdout);	/* send to standard output */
	}

	return 0;
}
