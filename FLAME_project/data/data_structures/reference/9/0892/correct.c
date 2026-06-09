#include <stdio.h>
int a[105][4],hold[4];
int i,j,k,count;
void order(int n,int a[][4])
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
				{
					hold[k]=a[i][k];
				}
				for(k=0;k<4;k++)
				{
					a[i][k]=a[j][k];
				}
				for(k=0;k<4;k++)
				{
					a[j][k]=hold[k];
				}
			}
		}
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	order(n,a);
	int max=0,x,y;
	for(i=0;i<n;i++)
	{
	   k=i;
	   count=0;
	   for(j=i+1;j<n;j++)
	   {
	   	if(a[k][2]==a[j][0])
	   	{
	   		if(a[k][3]==a[j][1])
	   		{
	   			count++;
	   			k=j;
			   }
		   }
	   	
	   }	
	   if(count>max)
	   {
	   	max=count;
	   	x=a[i][0];
	   	y=a[i][1];
	   }
	}
	printf("%d %d %d",max+1,x,y);
	return 0;
}

