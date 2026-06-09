#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


int n;
void dfs(int);
int tail=1;
int num[10000];
int book[10000];

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
	
}
void dfs(int k)
{
	int i;
	if(k==(n+1))
	{
		for(i=1;i<=n;i++)
		{
			printf("%d ",num[i]);
		}
		putchar('\n');
		return;
	}
	
	for(i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i] = 1;
			num[tail] = i;
			tail++; 
			dfs(k+1);
			tail--;
			book[i] = 0;
		}
	}
}



