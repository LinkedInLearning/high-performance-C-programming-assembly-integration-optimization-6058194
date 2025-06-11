#include <stdio.h>
#include <stdarg.h>

/* function with a variable argument list */
void list(int a, ... )
{
	va_list arg_list;		/* variable argument list variable */
	int x;

	/* begin processing */
	va_start(arg_list,a);		/* initialize the list */
	printf("Passed:");
	for(x=0;x<a;x++)			/* a is the item count */
	{
		/* fetch integer values */
		printf(" %2d",va_arg(arg_list,int) );
	}
	putchar('\n');

	/* clean up */
	va_end(arg_list);
}

int main()
{
	/* process variable length arguments */
	list( 5, 1, 2, 3, 4, 5 );
	list( 3, 40, 60, 10 );
	list( 0 );

	return 0;
}
