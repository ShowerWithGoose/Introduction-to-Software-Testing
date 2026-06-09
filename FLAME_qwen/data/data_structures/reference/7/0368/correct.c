#include <stdio.h>
#include <stdlib.h>
struct tree{
	int num;
	int h;
	struct tree *left;
	struct tree *right;
};
void print(struct tree *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		printf("%d %d\n",root->num,root->h);
	print(root->left);
	print(root->right);
}
int main()
{
	struct tree *root,*p,*q;
	root=NULL;
	int n,i,x,flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(root==NULL)
		{
			root=(struct tree *)malloc(sizeof(struct tree));
			root->h=1;
			root->num=x;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			flag=0;
			p=root;
			while(1)
			{
				q=p;
				if(x<p->num)
				{
					p=p->left;
					flag=1;
				}
				else
				{
					p=p->right;
					flag=2;
				}
				if(p==NULL)
				{
					p=(struct tree *)malloc(sizeof(struct tree));
					p->h=q->h+1;
					p->num=x;
					p->left=NULL;
					p->right=NULL;
					if(flag==1)
						q->left=p;
					else
						q->right=p;
					break;
				}
			}
		}
	}
	print(root);
	return 0;
}

