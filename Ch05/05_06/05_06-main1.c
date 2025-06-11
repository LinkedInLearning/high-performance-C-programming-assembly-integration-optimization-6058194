/* this code calls an assembly language function
   built and linked as a separate module */
#include <stdio.h>

/* must prototype the assembly function */
int safe_input(char *buffer, unsigned length );

int main()
{
	char buffer[32];
	int r;

	printf("Your name:\n");
	r = safe_input(buffer,32);		/* assembly language function */
	printf("Pleased to meet you, %s!\n",buffer);
	printf("(%d characters input)\n",r);

	return 0;
}
