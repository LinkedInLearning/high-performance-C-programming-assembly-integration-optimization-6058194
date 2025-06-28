#include <stdio.h>

#define save_cursor() printf("\e7")
#define restore_cursor() printf("\e8\e[0J")

int main()
{
	const int size = 24;
	char buffer[size];

	printf("Command: ");
	do
	{
		save_cursor();
		fgets(buffer,size,stdin);
		restore_cursor();
	}
	while( buffer[0] != 'Q' );
	putchar('\n');

	return 0;
}
