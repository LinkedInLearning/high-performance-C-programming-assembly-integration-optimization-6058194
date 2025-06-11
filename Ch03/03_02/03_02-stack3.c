#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

int main()
{
	int *base,*sp,value;

	/* initialize */
	base = malloc( sizeof(int) * STACK_SIZE );
	if( base==NULL )
	{
		fprintf(stderr,"Unable to initialize the stack\n");
		exit(1);
	}
	sp = base;			/* stack pointer */
	puts("Stack ready");

	/* push values onto the stack */
	while( sp<base+STACK_SIZE )
	{
		printf("Enter a value, 0 to stop: ");
		scanf("%d",&value);
		if( value==0 )
			break;
		*sp = value;	/* add the value to the stack */
		sp++;
	}

	/* remove values from the stack */
	sp--;				/* skip over empty item */
	while(1)
	{
		printf("Popping %d\n",*sp);		/* fetch value */
		sp--;							/* adjust stack pointer */
		if( sp<base )
			break;
	}

	/* clean-up */
	free(base);
	return 0;
}
