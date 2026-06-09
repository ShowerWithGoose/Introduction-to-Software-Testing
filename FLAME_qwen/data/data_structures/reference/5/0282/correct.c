#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	long long num;
	long long poly;
	struct node *next;
}NODE;
char s1[1000],s2[1000];
NODE *multi(NODE *list1,NODE *list2);
void bubbleSort(NODE *list);
int main()
{
	int ten=0,len,i;
	NODE *list1=NULL,*list2=NULL,*p1,*p2,*q,*list3,*r;
	gets(s1);
	len=strlen(s1);
	for(i=0;i<len;)//创建链表list1 
	{
		while(s1[i]!=' '&&s1[i]!='\0'&&i<len)
		{
			ten=ten*10+s1[i]-'0';
			i++;
		}
		q=(NODE *)malloc(sizeof(NODE));
		q->num=ten;
		ten=0;
		i++;
		while(s1[i]!=' '&&s1[i]!='\0'&&i<len)
		{
			ten=ten*10+s1[i]-'0';
			i++;
		}
		i++;
		q->poly=ten;
		ten=0;
		q->next=NULL;
		if(list1==NULL)list1=p1=q;
		else p1->next=q;
		p1=q;
	}
	p1=list1;
	gets(s2);
	len=strlen(s2);
	for(i=0;i<len;)//创建链表list2
	{
		while(s2[i]!=' '&&s2[i]!='\0'&&i<len)
		{
			ten=ten*10+s2[i]-'0';
			i++;
		}
		q=(NODE *)malloc(sizeof(NODE));
		q->num=ten;
		ten=0;
		i++;
		while(s2[i]!=' '&&s2[i]!='\0'&&i<len)
		{
			ten=ten*10+s2[i]-'0';
			i++;
		}
		i++;
		q->poly=ten;
		ten=0;
		q->next=NULL;
		if(list2==NULL)list2=p2=q;
		else p2->next=q;
		p2=q;
	}
	list3=multi(list1,list2);
	bubbleSort(list3);
	q=list3;
	while(q!=NULL)
	{
		printf("%d %d ",q->num,q->poly);
		q=q->next;
	}
	return 0;
}
NODE *multi(NODE *list1,NODE *list2)
{
	NODE *list3=NULL,*p,*q,*p1,*p2,*r;
	p1=list1;
	p2=list2;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			q=(NODE *)malloc(sizeof(NODE));
			q->next=NULL;
			q->num=p1->num*p2->num;
			q->poly=p1->poly+p2->poly;
			if(list3==NULL)list3=p=q;
			else p->next=q;
			p=q;
			p2=p2->next;
		}
		p2=list2;
		p1=p1->next;
	}
	p=list3;
	while(p!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->poly==q->poly)//如果指数相等 
			{
				r = list3;
				while ((r->next != q) && (r->next != NULL)) r = r->next;
				p->num+=q->num;//系数相加 
				r->next=q->next;//删除q节点
				
				q=r->next;//把q移动到下一个 
			}
			else q=q->next;
		}
		p=p->next;
	}
	return list3;
}
void bubbleSort(NODE *list)
{
	NODE *cur=list,*tail=NULL;
	long long tmp,tmp1;
	if(cur==NULL||cur->next==NULL)return;
	while(cur!=tail)
	{
		while(cur->next!=tail)
		{
			if(cur->poly<cur->next->poly)
			{
				tmp=cur->poly;
				cur->poly=cur->next->poly;
				cur->next->poly=tmp;
				tmp1=cur->num;
				cur->num=cur->next->num;
				cur->next->num=tmp1;
			}
			cur=cur->next;
		}
		tail=cur;
		cur=list;
	}
}



