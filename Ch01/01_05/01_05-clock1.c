#include <stdio.h>
#include <time.h>

int main()
{
	clock_t ticks;

	ticks = clock();
	printf("The clock() function returned %ld\n",ticks);

	return 0;
}
