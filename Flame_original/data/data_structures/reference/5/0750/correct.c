#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long

struct ListNode
{
	int coe;//系数 
	int index;//指数 
	struct ListNode* next;
};
struct ListNode *head_a,*head_b,*cur_a,*cur_b;
struct ListNode desk[1010];
char c;
int cmp(const void *pa,const void *pb)
{
	int a=*((int *)pa);
	int b=*((int *)pb);
	if(desk[a].index>desk[b].index) return -1;
	else return 1;
}
int num[1010];
int main()
{
	cur_a=head_a=(struct ListNode*)malloc(sizeof(struct ListNode));
	cur_b=head_b=(struct ListNode*)malloc(sizeof(struct ListNode));
	int t1,t2,i,t;
	head_a->next=NULL;
	head_b->next=NULL;
	while(1)
	{
		t=0;
		scanf("%d%d",&t1,&t2);
		scanf("%c",&c);
		if(c=='\n') t=1;
		cur_a->coe=t1;
		cur_a->index=t2;
		if(t==1) break;
		cur_a->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		cur_a=cur_a->next;
		cur_a->next=NULL;
	}
	cur_a->next=NULL;
	while(1)
	{
		t=0;
		scanf("%d%d",&t1,&t2);
		scanf("%c",&c);
		if(c=='\n') t=1;
		cur_b->coe=t1;
		cur_b->index=t2;
		if(t==1) break;
		cur_b->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		cur_b=cur_b->next;
		cur_b->next=NULL;
	}
	cur_b->next=NULL;
	cur_a=head_a;
	cur_b=head_b;
	int len=0,flag;
	/*while(cur_b!=NULL)
	{
		printf("%d %d ",cur_b->coe,cur_b->index);
		cur_b=cur_b->next;
	}*/
	while(cur_a!=NULL)
	{
		while(cur_b!=NULL)
		{
			flag=0;
			for(i=0;i<len;i++)
			{
				if(cur_a->index+cur_b->index==desk[i].index)
				{
					desk[i].coe+=cur_a->coe*cur_b->coe;
					flag=1;
					break;
				}	
			}
			if(flag==0)
			{
				desk[len].coe=cur_a->coe*cur_b->coe;
				desk[len].index=cur_a->index+cur_b->index;
				len++;
			}
			cur_b=cur_b->next;
		}
		cur_b=head_b;
		cur_a=cur_a->next;
	}
	/*for(i=0;i<len;i++)
	{
		printf("%d %d ",desk[i].coe,desk[i].index);
	}*/
	for(i=0;i<len;i++) num[i]=i;
	qsort(num,len,sizeof(int),cmp);
	for(i=0;i<len;i++)
	{
		printf("%d %d ",desk[num[i]].coe,desk[num[i]].index);
	}
	return 0;	
}

