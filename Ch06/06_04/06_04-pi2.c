#include <stdio.h>
#include <math.h>

int main()
{
	int x;

	for(x=1;x<=10;x++)
		printf("%.*f\n",x,M_PI);

	return 0;
}
