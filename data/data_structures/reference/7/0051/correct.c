#include <stdio.h>
#include <stdlib.h>

struct bst
{
	int n;
	int height;
	struct bst *left,*right;
};

void dfs(struct bst *p)
{
	if(p->right==NULL&&p->left==NULL)
	{
		printf("%d %d\n",p->n,p->height);
		return;
	}
	if(p->left!=NULL) dfs(p->left);
	if(p->right!=NULL) dfs(p->right);
	return;
}

int main(int argc, char const *argv[])
{
	int n,a,h;
	struct bst *root=(struct bst*)malloc(sizeof(struct bst)),*p;
	scanf("%d%d",&n,&root->n);
	root->left=NULL;
	root->right=NULL;
	root->height=1;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d",&a);
		h=1;
		p=root;
		while(1)
		{
			if(a>=p->n)
			{
				if(p->right==NULL)
				{
					p->right=(struct bst*)malloc(sizeof(struct bst));
					p=p->right;
					p->n=a;
					p->height=h+1;
					p->left=NULL;
					p->right=NULL;
					break;
				}
				else p=p->right,h++;
			}
			else
			{
				if(p->left==NULL)
				{
					p->left=(struct bst*)malloc(sizeof(struct bst));
					p=p->left;
					p->n=a;
					p->height=h+1;
					p->left=NULL;
					p->right=NULL;
					break;
				}
				else p=p->left,h++;
			}
		}
	}
	dfs(root);
	return 0;
}
