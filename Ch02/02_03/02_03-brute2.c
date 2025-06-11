#include <stdio.h>
#include <string.h>

int main()
{
	char *v[] = {
		"cantalope", "grapefruit", "fig", "melon",
		"banana", "apple", "kiwi", "lemon"
	};
	char key[32];
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

	/* search for the string */
	for( x=0; x<size; x++ )
	{
		if( strcmp(key,v[x])==0 )
		{
			printf("String '%s' found!\n",key);
			return 0;		/* exit upon success */
		}
	}
	/* string not found */
	printf("String '%s' not found.\n",key);

	return 0;
}
