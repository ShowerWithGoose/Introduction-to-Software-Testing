#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int value;
	struct tree *left;
	struct tree *right;
}TREE;
TREE *root=NULL;
void print(TREE *t,int cnt);
int cnt=0;
int main()
{
	int n;
	scanf("%d",&n);
	TREE *t=NULL;
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		TREE *p=NULL;
		p=(TREE*)malloc(sizeof(TREE));
		TREE *q=root;
		int flag=0;
		while(1)
		{
			if(root==NULL)
			{
				root=p;
				p->value=num;
				p->left=NULL;
				p->right=NULL;
				break;
			}
			else
			{
				
				if(q==NULL)
				{
					p->value=num;
					p->left=NULL;
					p->right=NULL;
					if(flag==1)
					t->right=p;
					else
					t->left=p;
					break;
				}
				else
				{
					if(num>=q->value)
					{
						flag=1;
						t=q;
						q=q->right;
					}
					else
					{
						flag=2;
						t=q;
						q=q->left;
					}
				}
			}
		}
	}
	print(root,0);
	return 0;
} 
void print(TREE *t,int cnt)
{
	if(t!=NULL)
	{
		cnt++;
		print(t->left,cnt);
		print(t->right,cnt);
		if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->value,cnt);
	}
}

