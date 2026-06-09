#include <stdio.h>
int book[12]={0},re[12]={0},n;
long long num=1;
void dfs(int);
long long large(int);

int main()
{
	int i,j,k;
	scanf("%d",&n);
	

	dfs(1);
	
	return 0;
}

void dfs(int a)
{
	int i,k;
	if(a==n+1)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",re[i]);
			if(i<n) 
			printf(" ");
			
			else 
			{
				if(num!=large(n))
				printf("\n");
				num++;
			}
		}
		return ;
	}
	else
	{
		for(i=1;i<=n;i++)		
			if(book[i]==0)
			{
				re[a]=i;
				book[i]=1;
				dfs(a+1);
				book[i]=0;
			}		
	}
	return ;
	
}

long long large(int a)
{
	long long sum=1;
	while(a>0)
	{
		sum*=a;
		a--;
	}
	return sum;
}



