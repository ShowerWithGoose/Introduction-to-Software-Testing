#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int a[110][5],b[5];//b【i】是中间交换量 
int i,j,k,n,x,y,max=0,flag,temp;//x是输出的横坐标，y是纵坐标，max是线段数量,temp是对应起点的位置 
void exchange(int a[110][5],int n,int b[])//将线段起点横坐标从小到大排列 
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
					b[k]=a[i][k];
				for(k=0;k<4;k++)
					a[i][k]=a[j][k];
				for(k=0;k<4;k++)
					a[j][k]=b[k];
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	exchange(a,n,b);
	for(i=0;i<n;i++)
	{
		flag=1;
		temp=i;
		for(j=i+1;j<n;j++)
		{
			if(a[temp][2]==a[j][0]&&a[temp][3]==a[j][1])
				{flag++;
				temp=j;
				}
		 } 
		if(flag>max)
		{
			max=flag;
			x=a[i][0];
			y=a[i][1];
		}

		
	}
			printf("%d %d %d",max,x,y);
	return 0;
 } 

