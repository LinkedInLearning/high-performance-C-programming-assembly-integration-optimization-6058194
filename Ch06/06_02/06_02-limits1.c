#include <stdio.h>
#include <limits.h>

int main()
{
	printf("%-19s\t%27s\n","VARIABLE","VALUE");
	printf("%19s\t%27d\n","bits in a byte",CHAR_BIT);
	printf("%19s\t%27d\n","char max",SCHAR_MAX);
	printf("%19s\t%27d\n","char min",SCHAR_MIN);
	printf("%19s\t%27d\n","unsigned char",UCHAR_MAX);
	printf("%19s\t%27d\n","short max",SHRT_MAX);
	printf("%19s\t%27d\n","short min",SHRT_MIN);
	printf("%19s\t%27d\n","unsigned short",USHRT_MAX);
	printf("%19s\t%27d\n","int max",INT_MAX);
	printf("%19s\t%27d\n","int min",INT_MIN);
	printf("%19s\t%27u\n","unsigned int",UINT_MAX);
	printf("%19s\t%27ld\n","long max",LONG_MAX);
	printf("%19s\t%27ld\n","long min",LONG_MIN);
	printf("%19s\t%27lu\n","unsigned long",ULONG_MAX);
	printf("%19s\t%27lld\n","long long max",LLONG_MAX);
	printf("%19s\t%27lld\n","long long min",LLONG_MIN);
	printf("%19s\t%27llu\n","unsigned long long",ULLONG_MAX);

	return 0;
}
