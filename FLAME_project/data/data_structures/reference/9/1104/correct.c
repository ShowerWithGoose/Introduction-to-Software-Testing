#include<stdio.h>
int rng(int a[100][4],int n,int b[4])
{
	int i=0,j=0,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				for(k=0;k<4;k++)
				{
					b[k]=a[i][k];
				}
				for(k=0;k<4;k++)
				{
					a[i][k]=a[j][k];
				}
				for(k=0;k<4;k++)
				{
					a[j][k]=b[k];
				}
			}
		}
	}
}
int main()
{
	int n,a[100][4],b[4],num,i,j,t,x,e,f;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
        scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	rng(a,n,b);
	for(i=0;i<n;i++)
	{
		num=0;
		t=i;
		for(j=i+1;j<n;j++)
		{
			if(a[t][2]==a[j][0]&&a[t][3]==a[j][1])
			{
				num++;
				t=j;
			}
		}
		if(num>x)
		{
			x=num;
			e=a[i][0];
			f=a[i][1];
		}
	}
	printf("%d %d %d",x+1,e,f);
	return 0;
}


