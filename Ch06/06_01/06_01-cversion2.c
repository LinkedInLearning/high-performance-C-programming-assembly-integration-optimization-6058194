#include <stdio.h>

int main()
{
	if( __STDC_VERSION__ > 201100L )
		puts("You are using C11 or greater");
	else
		puts("You are using an early version of C");

	return 0;
}
