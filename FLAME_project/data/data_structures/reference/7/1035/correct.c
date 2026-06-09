#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}BTNode,*BTNodeptr;
BTNodeptr insertBTree(BTNodeptr p,int item);
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
void inorder(BTNodeptr p,int k);
void destroy(BTNodeptr p);
int main()
{
	int i,n,item=0;
	BTNodeptr root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insertBTree(root,item);
	}
//	printf("%d\n",heightBTree(root));
	inorder(root,1);
	destroy(root);
	return 0;
}

BTNodeptr insertBTree(BTNodeptr p,int item)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->left=p->right=NULL;
	}
	else if(item<p->data) p->left=insertBTree(p->left,item);
	else p->right=insertBTree(p->right,item);
	return p;
}
void inorder(BTNodeptr p,int k)
{
	if(p!=NULL)
	{
		inorder(p->left,k+1);
		if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->data,k);
		inorder(p->right,k+1);  
	}
}

void destroy(BTNodeptr p)
{
	if(p!=NULL)
	{
		destroy(p->left);
		destroy(p->right);
		free(p);
		p==NULL;
	}
}

