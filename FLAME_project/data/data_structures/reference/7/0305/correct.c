#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define MAX 1024
struct list{
	int data;
	int depth;
	struct list *let,*rit;
};
typedef struct list Tree;
Tree *head;
Tree* set(Tree *root,int data0,int depth0)
{
	depth0++;
	if(root==NULL)
	{
		root=(Tree*)malloc(sizeof(Tree));
		root->data=data0;
		root->depth=depth0;
		root->let=root->rit=NULL;
		head=root;
	}
	else if(data0<root->data)
		root->let=set(root->let,data0,depth0);
	else if(data0>=root->data)
		root->rit=set(root->rit,data0,depth0);
	return root;
}

void putTree(Tree *root)
{
	if(root)
	{
		if((root->let==NULL)&&(root->rit==NULL))
		{
			printf("%d %d\n",root->data,root->depth);
		}
		putTree(root->let);
		putTree(root->rit);
	}
}
int main()
{
	Tree *root=NULL;
	int n,i,dak;
	int depk;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&dak);
		depk=0;
		root=set(root,dak,depk);
	}
	putTree(root);
	return 0;
}
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35

