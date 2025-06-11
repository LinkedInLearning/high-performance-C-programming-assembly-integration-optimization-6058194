#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256
int *base;

/* push values onto the stack */
void push(int *s, int v)
{
	/* use the first storage spot on the stack */
	if( s>base+STACK_SIZE )
	{
		puts("Stack overflow");
	}
	else
	{
		*s = v;		/* add the value to the stack */
		s++;
	}
}

/* pop values from the stack */
void pop(int *s,int *v)
{
	if( s<base )
	{
		puts("Stack empty");
		v = NULL;
	}
	else
	{
		s--;
		*v = *s;
	}
}

int main()
{
	int *sp,value;

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
		push(sp,value);
	}

	/* remove values from the stack */
	while(sp > base )
	{
		pop(sp,&value);		/* fetch value */
		printf("Popping %d\n",value);
	}

	/* clean-up */
	free(base);
	return 0;
}
