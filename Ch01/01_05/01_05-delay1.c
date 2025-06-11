#include <stdio.h>
#include <time.h>

void delay(int milliseconds)
{
	long pause;
	clock_t now,then;

	pause = milliseconds*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while( now-then < pause )
		now = clock();
}

int main()
{
	int x;

	for( x=1; x<11; x++ )
	{
		printf("%d\n",x);
		delay(250);
	}

	return 0;
}
