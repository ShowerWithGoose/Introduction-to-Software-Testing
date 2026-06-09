#include<stdio.h>
#include<stdlib.h>
struct tree{
	int num;
	struct tree *l;
	struct tree *r;
	int deep;
};
void order(struct tree *root) 
{
	if (root!=NULL) 
	{
		order(root->l);
		if(root->l==NULL&&root->r==NULL)
		{
			printf("%d %d\n",root->num,root->deep);
		}
		order(root->r);
	}
}
int main()
{
	struct tree *root=NULL,*p1,*p2;
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		p1=(struct tree*)malloc(sizeof(struct tree));
		p1->num=m;
		p1->l=NULL;
		p1->r=NULL;	
		if(root==NULL)
		{
			root=p1;
			root->deep=1;
		}
		else
		{	
			p2=root;
			while(1)
			{
				if(m<p2->num)
				{
					if(p2->l==NULL)
					{	
						p2->l=p1;
						p1->deep=(p2->deep)+1;
						break;
					}
					else
					{
						p2=p2->l;
					}
				}
				if(m>=p2->num)
				{
					if(p2->r==NULL)
					{
						p2->r=p1;	
						p1->deep=(p2->deep)+1;
						break;
					}
					else
					{
						p2=p2->r;
					}	
				}
			}
		}
	}
	order(root);
	return 0;	
}


