#include<stdio.h>
#include<math.h>
#include<string.h>
int a[10],b[10],v[10];
int pailie(int ,int );
int main()
{
	int num,i,j,k,n;
	scanf("%d",&num);
	for(i=0;i<num;i++) a[i]=i+1;
	n=0;//n表示进入全排列的个数
	pailie(n,num); 
    return 0;
}
int pailie(int n,int num)
{
	int j,k;
	if(n==num)
	{
		for(j=0;j<num;j++) printf("%d ",b[j]);
		printf("\n");
	}
	else
	{
		for(j=0;j<num;j++)
		{
			if(v[j]==0)
			{
				b[n]=a[j];
				v[j]=1;
				pailie(n+1,num);//递归 
				v[j]=0;//回溯 
			}
		}
	}
} 

