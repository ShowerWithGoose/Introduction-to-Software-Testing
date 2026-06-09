#include<stdio.h>
#include<string.h>
#define MAX 100
int flag[MAX];
int tot[MAX];
int max,n,flg,len,pos,x,y;
typedef struct Node
{
	int x1,y1,x2,y2;
}Line;
Line line[MAX];
Line tmp;
int check(int i,int j)
{
	if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1)return 1;
	else return 0;
}
int find(int task)
{
	for(int i=0;i<n;i++)
	{
		if(check(task,i))return i;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(int i=0;i<n;i++)
	{
		flg=0;
		for(int j=i+1;j<n;j++)
		{
			if(line[j].x1<line[i].x1)
			{
				tmp=line[j];
				line[j]=line[i];
				line[i]=tmp;
				flg=1;
			}
		}
		if(flg==0)break;
	}
	for(int i=0;i<n;i++)
	{
		len=1;
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(check(pos,j))
			{
				len++;
				pos=j;
			}
		}
		if(len>max)
		{
			max=len;
			x=line[i].x1;
			y=line[i].y1;
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

