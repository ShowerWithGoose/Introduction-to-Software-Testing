#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
	int num;
	int high;
	struct tree* lchild;
	struct tree* rchild;
}trie;
trie* insert(int k,trie* p,int h)
{
	
	if(p == NULL)
	{
		p = (trie*)malloc(sizeof(trie));
		p->num=k;
		p->high= h;
		p->lchild= NULL;
		p->rchild= NULL;
	}
 
	
	else if( k<p->num )
	{
		p->lchild =insert(k,p->lchild,h+1);
	}
	else 
	{
		p->rchild =insert(k,p->rchild,h+1);
	}
	return (p);
}
void dfs(struct tree* node)
{
	if(node->lchild!=NULL) dfs(node->lchild);
	printf("%d ",node->num);
	if(node->rchild!=NULL) dfs(node->rchild); 
 } 
void bfs(struct tree* node)
{
	if(node->lchild==NULL&&node->rchild==NULL)
	{
		printf("%d %d\n",node->num,node->high);
	}
	if(node->lchild!=NULL) bfs(node->lchild);
	if(node->rchild!=NULL) bfs(node->rchild);
}
int main()
{
	int n;
	scanf("%d",&n);
	int k;
	struct tree* root=NULL;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		root=insert(k,root,1);
		
	}
	
	bfs(root);
	return 0;
}

