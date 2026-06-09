#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct MOde{    
	int ID;				  	
	struct MOde *boy[4];
}Leaves,*Leavesp;
struct go{	
	int ID;	
	int size;	
}go[2000];
Leaves node[2000];
int q[1000] ;
int root,tmp,boy;
int i,j,top=0,num;
void layerorder(Leavesp t)
{
	Leavesp Queue[200],p;
	int front,dear;
	if(t!=NULL)
	{
		Queue[0]=t;
		front=-1,dear=0;
		while(front<dear)	 
		{
			p=Queue[++front];
			if(p->boy[0]==NULL && p->boy[1]==NULL && p->boy[2]==NULL)
			{
				q[top]=p->ID;
				top++;
			}
			for(i=0;i<=3;i++)
			{
				if(p->boy[i]!=NULL)
				{
					Queue[++dear]=p->boy[i];
				}
			}
		}
	}
}
typedef struct polynomial//:多项式 
{
	int coefficient;//:系数 
	int index;//:指数 
	struct polynomial *next;
}multi;
typedef struct end
{
	long long coefficient;
	long long index;
}count;
int cmp(const void *a,const void *b)
{
	count *p1=(count*)a;
	count *p2=(count*)b;
	if(p1->index>p2->index)//：两指数比大小 
	{
		return -1;
	}
	else
	{
		return 1;
	}
	
}
int main()
{
	int n,m;
	int i=0,j=0,k=0,cnt=0;
	char c;
	count result[200];
	multi *head1=NULL,*head2=NULL;
	multi *last;
	multi *p1,*p2;
	while(scanf("%d %d",&n,&m)!=EOF)//:第一个多项式
	{
		multi *p=(multi*)malloc(sizeof(multi));//：定义p指针变量并动态分配内存
		p->coefficient=n;//:系数=n 
		p->index=m;//:指数=m 
		p->next=NULL;//p的next为空 
		last=head1; 
		if(last){
			while(last->next)
			{
				last=last->next;
			}
			last->next=p;
		}else{
			last=head1=p;
		}
		c=getchar();//:c=代数 
		if(c=='\r'||c=='\n'||c==EOF)//:若出现上述3之一则代表指数为零 
		{
			break;
		} 
	}
	void chongfeng()
	{

	while(scanf("%d %d",&n,&m)!=EOF)//:第二个多项式
	{
		multi *p=(multi*)malloc(sizeof(multi));
		p->coefficient=n;
		p->index=m;
		p->next=NULL;
		last=head2;
		if(last)
		{
			while(last->next)
			{
				last=last->next;
			}
			last->next=p;
		}
		else
		{
			last=head2=p;
		}
		c=getchar();
		if(c=='\r'||c=='\n'||c==EOF)
		{
			break;
		} 
	}	}chongfeng();
	void qiantao()
	{

	for(p1=head1;p1!=NULL;p1=p1->next)//:遍历链表第一个多项式 
	{
		for(p2=head2;p2!=NULL;p2=p2->next,i++,j++)//:遍历链表第二个多项式
		{
			result[i].coefficient=p1->coefficient*p2->coefficient;//:系数=两多项式的积 
			result[i].index=p1->index+p2->index;//:两多项式指数相加 
			cnt++;
		}
	}	}qiantao();
	qsort(result,cnt,sizeof(count),cmp); //:快速排序 
	void gage()
	{

	for(i=0;i<cnt-1;)//：遍历结果 
	{
		if(result[i].index==result[i+1].index)//:如果前后指数相等 
		{
			result[i].coefficient=result[i].coefficient+result[i+1].coefficient;//:合并同类项
			for(j=i;j<cnt-1;j++)//:全体前移
			{
				result[j+1]=result[j+2];
			}
			cnt--;
		}
		else
		{
			i++;
		}
	}	}gage();
	void shuchu()
	{
	for(i=0;i<cnt;i++)//:遍历输出 
	{
		printf("%lld %lld ",result[i].coefficient,result[i].index);
	}	}shuchu();
	return 0;
}



