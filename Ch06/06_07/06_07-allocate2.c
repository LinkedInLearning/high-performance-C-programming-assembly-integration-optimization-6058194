#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* text file included with exercise files */
	const char filename[] = "sonnet18.txt";
	const int size = 256;
	FILE *fp;
	char *buffer = NULL;
	int offset;

	/* open file */
	fp = fopen(filename,"r");
	if( fp==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		exit(1);
	}

	/* read and store file's data */
	offset = 0;
	while( !feof(fp) )
	{
		if( buffer==NULL )		/* test for first read */
		{
			/* initial allocation */
			buffer = malloc( sizeof(char) * size );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to allocate storage\n");
				exit(1);
			}
		}
		else
		{
			/* expand the buffer */
			offset+=size;
			buffer = realloc(buffer,sizeof(char) * (size+offset) );
			if( buffer==NULL )
			{
				fprintf(stderr,"Unable to expand storage\n");
				exit(1);
			}
		}
		fread(buffer+offset,size,sizeof(char),fp);
	}

	/* output file's text */
	offset = 0;
	while( putchar(*(buffer+offset)) )
		offset++;

	/* clean-up */
	fclose(fp);
	free(buffer);
	return 0;
}
