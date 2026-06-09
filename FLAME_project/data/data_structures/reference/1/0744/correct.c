#include<stdio.h>
#include<string.h>
int n;//排列数
char a[30]={0};//存放排列得数
int f[19];//记录每个数得个数 
 
void dfs(int t)
{
	if(t==n+1)puts(a);//递归得终止条件
	int j; 
	for( j=1;j<=n;j++)
	{
		if(f[j]>0)
		{
			a[2*t-2]=j+'0';                   //开始存
			f[j]--;//消耗掉了一个
			dfs(t+1);//开始存下一个
			f[j]++;//回收资源 
		}
	 } 
}
int main()
{
	scanf("%d",&n);
	int k=0;
     for(k=0;k<30;k++)a[k]=' ';
	int i;
	for( i=1;i<=n;i++)f[i]=1;
	dfs(1);
	
	return 0;
 } 



