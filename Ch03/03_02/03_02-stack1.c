#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

int main()
{
	int *base,*sp;

	/* initialize */
	base = malloc( sizeof(int) * STACK_SIZE );
	if( base==NULL )
	{
		fprintf(stderr,"Unable to initialize the stack\n");
		exit(1);
	}
	sp = base;		/* stack pointer */
	puts("Stack ready");

	/* clean-up */
	free(base);
	return 0;
}
