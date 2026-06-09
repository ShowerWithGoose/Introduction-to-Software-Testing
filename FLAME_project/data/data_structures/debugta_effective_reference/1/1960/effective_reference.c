#include <stdio.h>
int b[10],a[10],n;
void f(int k)
{
	int i; 
	if (k>n)
	{
		for (i=1;i<n;++i)
		printf("%d ",b[i]);
		printf ("%d\n",b[n]);
		return ;
	}
	else {
		for (i=1;i<=n;++i)
		{
			if (!a[i])
			{
				b[k]=i;a[i]=1; 
				f(k+1);
				b[k]=0;a[i]=0; 
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



