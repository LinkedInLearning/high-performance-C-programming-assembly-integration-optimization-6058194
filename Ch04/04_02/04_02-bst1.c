#include <stdio.h>
#include <stdlib.h>

int main()
{
	int data[] = {
		44, 28, 96, 10, 74, 33, 58,
		14, 37, 2, 50, 35, 72, 77, 54
	};
	int count,x;

	/* count elements in data[] */
	count = sizeof(data)/sizeof(data[0]);

	for( x=0; x<count; x++ )
	{
		printf("Added %d\n",data[x]);
	}

	return 0;
}
