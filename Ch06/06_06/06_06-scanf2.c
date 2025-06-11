#include <stdio.h>

int main()
{
	char input[32];

	printf("Type: ");
	scanf("%[$1234567890.,]",input);
	printf("You typed: %s\n",input);

	return 0;
}
