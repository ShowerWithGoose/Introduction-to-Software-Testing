#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	int z;
	struct node *left, *right;
};
int k;
typedef struct node Node,*Nodeptr;
Nodeptr insert(Nodeptr p, int item);
void inorder(Nodeptr t);
int main()
{
	int n, i, item;
	scanf("%d", &n);
	Nodeptr root = NULL;
	for(i=0; i<n; i++)
	{
		k = 0;
		scanf("%d", &item);
		root = insert(root,item);
	}
	inorder(root);
	return 0;
}
Nodeptr insert(Nodeptr p, int item)
{
	k++;
    if(p == NULL)
    {
    	p=(Nodeptr)malloc(sizeof(Node));
    	p->data = item;
    	p->z = k;
    	p->left = p->right =NULL;
	}
	else if(item >= p->data)
		p->right = insert(p->right, item);
	else if(item < p->data)
		p->left = insert(p->left, item);
	return p;
}
void inorder(Nodeptr t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->left == NULL &&t->right ==NULL)
		    printf("%d %d\n",t->data, t->z );
		inorder(t->right);
	}
}

