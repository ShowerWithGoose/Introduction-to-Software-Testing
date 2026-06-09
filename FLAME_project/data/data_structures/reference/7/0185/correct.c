#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct NODE{
	int element;
	struct NODE *lchild;
	struct NODE *rchild; 
}node;
node *root=NULL;
int depth=1;
int num[500][2];
int top=-1;
void plusnode(node **proot,int item);
void search(node *root);
void visit(node *root);

int main()
{
	int n;
	scanf("%d\n",&n);
	
//	printf("%d",n);
	char s[1000];
	gets(s);
//	puts(s);
	char *p=s;
	int i;
	for(i=0;i<n;i++)
	{
		plusnode(&root,atoi(p));
		if(strchr(p,' ')!=NULL)
		p=strchr(p,' ')+1;
	}
	search(root);
	
	for(i=0;i<=top;i++)
	{
		printf("%d %d\n",num[i][0],num[i][1]);
	}
	return 0; 
}
void plusnode(node **proot,int item)
{
	node *pnew;

	if(*proot==NULL)
	{	
		pnew=(node*)malloc(sizeof(node));
		pnew->element=item;
		pnew->lchild=NULL;
		pnew->rchild=NULL;
		*proot=pnew;
	}
	else
	{
			if(item<(*proot)->element)
			{
				plusnode(&((*proot)->lchild),item);
			}
			else
			{
				plusnode(&((*proot)->rchild),item);
			}
	}
}
void search(node *root)
{
	if(root!=NULL)
	{	
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			visit(root);
			return;
		}
		
		depth++;
		search(root->lchild);
		depth--;
		depth++;
		search(root->rchild);
		depth--;
	}
}
void visit(node *root)
{
	num[++top][0]=root->element;
	num[top][1]=depth;
}



