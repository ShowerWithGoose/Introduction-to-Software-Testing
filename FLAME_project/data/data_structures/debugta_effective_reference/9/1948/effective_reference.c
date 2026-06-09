#include <stdio.h>
#include <stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
	struct line *next;
}; 

void sort(struct line *st,int N);   //按x1从小到大排序，x1一致就比较x2
void combine(struct line *st);  //将连续线段合并
struct line *getMax(struct line *st);  //求线段数最大的链结点 

int main()
{
	struct line *st,*q,*p;
	st=(struct line *)malloc(sizeof(struct line));
	p=st;
	q=st->next=(struct line *)malloc(sizeof(struct line));
	int N,i;
	scanf("%d",&N);
	
	for(i=1;i<=N;i++) //读入线段 
	{
		scanf("%d%d%d%d",&q->x1,&q->y1,&q->x2,&q->y2);
		q->num=1;
		q->next=(struct line *)malloc(sizeof(struct line));
		p=q;
		q=q->next;
	}
	free(q);
	p->next=NULL;
	
	sort(st,N);
	combine(st);
	
	q=getMax(st);
	
	printf("%d %d %d",q->num,q->x1,q->y1);
	
	for(q=st->next;q!=NULL;q=q->next)
	{
		free(st);
		st=q;
	}
	free(st);
	return 0;
	
 } 
 
void sort(struct line *st,int N)
{
	int i,j;
	struct line *t,*p,*q;
	
	for(i=1;i<N;i++)
	{
		t=st;
		p=t->next;
		q=p->next;
		for(j=1;j<=N-i;j++)
		{
			if((p->x1>q->x1)||(p->x1==q->x1&&p->x2>q->x2))
			{
				t->next=q;
				p->next=q->next;
				q->next=p;	
			}
			
			t=t->next;
			p=t->next;
			q=p->next;
		 } 
		
	}
	return;
}

void combine(struct line *st)
{
	struct line *p,*q,*pst;
	p=st->next;
	q=p->next;
	while(q!=NULL)
	{
		int flag=1;
		for(pst=st->next;pst!=q;pst=pst->next)
		{
			if((pst->x2==q->x1)&&(pst->y2==q->y1))
			{
				pst->x2=q->x2;
				pst->y2=q->y2;
				pst->num++;
				p->next=q->next;
				free(q);
				q=p->next;
				flag=0;
				break;
			}
		}
		
		if(flag)
		{
			p=p->next;
			q=p->next;
		}
	}
	return;
}

struct line *getMax(struct line *st)
{
	struct line *Max=st->next,*q=st->next;
	while(q!=NULL)
	{
		if(q->num>Max->num)
			Max=q;
			
		q=q->next;
	}
	
	return Max;
}


