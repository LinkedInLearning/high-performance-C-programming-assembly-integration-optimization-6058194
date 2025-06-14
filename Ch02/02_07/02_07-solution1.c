#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
	float price;
	char *name;
};

int compare(const void *a, const void *b)
{
	char *name1 = ((struct item *)a)->name;
	char *name2 = ((struct item *)b)->name;
	return( strcmp(name1,name2) );
}

int main()
{
	struct item inventory[] = {
		{ 12.79, "Pickles" },
		{ 3.45, "Eggs" },
		{ 7.50, "Chocolate" },
		{ 2.20, "Onions" },
		{ 5.99, "Cheese" },
		{ 10.20, "Coffee" },
		{ 2.23, "Flour" },
		{ 1.25, "Garlic" },
		{ 1.99, "Tomatoes" },
		{ 4.00, "Potatoes" }
	};
	struct item *r,*key;
	char input[32];
	int size,x;

	/* calculate array size (structure) */
	size = sizeof(inventory)/sizeof(struct item);

	/* sort the inventory */
	qsort( inventory, size, sizeof(struct item), compare );

	/* output the list */
	puts("Inventory:");
	for( x=0; x<size; x++ )
		printf("%2d: %s\n",x+1,inventory[x].name);

	/* prompt for key value */
	printf("Look up price for: ");
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
	key = malloc( sizeof(struct item) );
	key->name = malloc( sizeof(char) * 32 );
	if( key==NULL || key->name==NULL )
	{
		fprintf(stderr,"Unable to allocate memory\n");
		exit(1);
	}
	strcpy(key->name,input);

	/* search for the string */
	r = bsearch( key, inventory, size, sizeof(struct item), compare);
	if( r!=NULL)
		printf("%s cost $%.2f\n",key->name,r->price);
	else
		printf("%s is unavailable\n",key->name);

	/* clean-up */
	free(key->name);
	free(key);
	return 0;
}
