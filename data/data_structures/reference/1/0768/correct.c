#include<stdio.h>
int flag[25],a[25],b[25],n,x;
void f(int t);
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		a[i]=1+i,flag[i]=1;
	x=0;f(0);
	return 0;
}
void f(int t)
{
	for(int i=0;i<n;i++)
		if(flag[i])
		{
			flag[i]=0;b[x]=a[i];x++;
			f(t+1);
			x--;flag[i]=1;
		}
	if(t==n)
	{
		for(int i=0;i<n;i++)
			printf("%d ",b[i]);
		putchar('\n');
	}
}
