#include <stdio.h>

int main()
{
	printf("char is %zu bits\n",sizeof(char)*8);
	printf("short is %zu bits\n",sizeof(short)*8);
	printf("int is %zu bits\n",sizeof(int)*8);
	printf("long is %zu bits\n",sizeof(long)*8);
	printf("long long is %zu bits\n",sizeof(long long)*8);

	return 0;
}
