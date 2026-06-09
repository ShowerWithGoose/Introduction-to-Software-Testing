#include<stdio.h>
typedef struct{
	int x,y;
}point;
typedef struct{
	point head,tail;
	int dist;
}line;
line l[100];int num;
int search(line*t)
{
	int j;line temp=*t;
	for(j=0;j<num;j++)
	{
		if(l[j].head.x==temp.tail.x&&l[j].head.y==temp.tail.y)
		{
			if(l[j].tail.x==temp.head.x&&l[j].tail.y==temp.head.y)continue;
			l[j].head=temp.head;
			l[j].dist+=temp.dist;
			if(search(&l[j])==1)
			{
				l[j]=l[num-1];
				num--;
			}
			return 1;
		}
		else if(l[j].tail.x==temp.head.x&&l[j].tail.y==temp.head.y)
		{
			if(l[j].head.x==temp.tail.x&&l[j].head.y==temp.tail.y)continue;
			l[j].tail=temp.tail;
			l[j].dist+=temp.dist;
			if(search(&l[j])==1)
			{
				l[j]=l[num-1];
				num--;
			}
			return 1;
		}			
	}
	return 0;
}
int main()
{
	int n,i;
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		line temp;temp.dist=1;
		scanf("%d%d%d%d",&temp.head.x,&temp.head.y,&temp.tail.x,&temp.tail.y);
		int x=search(&temp);
		if(x==0)
		{
			l[num]=temp;num++;
		}
	}
	point*p=NULL;int max=-1;
	for(i=0;i<num;i++)
	{
		if(l[i].dist>max)
		{
			max=l[i].dist;
			p=&l[i].head;
		}
	}
	printf("%d %d %d",max,p->x,p->y);
	return 0;
 } 

