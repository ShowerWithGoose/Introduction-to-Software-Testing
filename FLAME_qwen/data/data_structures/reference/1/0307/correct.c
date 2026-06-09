#include <stdio.h>
int n,a[111],b[111];
 void g()
 {
	int i;
	for(i=0;i<=n-2;i++)
	printf("%d ",b[i]);
	printf("%d\n",b[i]);
 }
 void f(int c)
 {
	int i;
	if(c==n) g();
	else
	{
		for(i=0;i<=n-1;i++)
		{
			if(a[i]==0)
			{
				b[c]=i+1; a[i]=1;
				f(c+1);
				a[i]=0;
			}
		}
	}
 }
int main()
{
	scanf("%d",&n);
	f(0);
	return 0;
} 

