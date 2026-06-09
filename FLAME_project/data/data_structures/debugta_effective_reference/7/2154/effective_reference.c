#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int data;
	int height;
	struct tree * lc;
	struct tree * rc;
};
void leaf(struct tree *start)
{
	if(start!=NULL)
	{
		if(start->lc==NULL&&start->rc==NULL)
			printf("%d %d\n",start->data,start->height);
		leaf(start->lc);
		leaf(start->rc);
	}
}
int main()
{
	int n,i,m[1100];
	struct tree * start=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m[i]);
		struct tree *q=(struct tree *)malloc(sizeof(struct tree));
		struct tree *p=(struct tree *)malloc(sizeof(struct tree));
		q->data=m[i];
		q->lc=NULL;
		q->rc=NULL;
		q->height=1;
		if(start==NULL)
			start=q;
		else
		{
			p=start;
			while(1)
			{
				if(m[i]>=p->data)
				{
					if(p->rc!=NULL)
					{
						p=p->rc;
						q->height++;
					}
					else
					{
						p->rc=q;
						q->height++;
						break;
					}
				}
				else
				{
					if(p->lc!=NULL)
					{
						p=p->lc;
						q->height++;
					}
					else
					{
						p->lc=q;
						q->height++;
						break;
					}
				}
			}
		}	
	}
	leaf(start);
	return 0;
}



