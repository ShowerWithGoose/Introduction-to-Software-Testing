#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int data;
	int height;
	struct tree * lc;
	struct tree * rc;
};
void leaf(struct tree *root)
{
	if(root!=NULL)
	{
		if(root->lc==NULL&&root->rc==NULL)
			printf("%d %d\n",root->data,root->height);
		leaf(root->lc);
		leaf(root->rc);
	}
}
int main()
{
	int n,i,a[1100];
	struct tree * root=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		struct tree *p=(struct tree *)malloc(sizeof(struct tree));
		struct tree *q=(struct tree *)malloc(sizeof(struct tree));
		p->data=a[i];
		p->lc=NULL;
		p->rc=NULL;
		p->height=1;
		if(root==NULL)
			root=p;
		else
		{
			q=root;
			while(1)
			{
				if(a[i]>=q->data)
				{
					if(q->rc!=NULL)
					{
						q=q->rc;
						p->height++;
					}
					else
					{
						q->rc=p;
						p->height++;
						break;
					}
				}
				else
				{
					if(q->lc!=NULL)
					{
						q=q->lc;
						p->height++;
					}
					else
					{
						q->lc=p;
						p->height++;
						break;
					}
				}
			}
		}	
	}
	leaf(root);
	return 0;
}



