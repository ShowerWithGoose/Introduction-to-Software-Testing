#include <stdio.h>
int a[10],pd[10],n;
void pl(int k)
{
	int i;
	if (k>n)
	{
		for(i=1;i<n;++i)
		  printf("%d ",a[i]);
		  printf ("%d\n",a[n]);
	}
	else 
	{
		for (i=1;i<=n;++i)
		{
			if(pd[i]!=1)
			{
				a[k]=i;
				pd[i]=1;
				pl(k+1);
				a[k]=0;
				pd[i]=0;
			}
		}
	}
}
int main ()
{
	scanf ("%d",&n);
	pl(1);
	return 0;	
}
