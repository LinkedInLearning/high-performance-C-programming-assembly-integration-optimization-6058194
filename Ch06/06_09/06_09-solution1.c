/* reversing filter */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	int ch,offset;

	/* read and store standard input */
	offset = 0;
	while( (ch=fgetc(stdin)) != EOF )
	{
		/* allocate buffer first time through */
		if( buffer==NULL )
		{
			/* allocate one byte */
			buffer = malloc( sizeof(char) );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to allocate buffer\n");
				exit(1);
			}
		}
		else
		{
			/* expand the buffer */
			offset++;
			buffer = realloc(buffer,sizeof(char) * (1+offset) );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to expand storage\n");
				exit(1);
			}
		}
		*(buffer+offset) = ch;
	}

	/* input saved in the buffer, dump the buffer */
	while(offset>=0)
	{
		fputc( *(buffer+offset), stdout );
		offset--;
	}

	/* clean-up */
	free(buffer);
	return 0;
}
