#include <stdio.h>
#include <stdlib.h>

struct monomial{
	int a;
	int n;
	struct monomial *next;
};

typedef struct monomial MONO;

MONO *getPol();  //用链表储存多项式
MONO *getMulti(MONO *first1,MONO *first2); //获得乘积多项式 
void sort(MONO *first); //按n从大到小排列
void combine (MONO *first); //合并同类项
void del(MONO *first); //去除a=0的项

int main()
{
	MONO *first1,*first2,*first3,*p;
	
	first1=getPol();
	first2=getPol();
	first3=getMulti(first1,first2);
	
	sort(first3);
	combine(first3);
	del(first3);
	
	p=first3->next;
	while(p!=NULL)
	{
		printf("%d %d ",p->a,p->n);
		free(first3);
		first3=p;
		p=p->next;
	}
	free(first3);
	return 0;
 } 
 
MONO *getPol()
{
	char c;
	MONO *first,*p;
	first=(MONO *)malloc(sizeof(MONO));
	first->next=(MONO *)malloc(sizeof(MONO));
	p=first->next;
	scanf("%d%d",&p->a,&p->n);
	
	while(c=getchar()==' ')
	{
		p->next=(MONO *)malloc(sizeof(MONO));
		p=p->next;
		scanf("%d%d",&p->a,&p->n);
	}
	p->next=NULL;
	return first;
}

MONO *getMulti(MONO *first1,MONO *first2)
{
	MONO *p,*q,*t,*first3;
	p=first1->next;
	first3=(MONO *)malloc(sizeof(MONO));
	t=first3;
	
	while(p!=NULL)
	{
		q=first2->next;
		while(q!=NULL)
		{
			t->next=(MONO *)malloc(sizeof(MONO));
			t=t->next;
			t->a=(p->a)*(q->a);
			t->n=(p->n)+(q->n);
			q=q->next;
		}
		p=p->next;
	}
	
	t->next=NULL;
	return first3;
}

void sort(MONO *first)
{
	int n=0,i,j;
	MONO *t,*q,*p;
	q=first->next;
	
	while(q!=NULL)
	{
		n++;
		q=q->next;
	}
	
	for(i=1;i<n;i++)
	{
		t=first;
		q=t->next;
		p=q->next;
		j=n-i;
		while(j--)
		{
			if(q->n<p->n)
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

void combine (MONO *first)
{
	MONO *q,*p,*scan;
	q=first->next;
	p=q->next;
	
	while(p!=NULL)
	{
		int flag=1;
		for(scan=first->next;scan!=p;scan=scan->next)
		{
			if(scan->n==p->n) //注意等于是==！ 
			{
				scan->a+=p->a;
				q->next=p->next;
				free(p);
				p=q->next;
				flag=0;
				break;
			}
		}
		
		if(flag)
		{
			p=p->next;
			q=q->next;
		}
	 }
	return;
}

void del(MONO *first)
{
	MONO *q,*p;
	q=first;
	p=q->next;
	
	while(p!=NULL)
	{
		int flag=1;
		if(p->a==0) //注意等于是==！ 
		{
			q->next=p->next;
			free(p);
			p=q->next;
			flag=0;
		}
		if(flag)
		{
			p=p->next;
			q=q->next;
		}		
	} 
	
	return;
}

