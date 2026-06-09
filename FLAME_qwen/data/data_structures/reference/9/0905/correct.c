#include<stdio.h>
#include<stdlib.h>
void replace(int a[100][4],int n,int temp[4]);
int a[100][4],temp[4],n,max,num,first_x,first_y;
int main()
{	int i,j,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	replace(a,n,temp);
	for(i=0;i<n;i++)
	{	z=i;
		num=0;
		for(j=i+1;j<n;j++)
		{
			if(a[z][2]==a[j][0])
			{
				if(a[z][3]==a[j][1])
				{
				num++;z=j;
				}
			}
		}
		if(num>max)
		{
			max=num;
			first_x=a[i][0];first_y=a[i][1];
		}
	}
	printf("%d %d %d\n",max+1,first_x,first_y);
	return 0;
	
}
void replace(int a[100][4],int n,int temp[4])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(int k=0;k<4;k++)temp[k]=a[i][k];
				for(int k=0;k<4;k++)a[i][k]=a[j][k];
				for(int k=0;k<4;k++)a[j][k]=temp[k];
			}
		}
	}
}
