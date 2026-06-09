#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct treeNode
{
	int data;
	int deep;
	struct treeNode *lc;
	struct treeNode *rc;	
}tree,*LPtree; 

LPtree createNode(int data)
{
	LPtree newNode = (LPtree)malloc(sizeof(tree));
	newNode -> lc = NULL;
	newNode -> rc = NULL;
	newNode -> data = data;
	newNode -> deep = 1;
	return newNode;
}

void insert(LPtree root,LPtree a)
{
	if(a -> data < root -> data)
	{
		if(root -> lc == NULL)
		{
			root -> lc = a;
			a -> deep++;
		}
		else
		{
			a -> deep++;
			insert(root -> lc,a);	
		}
	}
	else
	{
		if(root -> rc == NULL)
		{
			root -> rc = a;
			a -> deep++;
		}
		else
		{
			a -> deep++;
			insert(root -> rc,a);	
		}
	} 
}

int ifPrint(LPtree node)
{
	if(node -> lc == NULL && node -> rc == NULL)
	return 1;
	else 
	return 0;
}


void p(LPtree root)
{
	if(root!=NULL)
	{
	printf("%d\n",root->data);
	p(root->lc);
	p(root->rc);
	}
	
}
void printTree(LPtree root)
{
	if(root!=NULL)
	{
	if(ifPrint(root)==1)
	{
		printf("%d %d\n",root->data,root->deep);
	}
	printTree(root -> lc);
	printTree(root -> rc);
	}
}

int main()
{
	int n,i,t[1000];
	LPtree a[1000];
	LPtree root;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&t[i]);
	for(i=1;i<=n;i++)
	a[i]=createNode(t[i]);
	for(i=2;i<=n;i++)
	{
		insert(a[1],a[i]);
	} 

	printTree(a[1]);

}



