#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
int depth = 1;
struct node
{
	Datatype data, depth;
	struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item, Datatype depth)
{
	if(p == NULL)
	{
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->left = p->right = NULL;
		p->depth=depth;
	}
	else if( item < p->data)
	{
		p->left = insertBST(p->left, item, depth+1);
	}
	else if( item >= p->data)
	{
		p->right = insertBST(p->right,item, depth+1);
	}
	//else
	//	do-something; //树中存在该元素
	return p;
}

void search(BTNodeptr x)
{
	if(x != NULL)
	{
		search(x->left);
		if(x->left==NULL&&x->right==NULL)
			printf("%d %d\n",x->data,x->depth);
		search(x->right);
	}
}

int main()
{
	int i, item, n;
	BTNodeptr  root=NULL;
	scanf("%d",&n);
	for(i=0; i<n; i++)  //构造一个有n个元素的BST树
	{
		scanf("%d", &item);
		root = insertBST(root, item, depth);
	}
	search(root);

	return 0;
}


