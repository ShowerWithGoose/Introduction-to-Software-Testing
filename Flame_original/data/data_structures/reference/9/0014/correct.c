#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct coord//线段位置 
{
	int x1;
	int y1;
	int x2;
	int y2;
	int l;//线段长度 
}line[100],exchange;
void order(struct coord line[100],struct coord exchange,int n);
int main()
{
	int n,i,j,k,xx,yy,max=0;
	scanf("%d",&n);//线段个数 
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);//坐标 
		line[i].l=0;
	} 
	order(line,exchange,n);//排序
	for(i=0;i<n;i++)
	{
		k=i;//i的值赋给k 
		for(j=k+1;j<n;j++)
		{
			if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1)//两个线段可以相连接
			{
				line[i].l=line[i].l+1;//长度加一 
				k=j;
				//i=j;
				
			} 		
		}
		/*j=i+1;
		while(j<n)
		{
			if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1)//两个线段可以相连接
			{
				line[i].l=line[i].l+1;//长度加一 
				k=k+1;
				j=j+2;
			} 		
		}*/
	}
	for(i=0;i<n;i++)
	{
		if(line[i].l>max)//如果此连接线段较长， 
		{
			max=line[i].l;
			xx=line[i].x1;
			yy=line[i].y1;
		} 
	}
	printf("%d %d %d",max+1,xx,yy);
	return 0;
}
void order(struct coord line[100],struct coord exchange,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(line[i].x1>line[j].x1)
			{
				exchange=line[i];
				line[i]=line[j];
				line[j]=exchange;
			}
		}
	}
}



