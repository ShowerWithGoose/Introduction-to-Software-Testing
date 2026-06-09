#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define ll long long
typedef struct tree *nodeptr;
typedef struct tree node;
struct tree {
	int node;
	node *left;
	node *right;
};
nodeptr creat(int t)
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(node));
	p->node=t;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void insert(int t,nodeptr p)
{
	if(t<p->node){
		if(p->left==NULL){
			p->left=creat(t);
		}
		else{
			insert(t,p->left);
		}
	}
	else{
		if(p->right==NULL){
			p->right=creat(t);
		}
		else{
			insert(t,p->right);
		}
	}
}
void visit(nodeptr p,int f)
{
	if(p->left==NULL&&p->right==NULL) 
	{
		printf("%d %d\n",p->node,f);
	}
	else {
			f++; 
		if(p->left!=NULL) visit(p->left,f);
		if(p->right!=NULL) visit(p->right,f);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	nodeptr root;
	root=(nodeptr)malloc(sizeof(node));
	int t;
	scanf("%d",&t);
	root->node=t;
	root->left=NULL;
	root->right=NULL;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&t);
		insert(t,root);
	}
	int f=1;
	visit(root,f);
	return 0;
}


