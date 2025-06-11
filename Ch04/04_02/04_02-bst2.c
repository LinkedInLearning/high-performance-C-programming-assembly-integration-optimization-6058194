#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

/* add a node */
struct node *add_node(struct node *r, int k)
{
	if( r==NULL )
	{
		r = malloc( sizeof(struct node) );
		if( r==NULL )
		{
			fprintf(stderr,"Unable to allocate memory\n");
			exit(1);
		}
		r->key = k;
		r->right = NULL;
		r->left = NULL;
	}
	else
	{
		/* smaller values go on the left */
		if( k < r->key )
			r->left = add_node(r->left,k);
		/* larger values go on the right */
		else
			r->right = add_node(r->right,k);
	}
	return(r);
}

int main()
{
	int data[] = {
		44, 28, 96, 10, 74, 33, 58,
		14, 37, 2, 50, 35, 72, 77, 54
	};
	int count,x;
	struct node *root = NULL;

	/* count elements in data[] */
	count = sizeof(data)/sizeof(data[0]);

	for( x=0; x<count; x++ )
	{
		root = add_node(root,data[x]);
		printf("Added %d\n",data[x]);
	}

	return 0;
}
