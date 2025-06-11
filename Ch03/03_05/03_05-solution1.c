#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

/* push values onto the stack */
void push(int *b,int **s, char v)
{
	/* use the first storage spot on the stack */
	if( *s>b+STACK_SIZE )
	{
		puts("Stack overflow");
	}
	else
	{
		**s = v;		/* add the value to the stack */
		(*s)++;
	}
}

/* pop values from the stack */
void pop(int *b,int **s,char *v)
{
	if( *s<b )
	{
		puts("Stack empty");
		v = NULL;
	}
	else
	{
		(*s)--;
		*v = **s;
	}
}

int main()
{
	int *base,*sp,count;
	char ch;

	/* initialize */
	base = malloc( sizeof(char) * STACK_SIZE );
	if( base==NULL )
	{
		fprintf(stderr,"Unable to initialize the stack\n");
		exit(1);
	}
	sp = base;
	count = 0;		/* charater input counter */
	puts("Stack ready");

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
			while( sp>base )
			{
				pop(base,&sp,&ch);
				putchar(ch);
			}
			putchar('\n');
			break;
		}
		push(base,&sp,ch);		/* add the character to the stack */

		/* track input */
		count++;
	}

	/* clean-up */
	free(base);
	return 0;
}
