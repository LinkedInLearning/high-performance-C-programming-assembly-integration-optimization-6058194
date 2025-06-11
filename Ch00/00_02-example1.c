#include <stdio.h>

int main()
{
	int x = 0xA;
	long a = 0x21868166FD9B32C8L;

	while(x--)
	{
		putchar(a & 0x7F);
		a>>=7;
	}

	return 0;
}
