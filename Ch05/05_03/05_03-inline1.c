#include <stdio.h>

long total;

int main()
{
	int x;

	total = 1;
	for( x=0; x<10; x++ )
	{
		printf("%ld\n",total);
		asm(
				".intel_syntax noprefix;"
				"mov rax, total;"
				"imul rax, 2;"
				"mov total,rax;"
		   );
	}

	return 0;
}
