#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
	int data;
	int deep;
	struct Node *left;
	struct Node *right;
};
typedef struct Node bst,*bs;
bs root=NULL;

int n,item;
int depth;

bs insert(bs p,int item,int dep)
{
	bs hold;
	dep++;
	if(p==NULL)
	{
		p=(bs)malloc(sizeof(bs));
		p->data=item;
		p->left=NULL;
		p->right=NULL;
		p->deep=dep;
	}
	else if(item>=p->data)
	{
		p->left=insert(p->left,item,dep);	
	}
	else if(item<p->data)
	{
		p->right=insert(p->right,item,dep);	
	}
	return p;
}
void printff(bs root)
{
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
			printf("%d %d\n",root->data,root->deep);
		printff(root->right);
		printff(root->left);
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		depth=0;
		scanf("%d",&item);
		root=insert(root,item,depth);
	}
	printff(root);
	return 0;
}
/*50
38
30
64
58
40
10
73
70
50
60
100
35
*/



