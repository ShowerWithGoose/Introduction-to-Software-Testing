#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree* left;
	struct tree* right;
};
struct tree* head;
struct tree* creat_tree(struct tree* p,int data)
{
	if(p==NULL)
	{
		struct tree* q=(struct tree*)malloc(sizeof(struct tree));
		q->data=data;
		q->left=q->right=NULL;
		return q;
	}else 
	{
		if(p->data>data)
		{
			p->left=creat_tree(p->left,data);
		}else{
			p->right=creat_tree(p->right,data);
		}
	}
	
	return p; 
}

void dfs(struct tree* p,int level)
{
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->data,level);
	}
	
		if(p->left!=NULL)
		{
			dfs(p->left,level+1);
		}
		if(p->right!=NULL)
		{
			dfs(p->right,level+1);
		}
	
}
int main()
{
	int n,i,k;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&k);
		head=creat_tree(head,k);
	}
	dfs(head,1);
	return 0;
 } 



