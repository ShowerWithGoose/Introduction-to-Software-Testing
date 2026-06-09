#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void dayin(int *,int );
void pailie(int *,int *,int,int);

int main()
{
int n;
scanf("%d",&n);
int a[15]={},b[15]={};
pailie(a,b,n,1);
return 0;
}

void dayin(int *a,int n)
{
	int i; 
	for(i=1;i<=n;i++)
	{
		if(i==n) printf("%d\n",a[i]);
		else printf("%d ",a[i]);
	}
}//这是打印格式，最后一个（等于n的时候）就打出来然后加换行符，不是最后一个就只打印数 

void pailie(int *a,int *b,int n,int c)
{
	int i=1;
	if(c==n+1)
	{
		dayin(a,n);
		return ;//不懂return到哪了 
	}//如果c等于n+1就开始打印，n+1是个固定的数，c每循环一次就会加一 
	for(i=1;i<=n;i++)
	{
		if(!b[i])//b[i]初始化为0，非0为1，满足判断要求 
		{
			a[c]=i;//第一遍让a[1]=i=1 
			b[i]=1;//第一遍b[1]=1 
			pailie(a,b,n,c+1);//进入递归数列 此时c=2，a[1]=1，b[1]=1，不进if，i=2，进if，a[2]=2，b[2]=1，再递归以此类推直到进上面的if打印完一整行； 
			b[i]=0;
		}
	}
	return;
}
//自己真的没有思路，看了网上的代码
 











