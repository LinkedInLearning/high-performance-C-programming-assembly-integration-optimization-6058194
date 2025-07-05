#include <stdio.h>

/* prototype the assembly function */
char firstchar(char *);

int main()
{
	char sample[] = "Hello, Assembly!";
	char a;

	/* fetch the first character in the string */
	a = firstchar(sample);
	printf("The first character of \"%s\" is '%c'\n",sample,a);

	return 0;
}
