#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
int n,num[20];
bool used[20];
void dfs(int x)
{
	int i;
	if(x>=n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
		return;
	}
	for(i=0;i<n;i++)
	{
		if(!used[i])
		{
			num[x] = i+1;
			used[i] = true;
			dfs(x+1);
			num[x] = 0;
			used[i] = false;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	used[i]=false;
	dfs(0);
	return 0;
}


