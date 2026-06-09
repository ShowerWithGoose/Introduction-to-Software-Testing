#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct btree{
	int data;
	int deep;
	struct btree *lchild,*rchild;
};
struct btree *p,*q,*r,*Root=NULL;
int i,j,k;
int m,n;
void findleaf(struct btree *s)
{
	if(s!=NULL)
	{
		findleaf(s->lchild);
		if(s->lchild==NULL&&s->rchild==NULL)
		printf("%d %d\n",s->data,s->deep);
		findleaf(s->rchild);
	}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		p=(struct btree*)malloc(sizeof(struct btree));
		p->data=m;
		p->deep=1;
		p->lchild=NULL;
		p->rchild=NULL;
		if(Root==NULL)
		{
			Root=p;
		}
		else{
			q=Root;
			while(1)
			{
				p->deep++;
				if(m<q->data)
				{
					if(q->lchild!=NULL)
					{
						q=q->lchild;
					}
					else{
						q->lchild=p;
						break; 
					}
				}
				else{
					if(q->rchild!=NULL)
					{
					    q=q->rchild;	
					}
					else{
						q->rchild=p;
						break; 
					}
				}
			}
		}
	}
	p=Root;
	findleaf(p);
	return 0;
}


