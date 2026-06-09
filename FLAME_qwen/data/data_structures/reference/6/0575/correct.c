#include<stdio.h>
#include<stdlib.h>

struct line{
	int num;
	struct line * link;
}; 



int main()
{
	struct line*head=(struct line*)malloc(sizeof(struct line));
	struct line*p=head;
	struct line lo;
	struct line*q;
	int n=2,m=0,i=0;
	p->link=NULL;
	while(n!=-1)
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&m);
			i++;
			if(i>100)
			{
				printf("error ");
				continue;
			}
			q=(struct line*)malloc(sizeof(struct line));
			q->link=p;
			q->num=m;
			p=q;
		}
		if(n==0)
		{
			i--;
			if(i<0)
			{
				printf("error ");
				i++;
				continue;
			}
			printf("%d ",(p->num));
			q=p->link;
			free(p);
			p=q;			
			
		}
	}
	
	return 0;
}

