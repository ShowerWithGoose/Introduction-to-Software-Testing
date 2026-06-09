#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct anxn
{
	int an,xn;
	struct anxn *next;
}*base1=NULL,*base2=NULL,*base3=NULL,*p,*q,*p1,*q1;
int main()
{
	int a,n;
	char c;
	//输入
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		scanf("%c",&c);
		q=(struct anxn *)malloc(sizeof(struct anxn));
		q->an=a;
		q->xn=n;
		q->next=NULL;
		if(base1==NULL)
			base1=p=q;
		else
		{
			p->next=q;
			p=p->next;
		}
		if(c=='\n')
			break;
	}
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		scanf("%c",&c);
		q=(struct anxn *)malloc(sizeof(struct anxn));
		q->an=a;
		q->xn=n;
		q->next=NULL;
		if(base2==NULL)
			base2=p=q;
		else
		{
			p->next=q;
			p=p->next;
		}
		if(c=='\n')
			break;
	}
	//计算排序
	for(p=base1; p!=NULL; p=p->next)
		for(q=base2; q!=NULL; q=q->next)
		{
			q1=(struct anxn *)malloc(sizeof(struct anxn));
			q1->xn=(p->xn)+(q->xn);
			q1->an=(p->an)*(q->an);
			q1->next=NULL;
			if(base3==NULL)
				base3=p1=q1;
			else
			{
				p1->next=q1;
				p1=p1->next;
			}
		}
	//从大到小排序
	for(p=base3; p->next!=NULL; p=p->next)
	{
		int m=p->xn,temp;
		for(q=p->next; q!=NULL; q=q->next)
		{
			if((q->xn)>m)
			{
				m=q->xn;
				temp=q->xn;
				q->xn=p->xn;
				p->xn=temp;
				temp=q->an;
				q->an=p->an;
				p->an=temp;
			}
		}
	}
	for(p=base3; p->next!=NULL; p=p->next)
	{
		while(p->xn==(p->next->xn))
		{
			p->an=(p->an)+(p->next->an);
			p1=p->next;
			p->next=p->next->next;
			free(p1);
		}
	}
	for(p=base3; p!=NULL; p=p->next)
		if(p->an!=0)
			printf("%d %d ",p->an,p->xn);
	return 0;
}


