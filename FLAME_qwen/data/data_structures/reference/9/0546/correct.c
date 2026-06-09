#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100][5];
int f(int a[100][5],int n,int i);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	int max=0,j=0;
	for(int i=0;i<=n-1;i++)
	if(f(a,n,i)>max)
	{
		j=i,max=f(a,n,i);
	}
	printf("%d %d %d",max,a[j][0],a[j][1]);
	return 0;
}
int f(int a[100][5],int n,int i)
{
	int sum=1,j=i;
	a[i][4]=1;
	for(int k=0;k<n;k++)
	{
		if(a[k][4]==1)
		continue;
		else
		{
			if((a[j][2]==a[k][0])&&(a[j][3]==a[k][1]))
			{
				sum++;
				a[k][4]=1;
//				printf("\n!%d %d %d %d!%d",a[j][0],a[j][1],a[j][2],a[j][3],j);
//				printf("%d %d\n",j,k);
				j=k;
				k=-1;
			}
		}
//		printf("@\n");
	}
	for(int k=0;k<=n-1;k++)
	a[k][4]=0;
	return sum;
//	printf("%d\n",sum);
}



