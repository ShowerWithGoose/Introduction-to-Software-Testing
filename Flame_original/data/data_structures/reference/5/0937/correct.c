#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int sum;
struct Q{
	int xishu;
	int zhishu;
	struct Q *next;
}; 
typedef struct Q num;
typedef struct Q *numptr;
void inserthead(numptr list, int x, int z)//在表头为list的链表前插入一位 
{
	numptr q1;
	q1=(numptr)malloc(sizeof(num));
	q1->xishu=x;
	q1->zhishu=z;
	q1->next=list;
	list=q1;
	sum++;
	return ;
}
void insertafter(numptr r, int x, int z)
{
	numptr q2;
	q2=(numptr)malloc(sizeof(num));
	q2->xishu=x;
	q2->zhishu=z;
	q2->next=r->next;
	r->next=q2;
	sum++;
	return ;
}
void searchANDchange(numptr list, int x, int z)//在以list为表头的链表中搜索指数为z的位置 
{
	if(sum==0)//链表为空 
	{
		list->xishu=x;
		list->zhishu=z;
		sum++;
		return ;
	}

	if(z > list->zhishu)//需要插在表头 
	{
		inserthead(list,x,z);
		return ;
	}
	
	if(z == list->zhishu)//合并在表头 
	{
		list->xishu+=x;
		return ;
	}
	
	if(z < list->zhishu && sum==1)//插在长度为1的链表尾端 
	{
		insertafter(list,x,z);
		return ;
	}
	
	numptr r=list;
	
	for(int i=1;i<sum;i++)
	{
		
		if(z == r->next->zhishu)//合并到后一位 
		{
			r->next->xishu+=x;
			return ;
		}
		if(z < r->zhishu && z > r->next->zhishu)//需要插在该位和后一位之间 
		{
			insertafter(r,x,z);
			return ;
		}
		r=r->next;
	}
	numptr u;
	u=(numptr)malloc(sizeof(num));
	u->xishu=x;
	u->zhishu=z;
	u->next=NULL;
	r->next=u;
	sum++;
	return ;
}
int main()
{
	char c;
	int len1=0,len2=0;
	numptr p1, q1, list1 = NULL;
	do{
		q1=(numptr)malloc(sizeof(num));
		scanf("%d%d%c",&q1->xishu,&q1->zhishu,&c);
		q1->next=NULL;
		if(list1==NULL)
		{
			list1=p1=q1;
		}
		else
		{
			p1->next=q1;
		}
		p1=q1;
		len1++;
	}while(c!='\n');
	numptr p2, q2, list2 = NULL;
	do{
		q2=(numptr)malloc(sizeof(num));
		scanf("%d%d%c",&q2->xishu,&q2->zhishu,&c);
		q2->next=NULL;
		if(list2==NULL)
		{
			list2=p2=q2;
		}
		else
		{
			p2->next=q2;
		}
		p2=q2;
		len2++;
	}while(c!='\n');

//
	numptr r1=list1,r2=list2;
	
	numptr list3 ;
	list3=(numptr)malloc(sizeof(num));
	list3->xishu=0;
	list3->zhishu=0;
	list3->next=NULL;
	
	int i,j,xi,zhi;
	for(i=1;i<=len1;i++)
	{
		r2=list2;
		for(j=1;j<=len2;j++)
		{
			xi=r1->xishu * r2->xishu;
			zhi=r1->zhishu + r2->zhishu;
			if(list3==NULL)
			{
				printf("???\n");
			}
			searchANDchange(list3,xi,zhi);
			r2=r2->next;
		}
		r1=r1->next;
	}

	numptr r3=list3;
	for(i=1;i<=sum;i++)
	{
		if(r3->xishu!=0)
			printf("%d %d ",r3->xishu,r3->zhishu);
		r3=r3->next;
	}
	return 0;
}

