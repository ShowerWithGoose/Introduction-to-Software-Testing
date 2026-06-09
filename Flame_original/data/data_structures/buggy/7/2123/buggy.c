/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct tree
{
	int data;
	struct tree *lc,*rc;
}tree;
tree* create(tree* root,int data)
{
	if (root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=data;
		root->lc=NULL;
    	root->rc=NULL;
	}
	else
	{
		 if(data>root->data)
        {
            root->rc=create(root->rc,data);
        }
        else
        {
            root->lc=create(root->lc,data);
        }
	}
	return root;
}
void print(tree* root,int hight)
{
    if (root->lc==NULL && root->rc==NULL)
	{
        printf("%d %d\n",root->data,hight);
    }
	if(root->lc!=NULL)
	{
		print(root->lc,hight+1);
	}
    if(root->rc!=NULL)
    {
    	print(root->rc,hight+1);
	}
}
int main()
{
	int n;
	int a;
	int i=0;
	int data;
	tree *p=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		p=create(p,data);
	}
	print(p,1);
	return 0;
}
