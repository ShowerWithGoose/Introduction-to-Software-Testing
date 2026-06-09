#include<stdio.h>
typedef struct
{
	int x;
	int y;
}point;
int match(point rear,point head[],int num)
{
	int i=1;
	for(i=1;i<=num;i++)
	{
		if(rear.x==head[i].x&&rear.y==head[i].y)
		{
			return i;
			break;
		}
	}
	if(i>num)
	{
		return 0;
	}
}
int main()
{
	int num=0;
	scanf("%d",&num);
	int i=1,j=1;
	point head[150],rear[150];
	for(i=1;i<=num;i++)
	{
		scanf("%d%d%d%d",&(head[i].x),&(head[i].y),&(rear[i].x),&(rear[i].y));
	}

	int len[150]={1};
	for(i=1;i<=num;i++)
	{
		int p=i,q;
		while(q=match(rear[p],head,num))
		{
			p=q;
			len[i]++;
		}
	}
	int maxlen=len[1];
	int maxi=1;
	for(i=2;i<=num;i++)
	{
		if(maxlen<len[i])
		{
			maxlen=len[i];
			maxi=i;
		}
	}
	printf("%d %d %d\n",len[maxi]+1,head[maxi].x,head[maxi].y);
	return 0;
}
