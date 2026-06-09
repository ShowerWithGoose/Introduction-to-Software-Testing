#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
int a[12],b[12],n;
void d(int s)
{
	if(s==n+1)
    {
    int j;	
	for(j=1;j<=n;j++)
		printf("%d ",a[j]);
	printf("\n");
	return;
	}	
	int i;
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[s]=i;
			b[i]=1;
			d(s+1);
			b[i]=0;
		}
	}
}
int main()
{
	
	scanf("%d",&n);
	d(1);
	return 0;
}





