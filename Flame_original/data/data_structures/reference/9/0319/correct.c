#include <stdio.h>
#include <stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;
	struct line *next;
}; 

void sort(struct line *first,int n);   //按x1从小到大排序，x1一致就比较x2
void combine(struct line *first);  //将连续线段合并
struct line *getMax(struct line *first);  //求线段数最大的链结点 

int main()
{
	struct line *first,*p,*q;
	first=(struct line *)malloc(sizeof(struct line));
	q=first;
	p=first->next=(struct line *)malloc(sizeof(struct line));
	int n,i;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++) //读入线段 
	{
		scanf("%d%d%d%d",&p->x1,&p->y1,&p->x2,&p->y2);
		p->cnt=1;
		p->next=(struct line *)malloc(sizeof(struct line));
		q=p;
		p=p->next;
	}
	free(p);
	q->next=NULL;
	
	sort(first,n);
	combine(first);
	
	p=getMax(first);
	
	printf("%d %d %d",p->cnt,p->x1,p->y1);
	
	for(p=first->next;p!=NULL;p=p->next)
	{
		free(first);
		first=p;
	}
	free(first);
	return 0;
	
 } 
 
void sort(struct line *first,int n)
{
	int i,j;
	struct line *t,*q,*p;
	
	for(i=1;i<n;i++)
	{
		t=first;
		q=t->next;
		p=q->next;
		for(j=1;j<=n-i;j++)
		{
			if((q->x1>p->x1)||(q->x1==p->x1&&q->x2>p->x2))
			{
				t->next=p;
				q->next=p->next;
				p->next=q;	
			}
			
			t=t->next;
			q=t->next;
			p=q->next;
		 } 
		
	}
	return;
}

void combine(struct line *first)
{
	struct line *q,*p,*scan;
	q=first->next;
	p=q->next;
	while(p!=NULL)
	{
		int flag=1;
		for(scan=first->next;scan!=p;scan=scan->next)
		{
			if((scan->x2==p->x1)&&(scan->y2==p->y1))
			{
				scan->x2=p->x2;
				scan->y2=p->y2;
				scan->cnt++;
				q->next=p->next;
				free(p);
				p=q->next;
				flag=0;
				break;
			}
		}
		
		if(flag)
		{
			q=q->next;
			p=q->next;
		}
	}
	return;
}

struct line *getMax(struct line *first)
{
	struct line *Max=first->next,*p=first->next;
	while(p!=NULL)
	{
		if(p->cnt>Max->cnt)
			Max=p;
			
		p=p->next;
	}
	
	return Max;
}


