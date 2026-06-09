#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
int a[15],n;

void print()
{
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}

int search(int key,int len)
{
	for(int i=0;i<len;i++) 
	{
		if(key==a[i]) return 1;
	}
	return 0;
}

void dfs(int len)
{
	if(len==n)
	{
		print();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(search(i,len)==0)
		{
			a[len]=i;
			dfs(len+1);
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(0);
	return 0;	
}



