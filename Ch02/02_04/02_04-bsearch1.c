#include <stdio.h>
#include <stdlib.h>

/* compare the integer values */
int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b );
}

int main()
{
	int v[] = { 23, 25, 1, 17, 20, 14, 3, 19 };
	int size,key,*r;

	/* calculate the array size */
	size = sizeof(v)/sizeof(int);

	/* prompt for the key value */
	printf("Key value: ");
	scanf("%d",&key);

	/* sort the array */
	qsort ( v, size, sizeof(int), compare );

	/* search for the value */
	r = bsearch( &key, v, size, sizeof(int), compare );
	if( r!=NULL )
		printf("Value %d found!\n",key);
	else
		printf("Value %d isn't found.\n",key);

	return 0;
}
