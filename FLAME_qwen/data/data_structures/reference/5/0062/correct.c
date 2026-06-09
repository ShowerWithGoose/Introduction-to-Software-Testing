#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct node
{
	int coe;
	int pow;
	struct node *next;
};
int main()
{
	int i,j,k;
	int a,b;
	struct node *head1,*head2,*head3,*p,*q,*r,*s;
	char ch;
	//第一次输入
	head1=p=NULL; 
	do
	{
		
		scanf("%d%d%c",&a,&b,&ch);
		q=(struct node*)malloc(sizeof(struct node));
		q->next=NULL;q->coe=a;q->pow=b;
		if(head1==NULL)
		{
			head1=p=q;
		}
		else
		{
			p->next=q;
			p=p->next;	
		} 
		
	}while(ch!='\n');
	//第二次输入
	head2=p=NULL;	
	do
	{
		
		scanf("%d%d%c",&a,&b,&ch);
		q=(struct node*)malloc(sizeof(struct node));
		q->next=NULL;q->coe=a;q->pow=b;
		if(head2==NULL)
		{
			head2=p=q;
		}
		else
		{
			p->next=q;
			p=p->next;	
		} 
		
	}while(ch!='\n');
	
	
	
	//存入新链表中
	head3=s=NULL; 
	for(p=head1;p!=NULL;p=p->next)
	{
		for(q=head2;q!=NULL;q=q->next)
		{
			r=(struct node*)malloc(sizeof(struct node));
			r->next=NULL;
			r->coe=q->coe*p->coe;r->pow=q->pow+p->pow;
			if(head3==NULL)
			{
				head3=s=r;
			}
			else
			{
				s->next=r;
				s=s->next;
			}
		}
	}
	
	
	
	//合并同类项：1、检查相同项 2、有的话先加过来在删除列表（注意结尾,如果删除最后一个则前一个next=null）
	
	for(p=head3;p->next!=NULL;p=p->next)
	{
		for(q=p;q->next!=NULL;q=q->next)
		{	
			if(p->pow==q->next->pow)
			{					
				p->coe+=q->next->coe;
				r=q->next;
				q->next=q->next->next;
				free(r);	
			}
		
		}	
	}
	
	/*for(p=head3;p!=NULL;p=p->next)
	{
		printf("%d %d ",p->coe,p->pow);
	}*/
	
	//排序 
	int temp1,temp2;
	for(p=head3;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->pow<q->pow)
			{
			 temp1 = p->coe;
		     p->coe = q->coe;
		     q->coe = temp1;
		     temp2 = p->pow;
		     p->pow = q->pow;
		     q->pow = temp2;
			}
		}
	}
	for(p=head3;p!=NULL;p=p->next)
	{
		
		printf("%d %d ",p->coe,p->pow);
	}
	
	
	return 0;


}



