#include <stdio.h>

int main()
{
	const int size = 24;
	char buffer[size];

	do
	{
		printf("Command: ");
		fgets(buffer,size,stdin);
	}
	while( buffer[0] != 'Q' );
	putchar('\n');

	return 0;
}
