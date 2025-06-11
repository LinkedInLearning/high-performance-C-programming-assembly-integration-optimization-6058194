#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct potus {
	int index;
	char *name;
};

int compare(const void *a, const void *b)
{
	char *name1 = ((struct potus *)a)->name;
	char *name2 = ((struct potus *)b)->name;
	return( strcmp(name1,name2) );
}

int main()
{
	struct potus v[] = {
		{ 1, "Washington" }, { 2, "Adams" }, { 3, "Jefferson" },
		{ 4, "Madison" }, { 5, "Monroe" }, { 6, "Adams" }
	};
	struct potus *r,*key;
	char input[32];
	int size,x;

	/* calculate array size (structure) */
	size = sizeof(v)/sizeof(struct potus);

	/* prompt for key value */
	printf("Key value: ");
	fgets(input,32,stdin);
	/* remove newline to ensure a match */
	x=0;
	while( input[x] )
	{
		if( input[x]=='\n' )
			input[x]='\0';
		x++;
	}

	/* allocate the key structure */
	key = malloc( sizeof(struct potus) );
	key->name = malloc( sizeof(char) * 32 );
	if( key==NULL || key->name==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}
	strcpy(key->name,input);

	/* sort the list */
	qsort( v, size, sizeof(struct potus),compare);

	/* search for the string */
	r = bsearch( key, v, size, sizeof(struct potus), compare);
	if( r!=NULL)
		printf("%s is President #%d\n",key->name,r->index);
	else
		printf("%s isn't in the dataset\n",key->name);

	return 0;
}
