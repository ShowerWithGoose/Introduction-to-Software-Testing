#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash[11],n,num[10];

void function(int x)
{
	if(x==0)
	{
		for(int i=0;i<n;i++)
			printf("%d ",num[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(hash[i])
			continue;
		hash[i]=1;
		num[n-x]=i;
		function(x-1);
		hash[i]=0;
	}
}

int main()
{
	scanf("%d",&n);
	function(n);
	return 0;
}

