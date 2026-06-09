#include<stdio.h>
#include<string.h>
int main()
{
	int a[105][4],b[4]={0},i,j,k,n,max=1,num,x,y,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j][0]<a[i][0])
			{
				for(k=0;k<4;k++)
				{
					b[k]=a[j][k];
					a[j][k]=a[i][k];
					a[i][k]=b[k];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		z=i;
		num=1;
		for(j=i+1;j<n;j++)
		{
			if(a[j][0]==a[z][2]&&a[j][1]==a[z][3])
			{
				num++;
				z=j;
			}
		}
		if(num>max)
		{
			max=num;
			x=a[i][0];
			y=a[i][1];
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

