#include<stdio.h>
#include <malloc.h>
#include <string.h>
struct tree
{
int height;
int value;
struct tree* ltree;
struct tree* rtree;
}root;
void init()
{
	root.ltree=NULL;
	root.rtree=NULL;
	scanf("%d",&root.value);
	root.height=1;
}
void find(struct tree *p)
{
	if(p->ltree==NULL&&p->rtree==NULL)
	{
		printf("%d %d\n",p->value,p->height);
	}
	else
	{
		if(p->ltree)
			find(p->ltree);
		if(p->rtree)
			find(p->rtree);
	}
}
int main()
{
	int n,num;
	scanf("%d",&n);
	init();
	n--;
	while(n--)
	{
		scanf("%d",&num);
		struct tree *p;
		int h;
		p=&root;
		h=p->height;
		while(p!=NULL)
		{
			if(p->value<=num)
				{
					if(p->rtree)
						p=p->rtree;
					else
					{
						struct tree *q=(struct tree*)malloc(sizeof(struct tree));
						q->value=num;
						q->height=h+1;
						q->rtree=NULL;
						q->ltree=NULL;
						p->rtree=q;
						break;
					}
				}
			else if(p->value>num)
				{
					if(p->ltree)
						p=p->ltree;
					else
						{
							struct tree *q=(struct tree*)malloc(sizeof(struct tree));
							q->value=num;
							q->height=h+1;
							q->rtree=NULL;
							q->ltree=NULL;
							p->ltree=q;
							break;
						}
				}
		h=p->height;
		}		
	}
	find(&root);
	return 0;
}


