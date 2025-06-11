#include <stdio.h>

/* prototype the assembly function */
int stringlength(char *);

int main()
{
	char sample[] = "Hello, Assembly!";
	int len;

	/* obtain the string length */
	len = stringlength(sample);
	printf("The string \"%s\" is %d characters long\n",sample,len);

	return 0;
}
