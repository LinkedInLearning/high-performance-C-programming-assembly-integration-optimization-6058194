#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return( strcmp(*(const char **)a,*(const char **)b) );
}

int main()
{
	char *v[] = {
		"cantalope", "grapefruit", "fig", "melon",
		"banana", "apple", "kiwi", "lemon"
	};
	char key[32];
	char **r;
	int size,x;

	/* calculate array size (pointers) */
	size = sizeof(v)/sizeof(char *);

	/* prompt for the key value */
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

	/* sort the array */
	qsort( v, size, sizeof(char *), compare );

	/* search for the string */
	r = bsearch( key, v, size, sizeof(char *), compare );
	if( r!=NULL )
		printf("String '%s' found!\n",key);
	else
		printf("String '%s' not found.\n",key);

	return 0;
}
