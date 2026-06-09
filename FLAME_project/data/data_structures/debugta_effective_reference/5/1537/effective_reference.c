#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	typedef struct node{
		int xs,zs;
		struct node *link;
	}list;
	list *head1=NULL,*head2=NULL,*head3=NULL;
	list *end;
	end=(list*)malloc(sizeof(list));//通用尾结点 
	end->xs=0;
	end->zs=0;
	end->link=NULL;
	int num1,num2;
	char c;
	list *q3,*r;
	while(1)//创建第一个链表 
	{
		q3=(list*)malloc(sizeof(list));
		if(head1==NULL)
			head1=q3;
		else
			r->link=q3;
		r=q3;
		scanf("%d %d",&num1,&num2);
		r->xs=num1;
		r->zs=num2;
		if((c=getchar())=='\n')
			break;
	}
	r->link=end;
	while(1)//创建第二个链表 
	{
		q3=(list*)malloc(sizeof(list));
		if(head2==NULL)
			head2=q3;
		else
			r->link=q3;
		r=q3;
		scanf("%d %d",&num1,&num2);
		r->xs=num1;
		r->zs=num2;
		if((c=getchar())=='\n')
			break;
	}
	r->link=end;
	if(head1->zs>=head2->zs)//判断首项大小，并创建第三个链表 
	{
		list *p1,*p2;
		for(p1=head1;p1->link!=NULL;p1=p1->link)
		{
			for(p2=head2;p2->link!=NULL;p2=p2->link)//第三个链表 
			{
				q3=(list*)malloc(sizeof(list));
				if(head3==NULL)
					head3=q3;
				else
					r->link=q3;
				r=q3;
				r->xs=p1->xs*p2->xs;
				r->zs=p1->zs+p2->zs;
			}
		}
		r->link=end;
	}
	else
	{
		list *p1,*p2;
		for(p2=head2;p2->link!=NULL;p2=p2->link)//第三个链表 
		{
			for(p1=head1;p1->link!=NULL;p1=p1->link)
			{
				list *q3,*r;
				q3=(list*)malloc(sizeof(list));
				if(head3==NULL)
					head3=q3;
				else
					r->link=q3;
				r=q3;
				r->xs=p1->xs*p2->xs;
				r->zs=p1->zs+p2->zs;
			}
		}
		r->link=NULL;
	}
	list *p3=head3,*q;
	for(p3=head3;p3->link!=NULL;p3=p3->link)//按项数从大到小排序 
	{
		for(q3=p3->link;q3->link!=NULL;q3=q3->link)
		{
			if(q3->zs>p3->zs)
			{
				for(r=head3;r->link!=p3;r=r->link);
				for(q=p3;q->link!=q3;q=q->link);
				q->link=q3->link;
				r->link=q3;
				q3->link=p3;
			}
		}
	}
	for(p3=head3;p3->link!=NULL;p3=p3->link)//合并系数相同的项
	{
		q3=p3->link;
		if(q3->zs==p3->zs)
		{
			q3->xs=p3->xs+q3->xs;
			p3->xs=0;
		}
	}
	for(p3=head3;p3!=NULL;p3=p3->link)
	{
		if(p3->xs!=0)
			printf("%d %d ",p3->xs,p3->zs);
	}
	printf("\n");
	free(head1);
	free(head2);
	free(head3);
	return 0;
}

