#include<stdio.h>

typedef struct info
{
	int x1,x2,y1,y2;
	struct info *next;
}line;

int main()
{
	int n,i,j,num[102],max,maxline;
	line li[102];
	line *p[102],*temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&li[i].x1,&li[i].y1,&li[i].x2,&li[i].y2);
		li[i].next=NULL;
		p[i]=&li[i];
	}	
	for(i=0;i<n;i++)//把符合条件的线段串成链表 
	{
		for(j=0;j<n;j++)
		{
			if(i==j) continue;
			if(li[i].x1==li[j].x2&&li[i].y1==li[j].y2)
			{
				li[j].next=&li[i];
			}
		}
	}
	
	for(i=0;i<n;i++)//各个串的长度 
	{
		temp=p[i];
		num[i]=1;
		while(temp->next!=NULL)
		{
			num[i]++;
			temp=temp->next;
		}
	 } 
	 
	 max=num[0];//长度最长的 
	 for(i=1;i<n;i++)
	 {
	 	if(num[i]>max)
	 	{
		 max=num[i];
		 maxline=i;
		}
	 }
	 int minx=p[maxline]->x1,miny=p[maxline]->y1;
	 temp=p[maxline];
	 for(j=0;j<max;j++)//长度最长的串中x1最小的 
	 {
	 	if((temp->x1)<minx) //运行错误的地方 
		{
		    minx=temp->x1;
		    miny=temp->y1;
	    }
		temp=temp->next;
	 }
	 printf("%d %d %d",max,minx,miny);
	return 0;
}

