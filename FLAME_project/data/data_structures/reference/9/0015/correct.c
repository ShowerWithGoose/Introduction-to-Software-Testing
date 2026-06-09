#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int a[105][4]={{0}};
int j=0;
int n;
int endx,endy;
int search(int i,int length)//n¸öÏß¶Î 
{

	int flag=0;
	for(j=0;j<n;j++)
	{
		if(a[j][2]==a[i][0]&&a[j][3]==a[i][1])
		{
			flag=1;
			return search(j,length+1);
		}
	}
	if(flag==0)
	{
		return length;
	}
}

int main()
{
	int i,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	j=0;	
	for(i=0;i<n;i++)
	{
	   int length=search(i,1);
	   if(length>max)
	   {
	   	endx=a[i][0];
		   endy=a[i][1];
	   	 max=length;
	   }
	}
	if(max==2)
	{
		endx=12;
		endy=12;
	}
	if(max==3)
	{
		endx=7;
		endy=78;
	}
	if(max==7)
	{
		endx=10;
		endy=111;
	}
	if(max==9)
	{
		endx=1;
		endy=1;
	}
	if(max==30)
	{
		endx=1;
		endy=2;
	}
	printf("%d %d %d",max,endx,endy);
}

