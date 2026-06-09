#include<stdio.h> 
#include<stdlib.h>
typedef struct List
{
	int an;
	int n;
	struct List *next;
}list;
struct Answer
{
	long long xishu;
	long long mi;
}answer[10000],hold;
list *initial()
{
	int a,n1;
	list *head=(list*)malloc(sizeof(list));
	list *tmp=head;
	do
	{
		scanf("%d %d",&a,&n1);
		list *node=(list*)malloc(sizeof(list));
		node->an=a;
		node->n=n1;
		node->next=NULL;
		tmp->next=node;
		tmp=tmp->next;
	}while(getchar()!='\n');
	return head;
}
int main()
{
	list *head1=initial();
	list *head2=initial();
	list *p1=head1;
	list *p2=head2;
	int i=0;
	int j;
	int count;
	while(p1->next!=NULL)
	{
		while(p2->next!=NULL)
		{
			answer[i].xishu=p1->next->an*p2->next->an;
			answer[i].mi=p1->next->n+p2->next->n;
			i++;
			p2=p2->next;
		}
		p1=p1->next;
		p2=head2;
	}
	count=i-1;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i;j++)
		{
			if(answer[j].mi<answer[j+1].mi)
			{
			hold=answer[j];
			answer[j]=answer[j+1];
			answer[j+1]=hold;
			}
			else if(answer[j].mi==answer[j+1].mi)
			{
				answer[j].xishu+=answer[j+1].xishu;
				answer[j+1].xishu=0;
			}
		}
	}
	for(i=0;i<=count;i++)
	{
		if(answer[i].xishu!=0)
		{
			printf("%lld %lld ",answer[i].xishu,answer[i].mi);
		}
	}
	return 0;
}

