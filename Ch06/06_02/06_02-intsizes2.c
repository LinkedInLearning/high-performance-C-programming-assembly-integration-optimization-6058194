#include <stdio.h>
#include <stdint.h>

int main()
{
	printf("int8_t is %zu bits\n",sizeof(int8_t)*8);
	printf("int16_t is %zu bits\n",sizeof(int16_t)*8);
	printf("int32_t is %zu bits\n",sizeof(int32_t)*8);
	printf("int64_t is %zu bits\n",sizeof(int64_t)*8);

	return 0;
}
