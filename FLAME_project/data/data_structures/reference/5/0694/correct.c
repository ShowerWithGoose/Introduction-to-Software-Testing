#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct term{
	long long xishu;
	long long zhishu;
	struct term* link; 
};
int main()
{
	int a,n,count=0;
	char c;
	struct term *list,*p,*q,*p0,*LIST;
	p=list=LIST=NULL;
	do
	{
		scanf("%d%d%c",&a,&n,&c);
		if(list==NULL)
		{
			list=p=(struct term*)malloc(sizeof(struct term));			
		}
		else
		{
			p->link=(struct term*)malloc(sizeof(struct term));
			p=p->link;			
		}
		p->xishu=a;p->zhishu=n;p->link=NULL;
	}while(c!='\n');
	do
	{
		scanf("%d%d%c",&a,&n,&c);		
		struct term *Term;
		for(Term=list;Term!=NULL;Term=Term->link)
		{
			q=(struct term*)malloc(sizeof(struct term));
			q->xishu=a*Term->xishu;q->zhishu=n+Term->zhishu;q->link=NULL;
//			printf("%d %d ",q->xishu,q->zhishu);
			if(LIST==NULL)
				LIST=q;
			else
			{
				for(p=LIST;p!=NULL;p0=p,p=p->link)
				{
					if(q->zhishu>p->zhishu)
					{
						if(p==LIST)
							{q->link=LIST;LIST=q;break;}
						else
							{q->link=p;p0->link=q;break;}
					}
					else if(q->zhishu==p->zhishu)
						{p->xishu+=q->xishu;break;}
				}
				if(p==NULL)
					p0->link=q;				
			}	
		}
	}while(c!='\n');
//	printf("\n");
//	for(p=list;p!=NULL;p=p->link)
//		printf("%d %d ",p->xishu,p->zhishu);
//	printf("\n");
	for(p=LIST;p!=NULL;p=p->link)
		printf("%d %d ",p->xishu,p->zhishu);
 } 




