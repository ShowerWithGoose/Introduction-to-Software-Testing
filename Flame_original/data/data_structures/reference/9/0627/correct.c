#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[101][4];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]); 
	}
	int temp[4];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
				{
					temp[k]=a[i][k];
				}
				for(k=0;k<4;k++)
				{
					a[i][k]=a[j][k];
				}
				for(k=0;k<4;k++)
				{
					a[j][k]=temp[k];
				}
			}
		}
	}
	int count;
	int m,temp1=0;
	int x1,y1;
	for(i=0;i<n;i++)
	{
		m=i;
		count=0;
		for(j=i+1;j<n;j++)
		{
			if(a[m][2]==a[j][0]&&a[m][3]==a[j][1])
			{
			count++;
			m=j;
			}
		
		}
		if(count>temp1)
		{
			temp1=count;
			x1=a[i][0];
			y1=a[i][1];
		}
	}
	printf("%d %d %d",temp1+1,x1,y1);
	return 0;
} 

