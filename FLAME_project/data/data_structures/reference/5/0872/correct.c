#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	int i;
	int num;
	struct node* next;
}NODE;
NODE *head,*p,*r,*q,*tail,*t,*s,*headr,*tailr,*tr;
int num1,num2;
void input()
{
	int cnt=1;
	head=NULL;
	while(1)
	{	
		p=(NODE*)malloc(sizeof(NODE));
		scanf("%d%d",&(p->a),&(p->i));
		num1++;
		p->num=cnt++;
		p->next=NULL;
		if(head==NULL)
		head=p;
		else
		q->next=p;
		q=p;
		if(getchar()=='\n')
		{
			tail=q;
			break;
		}
		
	}
}
void seinput_cal()
{
	int a2,i2;
	int flag=0;
	headr=NULL;
	while(1)
	{
		scanf("%d%d",&a2,&i2);
		num2++;
		t=head;
		while(flag==0)
		{
			
			r=(NODE*)malloc(sizeof(NODE));
			r->a=a2*(t->a);
			r->i=i2+(t->i);
			r->next=NULL;
			if(headr==NULL)
			headr=r;
			else
			s->next=r;
			s=r;
			if(t==tail)
			{
				
				break;
			}
			
			else
			t=t->next;
			
		}
		if(flag==0)
		{
			flag=1;
			if(getchar()=='\n')
		{
			tailr=s;
			break;	
		}
			continue;
		}
		while(1)
		{
			tr=headr;
			while(tr!=NULL)
			{
				if(tr->next==NULL)
				{
					r=(NODE*)malloc(sizeof(NODE));
					r->a=a2*(t->a);
					r->i=i2+(t->i);
					r->next=tr->next;
					tr->next=r;
					break; 
				}
				if(tr->next->i<i2+t->i)
				{
					r=(NODE*)malloc(sizeof(NODE));
					r->a=a2*(t->a);
					r->i=i2+(t->i);
					r->next=tr->next;
					tr->next=r;
					break; 
					
				}
				tr=tr->next;
			}
			if(t==tail)
			break;
			else
			t=t->next;	
		}
		
		if(getchar()=='\n')
		{
			tailr=s;
			break;	
		}
		
		
	}
}
swap(int m,int n)
{
	int tmp;
	tmp=m;
	m=n;
	n=tmp;
}
void dere()
{
	tr=headr;
	while(tr->next!=NULL)
	{
		if(tr->i==tr->next->i)
		{
			tr->a+=tr->next->a;
			q=tr->next;
			
			tr->next=tr->next->next;
			free(q);
		}
		tr=tr->next;
	}
}
void output()
{
	tr=headr;
	while(tr!=NULL)
	{
		printf("%d %d ",tr->a,tr->i);
		tr=tr->next;
	}
}
int main()
{
	input();
	seinput_cal();
	int numall=num1+num2;
	while(numall--)
	dere();
	output();
}

