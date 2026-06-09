#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	int z;
	struct node *left, *right;
};
int depth;
typedef struct node Node,*Nodeptr;
Nodeptr insert(Nodeptr p, int n);
void inorder(Nodeptr t);
int main()
{
	int all, i, n;
	scanf("%d", &all);
	Nodeptr root = NULL;
	for(i=0; i<all; i++)
	{
		depth = 0;
		scanf("%d", &n);
		root = insert(root,n);
	}
	inorder(root);
	return 0;
}
Nodeptr insert(Nodeptr p, int n)
{
	depth++;
    if(p == NULL)
    {
    	p=(Nodeptr)malloc(sizeof(Node));
    	p->data = n;
    	p->z = depth;
    	p->left = p->right =NULL;
	}
	else if(n >= p->data)
		p->right = insert(p->right, n);
	else if(n < p->data)
		p->left = insert(p->left, n);
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

