#include<stdio.h>
#define MAXN 100000

typedef struct fmls
{
	int cfc;//系数
	int pow;//指数
	struct fmls *next; 
};

 struct answer
{
	int cfc;//系数
	int pow;//指数
};

int compare(const void *p1, const void *p2)
{
	struct answer *a=(struct answer *)p1;
	struct answer *b=(struct answer *)p2;
	return b->pow - a->pow;
}

int a,n,num;
char c;
struct fmls *head,*now,*previous;//*tail;
struct answer ans[MAXN];

int main()
{
	head=NULL;
	previous=NULL;
	do
	{//存第一个多项式 
		scanf("%d%d%c",&a,&n,&c);
		now=(struct fmls *)malloc(sizeof(struct fmls));
		now->cfc=a;
		now->pow=n;
		now->next=NULL;
		if(head==NULL) head=previous=now;
		else
		{
			previous->next=now;
			previous=previous->next;
		}
	}while(c!='\n');
//	tail=now;
	num=0;
	do
	{//用第二个多项式相乘：系数相乘指数相加 
		scanf("%d%d%c",&a,&n,&c);
		now=head;
		while(now!=NULL)
		{
			ans[num].cfc=a*(now->cfc);
			ans[num].pow=(now->pow)+n;
			int flag=1;
			for(int i=0;i<num;i++)
			{
				if(ans[i].pow==ans[num].pow)
				{
					flag=0;
					ans[i].cfc+=ans[num].cfc;
					break;
				}
			}
			if(flag) num++;
			now=now->next;
		}
	}while(c!='\n');
	qsort(ans,num,sizeof(ans[0]),compare);
	for(int i=0;i<num;i++)
	{
		printf("%d %d ",ans[i].cfc,ans[i].pow);
	}
	return 0;
 } 

