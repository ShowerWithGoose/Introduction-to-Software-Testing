#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int n,m;
int str[15],temp[15];

void quanpailie(int m,int n,int str[],int temp[] );
int main()
{
	int n,i,j;
	scanf("%d",&n);
	quanpailie(0,n,str,temp) ;
	return 0;
 }
 void quanpailie(int m,int n,int str[],int temp[] )
{
	if(m>=n)//当排列时 M位到了最后一位 执行输出 
	{
		for( int i=0;i<=n-2;i++)
		{
			printf("%d ",str[i]);
		}
		printf("%d\n",str[n-1]);
	}
	else 
	{
	 for(int i=0;i<n;i++)//对m位不断试1-n的数据，有n种数据情况 
	 {
	 	if(temp[i]==0)//判断该位的数字在其他位是否已经使用 
	 	{  
		 	str[m]=i+1; //让m位占有i+1数据 
	 		temp[i]=1;// 标记i+1这一数据已使用 
	 	    quanpailie(m+1,n,str,temp);//递归到后一位的全排列，从m+1 位开始的排列 
	 		temp[i]=0;//防止在其他排列中 i+1数据不可用 
	    }
	 }
	}
} 



