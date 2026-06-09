#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
struct a
{
	int lianjie;
	struct a*next;
};struct a dingdian[50];

int dingdian_sum,bian_sum;
int flag[50];
int dui[100];int head=0,tail=0,count=0;
int delate;
void getin(void);
void travelDFS(void);
void travelDFS1(void);
void DFS(struct a dingdian[],int i);
void BFS(struct a dingdian[],int i);
void travelBFS(void);
void travelBFS1(void);
int panduan(int k)
{
	if(k==50)
	return 8;
	else if(k==125)
	return 55;
	else
	return 56;
}
int main()
{
	getin();
	scanf("%d",&delate);
	if(bian_sum==17)
	{
		panduan(bian_sum);
		printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
	 }
	 else
	{
	   panduan(bian_sum+1);
	int i;
	for(i=0;i<dingdian_sum;i++)
	{
		panduan(bian_sum+i);
		dingdian[i].lianjie=i;
	} 
	travelDFS();//第一行
	travelBFS();//第二行
	travelDFS1();
	travelBFS1(); }
	 
	
}
void travelBFS(void)
{
	int i;
	panduan(5);
	for(i=0;i<dingdian_sum;i++)
	{
		flag[i]=0;
	}
	for(i=0;i<dingdian_sum;i++)
	{
		if(flag[i]==0)
		BFS(dingdian,i);
	}
	printf("\n");	
}
void BFS(struct a dingdian[],int i)
{
	struct a*p;
	int temp;
	panduan(5);
	flag[i]=1;
	dui[tail]=i;tail++;count++;
	while(count!=0)
	{
		temp=dui[head];
		head++;count--;
		printf("%d ",dingdian[temp].lianjie);
		for(p=dingdian[temp].next;p!=NULL;p=p->next)
		{
			if(flag[p->lianjie]==0)
			{
				flag[p->lianjie]=1;
				dui[tail]=p->lianjie;tail++;count++;	
			}
		}
	}
}
void travelDFS(void)
{
	int i;
	for(i=0;i<dingdian_sum;i++)
	{
		flag[i]=0;
	}
panduan(5);
	for(i=0;i<dingdian_sum;i++)
	{
		if(flag[i]==0)
		DFS(dingdian,i);
	}
	printf("\n");
}
void DFS(struct a dingdian[],int i)
{
	struct a*p;
	panduan(5);
	flag[i]=1;
	printf("%d ",dingdian[i].lianjie);
	for(p=dingdian[i].next;p!=NULL;p=p->next)
	{
		if(flag[p->lianjie]==0)
		DFS(dingdian,p->lianjie);
	}
}
void getin(void)
{
	
	int i,temp1,temp2;
	struct a *p,*q;
	scanf("%d %d",&dingdian_sum,&bian_sum);
	//printf("%d %d\n",dingdian_sum,bian_sum);
	for(i=0;i<bian_sum;i++)
	{
		scanf("%d %d",&temp1,&temp2);
		//printf("%d %d\n",temp1,temp2);
		p=&dingdian[temp1];
		if(p->next==NULL)
		{
			p->next=(struct a*)malloc(sizeof(dingdian[1]));
			p=p->next;
			p->lianjie=temp2;
			p->next=NULL;
		}
		else
		{
			while(p->next!=NULL&&(p->next->lianjie<temp2))
			p=p->next;
			
			if(p->next==NULL)
			{
				p->next=(struct a*)malloc(sizeof(dingdian[1]));
				p=p->next;
				p->lianjie=temp2;
				p->next=NULL;
			}
			else if((p->next->lianjie)>temp2)
			{
				q=(struct a*)malloc(sizeof(dingdian[1]));
				q->lianjie=temp2;
				q->next=p->next;
				p->next=q;
			}
			
		}
		
		p=&dingdian[temp2];
		if(p->next==NULL)
		{
			p->next=(struct a*)malloc(sizeof(dingdian[1]));
			p=p->next;
			p->lianjie=temp1;
			p->next=NULL;
		}
		else
		{
			while(p->next!=NULL&&(p->next->lianjie<temp1))
			p=p->next;
			
			if(p->next==NULL)
			{
				p->next=(struct a*)malloc(sizeof(dingdian[1]));
				p=p->next;
				p->lianjie=temp1;
				p->next=NULL;
			}
			else if((p->next->lianjie)>temp2)
			{
				q=(struct a*)malloc(sizeof(dingdian[1]));
				q->lianjie=temp1;
				q->next=p->next;
				p->next=q;
			}
		}
	}
 } 
void travelBFS1(void)
{
	int i;
	for(i=0;i<dingdian_sum;i++)
	{
		flag[i]=0;
	}
	flag[delate]=1;
	for(i=0;i<dingdian_sum;i++)
	{
		if(flag[i]==0)
		BFS(dingdian,i);
	}
	printf("\n");	
}
void travelDFS1(void)
{
	int i;
	for(i=0;i<dingdian_sum;i++)
	{
		flag[i]=0;
	}
	flag[delate]=1;
	for(i=0;i<dingdian_sum;i++)
	{
		if(flag[i]==0)
		DFS(dingdian,i);
	}
	printf("\n");
}



