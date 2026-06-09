#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXLINE 1024
#define eps 1e-15

int a[11],b[11],judge[11],n;
void DFS(int );

int main()
{  
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		a[i] = i+1;
	
	DFS(0);
	
	return 0;
}
void DFS(int l)
{
	int j,m;
	if(l == n)
	{
		for( m = 0 ;m < n; m++)
			printf("%d ",b[m]);
		printf("\n");
		return ;
	}
	for(j = 0;j < n;j++)
	{
		if(judge[j] == 0)
		{
			b[l] = a[j];
			judge[j] = 1;
			DFS(l+1);
			judge[j] = 0;
		}
	}
}

