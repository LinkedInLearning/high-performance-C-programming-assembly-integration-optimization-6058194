#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
};

/* search for a key value */
struct node *search(struct node *r, int v)
{
	/* return on NULL or success */
	if( r==NULL || r->key==v )
		return(r);
	
	/* search for values less than v */
	if( v < r->key )
		return( search( r->left,v ) );
	/* search for values greater than or equal to */
	return( search( r->right,v ) );
}

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

/* free the tree's storage */
void free_tree(struct node *r)
{
	/* stop on NULL */
	if( r==NULL )
		return;

	/* find the bottom-most node */
	free_tree(r->left);
	free_tree(r->right);
	free(r);
}

int main()
{
	int data[] = {
		44, 28, 96, 10, 74, 33, 58,
		14, 37, 2, 50, 35, 72, 77, 54
	};
	int count,x,value;
	struct node *root = NULL;
	struct node *result;

	/* count elements in data[] */
	count = sizeof(data)/sizeof(data[0]);

	/* load the bst */
	for( x=0; x<count; x++ )
		root = add_node(root,data[x]);

	/* prompt to search */
	printf("Value? ");
	scanf("%d",&value);
	result = search(root,value);
	if( result==NULL )
		printf("Value %d not found\n",value);
	else
		printf("Value %d found: %d\n",value,result->key);

	/* clean-up */
	free_tree(root);
	return 0;
}
