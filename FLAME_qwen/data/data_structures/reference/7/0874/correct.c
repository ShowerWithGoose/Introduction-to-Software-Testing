#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node
{
	int data;
	int rchild,lchild;
}tree[100005];
int n,root=1;
void insert_tree(int x,int y)
{
	if(y==root)return;
	if(tree[x].data<=tree[y].data)
	{
		if(tree[x].rchild==-1){tree[x].rchild=y;return;}
		else insert_tree(tree[x].rchild,y);
	}
	else if(tree[x].data>tree[y].data)
	{
		if(tree[x].lchild==-1){tree[x].lchild=y;return;}
		else insert_tree(tree[x].lchild,y);
	}
}
void dfs(int x,int depth)
{
	if(tree[x].rchild==-1&&tree[x].lchild==-1)
	{
		printf("%d %d\n",tree[x].data,depth);return;
	}
	if(tree[x].lchild!=-1)dfs(tree[x].lchild,depth+1); 
	if(tree[x].rchild!=-1)dfs(tree[x].rchild,depth+1);
} 
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		tree[i].lchild=tree[i].rchild=-1;
		scanf("%d",&tree[i].data);
		insert_tree(root,i);
	}
//	for(i=1;i<=n;i++)printf("%d %d %d\n",i,tree[i].lchild,tree[i].rchild);
	dfs(root,1);
	return 0;
}
/*
15
9 2 3 4 5 6 7 8 1 10 11 12 13 14 15 
*/

