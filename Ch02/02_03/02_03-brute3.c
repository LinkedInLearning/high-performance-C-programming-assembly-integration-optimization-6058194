#include <stdio.h>
#include <string.h>

struct potus {
	int index;
	char *name;
};

int main()
{
	struct potus v[] = {
		{ 1, "Washington" }, { 2, "Adams" }, { 3, "Jefferson" },
		{ 4, "Madison" }, { 5, "Monroe" }, { 6, "Adams" }
	};
	char key[32];
	int size,x;

	/* calculate array size (structure) */
	size = sizeof(v)/sizeof(struct potus);

	/* prompt for key value */
	printf("Key value: ");
	fgets(key,32,stdin);
	/* remove newline to ensure a match */
	x=0;
	while( key[x] )
	{
		if( key[x]=='\n' )
			key[x]='\0';
		x++;
	}

	/* search for the string */
	for( x=0; x<size; x++ )
	{
		if( strcmp(key,v[x].name)==0 )
		{
			printf("%s is President #%d\n",key,v[x].index);
			return 0;		/* exit upon success */
		}
	}
	/* record not found */
	printf("%s isn't in the dataset\n",key);

	return 0;
}
