#include <stdio.h>
#include <time.h>

int main()
{
	clock_t ticks1,ticks2;

	ticks1 = clock();
	printf("The clock() function returned %ld\n",ticks1);
	ticks2 = clock();
	printf("The clock() function returned %ld\n",ticks2);
	printf("%f seconds have elapsed\n",
			(float)(ticks2-ticks1)/CLOCKS_PER_SEC
		  );

	return 0;
}
