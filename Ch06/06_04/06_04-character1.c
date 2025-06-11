#include <stdio.h>

int main()
{
	int x;

	for( x=1; x<20; x++ )
		printf("%*c\n",x,'#');

	return 0;
}
