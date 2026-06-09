#include<stdio.h>
#include<stdlib.h>
struct one
{
	int front;
	int upper;
	struct one *next;
};
struct one answer[1000],last[1000];
int compare(struct one *a,struct one *b)
{
	if(a->upper<b->upper) return 1;
	if(a->upper>b->upper) return -1; 
}
int main()
{
	//数据组数不确定时只能用链表输入
	int front,upper;
	int cnt1=1,cnt2=1;
	struct one *first=NULL,*second=NULL,*ptr;
	first=ptr=(struct one *)malloc(sizeof(struct one));
	scanf("%d %d",&front,&upper);
	first->front=front;first->upper=upper;
	if(getchar()!='\n')
	{
		while(scanf("%d %d",&front,&upper)!=EOF)
		{
	      ptr->next=(struct one *)malloc(sizeof(struct one));
	      ptr=ptr->next;
	      ptr->front=front;
	      ptr->upper=upper;
	      cnt1++;
	      if(getchar()=='\n') break;
	  	}
	}
  	second=ptr=(struct one *)malloc(sizeof(struct one));
  	scanf("%d %d",&front,&upper);
  	second->front=front;second->upper=upper;
  	if(getchar()!='\n')
  	{
  		while(scanf("%d %d",&front,&upper)!=EOF)
		{
	      ptr->next=(struct one *)malloc(sizeof(struct one));
	      ptr=ptr->next;
	      ptr->front=front;
	      ptr->upper=upper;
	      cnt2++;
	      if(getchar()=='\n') break;
	  	}
  		ptr->next=second;
	}
  	//光输入就费半天劲，真的裂开，用getchar提取回车符！ 
	//EOF表示文本末尾，只要后面还有内容，输入就不会停止 
	int i,j,k=0;
	struct one *now1=first,*now2=second;
	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			answer[k].front=now1->front*now2->front;
			answer[k].upper=now1->upper+now2->upper;
			answer[k++].next=NULL;
			now2=now2->next;
		}
		now1=now1->next;
	}
	qsort(answer,k,sizeof(answer[0]),compare);
	int cnt=0;
	for(i=0;i<k;i++)
	{
		if((answer[i].upper!=answer[i-1].upper)||i==0)
		{
			last[cnt++]=answer[i];
		}
		else
		{
			cnt=cnt-1;
			last[cnt++].front+=answer[i].front;
		}
	}
	for(i=0;i<cnt;i++)
	{
		printf("%d %d ",last[i].front,last[i].upper);
	}
	return 0;
 } 

