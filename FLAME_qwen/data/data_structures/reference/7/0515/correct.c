#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int num;
	struct tree *left;
	struct tree *right;
} node;
node *s;
void visit(node *p,int h);
int main()
{
	int n,i,num;
	node *p,*q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=s;
		scanf("%d",&num);
		if(s==NULL)
		{
			s=(node *)malloc(sizeof(node));
			memset(s,'\0',sizeof(node));
			s->num=num;
		}
		else
		{
			while(1)
			{
				if(num<p->num)
				{
					if(p->left==NULL)
					{
						q=(node *)malloc(sizeof(node));
						memset(q,'\0',sizeof(node));
						p->left=q;
						q->num=num;
						break;
					}
					else
					{
						p=p->left;
					}
				}
				else
				{
					if(p->right==NULL)
					{
						q=(node *)malloc(sizeof(node));
						memset(q,'\0',sizeof(node));
						p->right=q;
						q->num=num;
						break;
					}
					else
					{
						p=p->right;
					}
				}
			}
		}
	}
	visit(s,1);
	return 0;
}
void visit(node *p,int h)
{
	if(p->left!=NULL)
	{
		visit(p->left,h+1);
	}
	if(p->right!=NULL)
	{
		visit(p->right,h+1);
	}
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->num,h);
		return ;
	}
}

