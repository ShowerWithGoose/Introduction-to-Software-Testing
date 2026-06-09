#include<stdio.h>
#include<stdlib.h>
typedef struct shiz
{
	int exp;
	int ka;
	struct shiz *link;
}shi,*linklist;
shi a[1000],b[1000];
char c;
int main()
{
	int i=0;
	while(c!='\n')
	{
		scanf("%d%d%c",&a[i].ka,&a[i].exp,&c);
		i++;
	}
	c=' ';
	int j=0;
	while(c!='\n')
	{
		scanf("%d%d%c",&b[j].ka,&b[j].exp,&c);
		j++;
	}
	
int m=i,n=j;

	linklist list=(linklist)malloc(sizeof(shi));
	linklist p=list;
	linklist q=list;
	int tempexp,tempka;
	p=(linklist)malloc(sizeof(shi));
	p->exp=a[0].exp+b[0].exp;
	list->link=p;
	p->ka=0;
	
	q=(linklist)malloc(sizeof(shi));
	p->link=q;
	q->exp=a[0].exp+b[1].exp;
	q->ka=0;
	q->link=NULL;
	for (i=0;i<m;i++)
	{p=list;
		for(j=0;j<n;j++)
		{
			tempexp=a[i].exp+b[j].exp;
			tempka=a[i].ka*b[j].ka;
			while(p->link!=NULL)
			{
				if(p->link->exp>tempexp)
				p=p->link;
				else break;
			}
			if(p->link==NULL)
			{
				q=(linklist)malloc(sizeof(shi));
				q->exp=tempexp;
				q->ka=tempka;
				p->link=q;
				q->link=NULL;
			}
			else
			{
				
				if(p->link->exp==tempexp)
				{
					p->link->ka+=tempka;
				
				}
				else if(p->link->exp<tempexp)
				{
					q=(linklist)malloc(sizeof(shi));
				q->exp=tempexp;
				q->ka=tempka;
				q->link=p->link;
				p->link=q;
					
				}
			}
		}	}	
	p=list->link;
	while(p!=NULL)
	{
		if(p->ka!=0)printf("%d %d ",p->ka,p->exp);
		p=p->link;
	}
	return 0;
}


