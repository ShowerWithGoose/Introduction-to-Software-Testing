#include<stdio.h>
#include<stdlib.h>
#define max 1010
typedef struct node{
	int data;
	int depth;
}Tree;
Tree tree[max];
int deep=0;
void build(int position,int item);
void inorder(int position);
int main()
{
	int i=0;
	for(i=0;i<max-1;i++)
	{
		tree[i].data=-1;
		tree[i].depth=0;
	}
	int n,item;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		deep=0;
		build(1,item);
	}
	inorder(1);
	return 0;
}
void build(int position,int item)
{
	deep++;
	if(tree[position].data==-1)
	{
		tree[position].data=item;
		tree[position].depth=deep;
	}
	else if(item<tree[position].data)
	{
		build(2*position,item);
	}
	else if(item>=tree[position].data)
	build(2*position+1,item);
}
void inorder(int position)
{
	if(tree[position].data!=-1){
		inorder(2*position);
	    if(tree[2*position].data==-1&&tree[2*position+1].data==-1)
	    {
	    	printf("%d %d\n",tree[position].data,tree[position].depth);
		}
	inorder(2*position+1);
	}
}

