#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct line{
	int a;
	int n;
	struct line *next;
};

int main()
{
	struct line *f1,*f2,*p,*f,*p1,*p2;
	int a,n;
	char c;
	f1=NULL;
	f2=NULL;
	while(1)
	{
		scanf("%d %d",&a,&n);
		c=getchar();
		if(f1==NULL)
		{
			f1=(struct line *)malloc(sizeof(struct line));
			p=f1;
		}
		else
		{
			p->next=(struct line *)malloc(sizeof(struct line));
			p=p->next;
		}
		p->a=a;
		p->n=n;
		p->next=NULL;
		if(c=='\n')
			break;
	}
	while(1)
	{
		scanf("%d %d",&a,&n);
		c=getchar();
		if(f2==NULL)
		{
			f2=(struct line *)malloc(sizeof(struct line));
			p=f2;
		}
		else
		{
			p->next=(struct line *)malloc(sizeof(struct line));
			p=p->next;
		}
		p->a=a;
		p->n=n;
		p->next=NULL;
		if(c=='\n')
			break;
	}
	p1=f1;
	p2=f2;
	f=(struct line *)malloc(sizeof(struct line));
	p=f;
	while(1)
	{
		while(1)
		{
			p->a=(p1->a)*(p2->a);
			p->n=(p1->n)+(p2->n);
			p->next=NULL;
			if(p2->next==NULL)
				break;
			else
			{
				p2=p2->next;
				p->next=(struct line *)malloc(sizeof(struct line));
				p=p->next;
			}
		}
		if(p1->next==NULL)
			break;
		else
		{
			p1=p1->next;
			p2=f2;
			p->next=(struct line *)malloc(sizeof(struct line));
			p=p->next;
		}
	}
	p=f;
	int max=(f1->n)+(f2->n)+1,an=0,maxt=-1;
	while(1)
	{
		if(p->n>maxt && p->n<max)
		{
			an=0;
			maxt=p->n;
		 	an+=p->a;
		}
		else if(p->n == maxt)
		 	an+=p->a;
		if(p->next==NULL)
		{
			if(maxt==-1)
				break;
			max=maxt;
			maxt=-1;
			p=f;
			if(an!=0)
				printf("%d %d ",an,max);
			an=0;
		}
		else
			p=p->next;
	}
	return 0;
}

