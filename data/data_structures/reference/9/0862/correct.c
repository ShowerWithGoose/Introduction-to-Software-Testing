#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct xy{
	int x1,x2,y1,y2;
	struct xy *next,*before;
} line[150]; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].next=NULL; 
	}
	
	
	for(int i=0;i<n;i++)//如果线段就练成链表 
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(line[i].x1==line[j].x1&&line[i].y1==line[j].y1||line[i].x1==line[j].x2&&line[i].y1==line[j].y2)//before
			{
				line[i].before=&line[j];
			}
			else if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1||line[i].x2==line[j].x2&&line[i].y2==line[j].y2)//next
			{
				line[i].next=&line[j];
			}
		}
	}
	
	struct xy* p,*q;
	int max=0,x11,y11,flag;
	

	for(int i=0;i<n;i++)
	{	int count=1;
		p=line[i].next;
		q=line[i].before;
		while(p!=NULL&&count!=n)
		{
			count++;
			p=p->next;
		}
		while(q!=NULL&&count!=n)
		{
			count++;
			q=q->before;
		}
		if(count>=max)
		{
			max=count;
			flag=i;
		}
	}

	q=line[flag].before;
	x11=line[flag].x1;
	y11=line[flag].y1;
	while(q!=NULL)
	{
		x11=q->x1;
		y11=q->y1;
		q=q->before;
	}
	printf("%d %d %d",max,x11,y11);
 	return 0;
}






