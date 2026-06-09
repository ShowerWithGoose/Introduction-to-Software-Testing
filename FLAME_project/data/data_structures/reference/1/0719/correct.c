#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
int ans[50];
int b[50];
void allPermutation(int m,int n);//m――当前排到了第几位；n――到n的全排列 

int main()
{
	int n;
	scanf("%d",&n);
	allPermutation(1,n);
	return 0;
}

void allPermutation(int m,int n)
{
	int i;
	if(m==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			ans[m]=i;
			b[i]=1;
			allPermutation(m+1,n);
			b[i]=0;
		}
	}
	return;
}



