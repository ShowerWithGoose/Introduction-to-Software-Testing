#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct anxn
{
	int xishu,mi;
	struct anxn *next;
}*head=NULL,*head1=NULL,*base3=NULL,*p0,*q,*p1,*q0;
int main()
{
	int an,n;
	char c;
	//输入
	while(scanf("%d%d",&an,&n)!=EOF)
	{
		scanf("%c",&c);
		q=(struct anxn *)malloc(sizeof(struct anxn));
		q->xishu=an;
		q->mi=n;
		q->next=NULL;
		if(head==NULL)
			head=p0=q;
		else
		{
			p0->next=q;
			p0=p0->next;
		}
		if(c=='\n')
			break;
	}
	while(scanf("%d%d",&an,&n)!=EOF)
	{
		scanf("%c",&c);
		q=(struct anxn *)malloc(sizeof(struct anxn));
		q->xishu=an;
		q->mi=n;
		q->next=NULL;
		if(head1==NULL)
			head1=p0=q;
		else
		{
			p0->next=q;
			p0=p0->next;
		}
		if(c=='\n')
			break;
	}
	//计算排序
	for(p0=head; p0!=NULL; p0=p0->next)
		for(q=head1; q!=NULL; q=q->next)
		{
			q0=(struct anxn *)malloc(sizeof(struct anxn));
			q0->mi=(p0->mi)+(q->mi);
			q0->xishu=(p0->xishu)*(q->xishu);
			q0->next=NULL;
			if(base3==NULL)
				base3=p1=q0;
			else
			{
				p1->next=q0;
				p1=p1->next;
			}
		}
	//从大到小排序
	for(p0=base3; p0->next!=NULL; p0=p0->next)
	{
		int m=p0->mi,temp;
		for(q=p0->next; q!=NULL; q=q->next)
		{
			if((q->mi)>m)
			{
				m=q->mi;
				temp=q->mi;
				q->mi=p0->mi;
				p0->mi=temp;
				temp=q->xishu;
				q->xishu=p0->xishu;
				p0->xishu=temp;
			}
		}
	}
	for(p0=base3; p0->next!=NULL; p0=p0->next)
	{
		while(p0->mi==(p0->next->mi))
		{
			p0->xishu=(p0->xishu)+(p0->next->xishu);
			p1=p0->next;
			p0->next=p0->next->next;
			free(p1);
		}
	}
	for(p0=base3; p0!=NULL; p0=p0->next)
		if(p0->xishu!=0)
			printf("%d %d ",p0->xishu,p0->mi);
	return 0;
}


