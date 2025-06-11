#include <stdio.h>

int isvowel(int c)
{
	if( c=='A' || c=='a' )
		return 1;
	if( c=='E' || c=='e' )
		return 1;
	if( c=='I' || c=='i' )
		return 1;
	if( c=='O' || c=='o' )
		return 1;
	if( c=='U' || c=='u' )
		return 1;

	return 0;
}

int main()
{
	int ch;

	/* read standard input until the EOF */
	while( (ch = fgetc(stdin)) != EOF )
	{
		if( isvowel(ch) )
			fputc('*',stdout);
		else
			fputc(ch,stdout);	/* send to standard output */
	}

	return 0;
}
