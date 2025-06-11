#include <stdio.h>

int main()
{
	int v[] = { 23, 25, 1, 17, 20, 14, 3, 19 };
	int size,key,x;

	/* calculate the array size */
	size = sizeof(v)/sizeof(int);

	/* prompt for the key value */
	printf("Key value: ");
	scanf("%d",&key);

	/* search for the value */
	for( x=0; x<size; x++ )
	{
		if( key==v[x] )
		{
			printf("Value %d found!\n",key);
			return 0;		/* exit upon success */
		}
	}
	/* value not found */
	printf("Value %d isn't found.\n",key);

	return 0;
}
