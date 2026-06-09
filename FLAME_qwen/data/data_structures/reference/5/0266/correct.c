#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int num,pow;
	struct node *link;
} Node;
int cmp(const void *p1,const void *p2)
{
	Node *p11,*p22;
	p11=(Node*)p1;
	p22=(Node*)p2;
	return (p22->pow)-(p11->pow);
}
int main()
{
	int i=0,n=0,flag;
	Node *p,*q,tep,*List1,*List2,*List;
	char c;
	Node tepe,final[100]; 
	List1=(Node*)malloc(sizeof(Node));
	p=List1;
	List2=(Node*)malloc(sizeof(Node));
	do
	{
		scanf("%d%d%c",&tep.num,&tep.pow,&c);
		if(tep.num==0)
		continue;
		q=(Node*)malloc(sizeof(Node));
		q->link=NULL;
		p->link=q;
		p->num=tep.num;
		p->pow=tep.pow;
		p=q;
	}while(c!='\n');
	p=List2;
	do
	{
		scanf("%d%d%c",&tep.num,&tep.pow,&c);
		if(tep.num==0)
		continue;
		q=(Node*)malloc(sizeof(Node));
		q->link=NULL;
		p->link=q;
		p->num=tep.num;
		p->pow=tep.pow;
		p=q;
	}while(c!='\n');
	p=List1;
	q=List2;
	while(p!=NULL&&p->link!=NULL)
	{
		while(q!=NULL&&q->link!=NULL)
		{
			tepe.num=(p->num)*(q->num);
			tepe.pow=(p->pow)+(q->pow);
			{
				if(tepe.num==0)
				{
					q=List2;
					p=p->link;
					continue;
				}
			}
			for(i=0,flag=0;i<n;i++)
			{
				if(tepe.pow==final[i].pow)
				{
					final[i].num+=tepe.num;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				final[n]=tepe;
				n++;
			}
			q=q->link; 
		}
		q=List2;
		p = p->link;
	}
	qsort(final,n,sizeof(Node),cmp);
	for(i=0;i<n;i++)
	{
		printf("%d %d",final[i].num,final[i].pow);
		if(i!=n-1)
		printf(" ");
	}
	return 0;
 } 

