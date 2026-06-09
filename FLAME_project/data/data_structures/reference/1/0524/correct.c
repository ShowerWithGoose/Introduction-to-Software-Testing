#include<stdio.h>
int a[15]={0},b[15]={0},n;
void f(int c)
{
	int i;
	if(c==n)
	{
		for(i=0;i<n;i++)
		printf("%d ",b[i]);
		putchar('\n');
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			b[c]=i;
			a[i]=1;
			f(c+1);
		    a[i]=0;
		}
	}
}	
int main()
{
	scanf("%d",&n);
	f(0);
	return 0;
}

