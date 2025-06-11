#include <stdio.h>

int main()
{
	const int height = 20;
	int row,col,stars;

	for( row=0, stars=1; row<height; row++, stars+=2 )
	{
		printf("%*c",height-row,' ');
		for( col=0; col<stars; col++ )
			putchar('*');
		putchar('\n');
	}

	return 0;
}
