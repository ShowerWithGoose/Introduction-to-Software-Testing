#include<stdio.h>
int lx[101],ly[101],rx[101],ry[101];
int look_up(int a[],int b[],int c[],int d[],int i,int m,int x)
{
	int n=0;
	for(n=0;n<m;n++)
	{
		if(d[i]==b[n]&&c[i]==a[n])
		{
			return look_up(a,b,c,d,n,m,x+1);
		}
	}
	return x;
}
int main()
{
	int a,i,n;
	int js=1;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d%d%d%d",&lx[i],&ly[i],&rx[i],&ry[i]);
	}
	int temp=lx[0];
	int flag=0;
	for(i=0;i<a;i++)
	{
		look_up(lx,ly,rx,ry,i,a,0);
		if(js<=look_up(lx,ly,rx,ry,i,a,1))
		{
			js=look_up(lx,ly,rx,ry,i,a,1);
			flag=i;
		}
	}
    
   printf("%d %d %d",js,lx[flag],ly[flag]);

 } 

