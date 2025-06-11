#include <stdio.h>

int main()
{
#ifdef _WIN64
	puts("Welcome to Windows");
#elif __linux__
	puts("Welcome to Linux");
#elif __APPLE__
	puts("Welcome to some Apple device");	
#else
	puts("System undefined");
#endif

	return 0;
}
