#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

int main()
{
	int count;
	char ch;

	/* initialize */
	count = 0;		/* charater input counter */

	/* prompt the user */
	printf("Type text. Type * to undo, ENTER to stop.\n");
	printf("Prompt: ");
	/* input loop */
	while( count<STACK_SIZE )
	{
		ch = getchar();
		if( ch=='\n' )
			break;
		if( ch=='*' )
		{
			printf("Undo: ");
			/* pop characters from the stack */
			putchar('\n');
			break;
		}
		/* add the character to the stack */

		/* track input */
		count++;
	}

	/* clean-up */
	return 0;
}
