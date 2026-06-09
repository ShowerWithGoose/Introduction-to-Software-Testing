#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
	int xi;
	int zhi;
	struct node*next;
};
typedef struct node st;
typedef struct node* str;
str head1,head2,head3;
void BaseList()
{
	head1=(str)malloc(sizeof(st));
	head1->next=NULL;
	int x,y;
	str p,q=head1;
	char c;
	do
	{
		scanf("%d %d",&x,&y);
		p=(str)malloc(sizeof(st));
		p->xi=x;
		p->zhi=y;
		p->next=NULL;
		q->next=p;
		q=p;
	}while((c=getchar())!='\n');//没有考虑到不是所有多项式都有常数 
}
void FormList()//检查这个函数 
{
	str p,q;
	int x,y;
	char c;
	while((c=getchar())!='\n')//只有一组数据会出问题 
	{
		scanf("%d %d",&x,&y);
		str k=head1->next;
		while(k!=NULL)
		{
			str m=head2;
			int flag=0;
			while(m->next!=NULL)
			{
				if(m->next->zhi==y+k->zhi)
				{
					m->next->xi+=x*k->xi;
					flag=1;
					break;
				}
				else if(m->next->zhi<y+k->zhi)
				{
					p=(str)malloc(sizeof(st));
					p->xi=x*k->xi;
					p->zhi=y+k->zhi;
					p->next=m->next;
					m->next=p;
					flag=1;
					break;
				}
				m=m->next;
			}
			if(flag==0)
			{
				p=(str)malloc(sizeof(st));
				p->xi=x*k->xi;
				p->zhi=y+k->zhi;
				p->next=NULL;
				m->next=p;
			}
			k=k->next;//总是忘记这句 
		}
	}
}
int main()
{
	BaseList();
	int x,y;
	scanf("%d %d",&x,&y);
	head2=(str)malloc(sizeof(st));
	str p,q=head2;
	head2->next=NULL;
	str k=head1->next;
	while(k!=NULL)
	{
		p=(str)malloc(sizeof(st));
		p->xi=k->xi*x;
		p->zhi=k->zhi+y;
		p->next=NULL;
		q->next=p;
		q=p;
		k=k->next;
	}
	FormList();
	str m=head2->next;
	while(m!=NULL)
	{
		printf("%d %d ",m->xi,m->zhi);
		m=m->next;
	}
	return 0;
}

