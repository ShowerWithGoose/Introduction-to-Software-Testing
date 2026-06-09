#include <stdio.h>
int a[10],b[10],n;
void f(int k)
{
	int i; 
	if (k>n)
	{
		for (i=1;i<n;++i)
		printf("%d ",a[i]);
		printf ("%d\n",a[n]);
		return ;
	}
	else {
		for (i=1;i<=n;++i)
		{
			if (!b[i])
			{
				a[k]=i;b[i]=1; 
				f(k+1);
				a[k]=0;b[i]=0; 
			}
		}
	}
}
int main ()
{
	scanf ("%d",&n);
	f(1);
	return 0;	
}



