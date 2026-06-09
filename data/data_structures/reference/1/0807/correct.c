#include <stdio.h>
int N;//N为要排列的最大数 
int a[10];
int jie(int m)//算阶乘
{
	if(m==0)
return 1;
    else
return m*jie(m-1);
}
void prn()//打印一行全排列的数列 ,且自动换行 
{
	int i;
	for(i=0;i<N-1;i++)
	printf("%d ",a[i]);
	printf("%d\n",a[i]);
}
void change()//开始换数组 
{
	int i,j,k,tmin,mid;
	for(i=N-2;i>=0;i--)
	{
		if(a[i]<a[i+1])
		break;//从最右找到第一个按自然序排列的a[i]，并在右边比它大的数中找最小的数，它俩位置互换 
	}
	tmin=i+1;
	k=i;
	for(j=i+1;j<=N-1;j++)
	{
		if(a[j]>a[i]&&a[j]<a[tmin])
		tmin=j;
	}
	mid = a[i];
	a[i] = a[tmin];
	a[tmin] = mid;
	for(j=k+1,i=N-1;i>j;i--,j++)
	{
		mid=a[i];
		a[i]=a[j];
		a[j]=mid;
	}
}
int main()
{
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		a[i]=i+1;
	}
	prn();
	for(i=1;i<jie(N);i++)
	{
		change();
		prn();
	}
return 0;
 } 

