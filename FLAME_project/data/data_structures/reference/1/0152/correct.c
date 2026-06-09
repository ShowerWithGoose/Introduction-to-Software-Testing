#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int a[15];//存阶乘 
int i,j,n;
int b[15];//存1到10
int jiecheng()
{
	a[0]=1;
	for(i=1;i<=10;i++)
	{
		a[i]=i*a[i-1];
	}
 } 
void shuchu()
{   
    int i=0;
	for(i=0;i<n-1;i++)
	printf("%d ",b[i]);
	printf("%d\n",b[n-1]);
}
void caozuo()
{	
	
	int m,q,t;
	
	for(i=n-2;i>=0;i--)
	{
		if(b[i]<b[i+1])
			{
			break;}//找到第一个比后面小的数所在位置 
	}
	m=i;
	for(i=m+1;i<n;i++)
	{
		if(b[i]>b[m])
		q=i;//n是后面比b[m]大的数中最小的数 
	}
	t=b[m];
	b[m]=b[q];
	b[q]=t;//两者互换位置
	for(j=m+1,i=n-1;i>j;i--,j++)
	{
		t=b[j];
		b[j]=b[i];
		b[i]=t;
	 } 

	
}
int main()
{
	scanf("%d",&n);
	int p;
	jiecheng();
	for(p=0;p<n;p++)
	b[p]=p+1;
	shuchu();
	for(p=1;p<a[n];p++)
	{
		
		caozuo();
		shuchu();
		
	}

	return 0;
	
}


