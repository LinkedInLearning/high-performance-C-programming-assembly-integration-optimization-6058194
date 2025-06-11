#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256
int *base,*sp;

/* push values onto the stack */
void push(int v)
{
	/* use the first storage spot on the stack */
	if( sp>base+STACK_SIZE )
	{
		puts("Stack overflow");
	}
	else
	{
		*sp = v;		/* add the value to the stack */
		sp++;
	}
}

/* pop values from the stack */
void pop(int *v)
{
	if( sp<base )
	{
		puts("Stack empty");
		v = NULL;
	}
	else
	{
		sp--;
		*v = *sp;
	}
}

int main()
{
	int value;

	/* initialize */
	base = malloc( sizeof(int) * STACK_SIZE );
	if( base==NULL )
	{
		fprintf(stderr,"Unable to initialize the stack\n");
		exit(1);
	}
	sp = base;
	puts("Stack ready");

	while(1)
	{
		printf("Enter a value, 0 to stop: ");
		scanf("%d",&value);
		if( value==0 )
			break;
		push(value);
	}

	/* remove values from the stack */
	while(sp > base )
	{
		pop(&value);		/* fetch value */
		printf("Popping %d\n",value);
	}

	/* clean-up */
	free(base);
	return 0;
}
