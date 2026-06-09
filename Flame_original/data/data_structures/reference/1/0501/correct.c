#include<stdio.h>
#include<stdlib.h>
int n,i,k;
int a[12];
void putdown(int a[])
{
	int l;
	for(l=1;l<n;l++)
	printf("%d ",a[l]);
	printf("%d",a[n]);
	printf("\n");
	return;
}
void leftswap(int beginning,int j)
{
	int target,l;
	target=a[j];
	for(l=j;l>beginning;l--)
	{
		a[l]=a[l-1];//后退一位 
	}
	a[beginning]=target;
}
void rightswap(int beginning,int j)
{
	int target,l;
	target=a[beginning];
	for(l=beginning;l<j;l++)
	{
		a[l]=a[l+1];//回复一位 
	}
	a[j]=target;
}
void arrange(int beginning,int len)
{
	int j,k,temp;
	if(len==1)
	{putdown(a);return;}//最后一项的情况 
	for(j=0;j<len;j++)//使首项和其后每一项分别交换，获得以每个数为首项的全排列 
	{
		leftswap(beginning,beginning+j);
		arrange(beginning+1,len-1);//递归，处理第二项、第三项......开始的全排列 ，一直到最后一项 
		rightswap(beginning,beginning+j);
	}
 } 
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) a[i]=i;
	arrange(1,n);	
	return 0;
 } 



