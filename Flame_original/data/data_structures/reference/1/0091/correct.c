#include<stdio.h>
void permutation(int m,int N,int arr[],int temp[]) //数组temp用于标记，arr用于储存全排列 
{
	int i;
	if(m>=N)//打印全排列 
	{
		for(i=0;i<=N-2;i++)
		printf("%d ",arr[i]);
		printf("%d\n",arr[i]);
	}
	else
	for(i=0;i<=N-1;i++)//逐一生成全排列 
    {
        if(temp[i]==0)
		{
			temp[i]=1;
			arr[m]=i+1;
			permutation(m+1,N,arr,temp);//递归到下一层 
			temp[i]=0;
		}	
	}
}
int main ()
{
	int N,arr[20],temp[20];
	int i;
	scanf("%d",&N);
	for(i=0;i<=N-1;i++)
		temp[i]=0;
    permutation(0,N,arr,temp);
    return 0;	
}

