#include<stdio.h>
void permutation(int m,int n,int a[],int temp[]) //数组temp用于标记，arr用于储存全排列 
{
	int i;
	if(m>=n)//打印全排列 
	{
		for(i=0;i<=n-2;i++)
		printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	else
	for(i=0;i<=n-1;i++)//逐一生成全排列 
    {
        if(temp[i]==0)
		{
			temp[i]=1;
			a[m]=i+1;
			permutation(m+1,n,a,temp);//递归到下一层 
			temp[i]=0;
		}	
	}
}
int main ()
{
	int n,a[20],temp[20];
	int i;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
		temp[i]=0;
    permutation(0,n,a,temp);
    return 0;	
}

