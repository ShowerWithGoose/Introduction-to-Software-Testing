#include<stdio.h>
int n;
int a[100],book[100];
void printpai(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			a[x]=i;
			printpai(x+1);
			book[i]=0;
		}
	}
	
}

int main()
{
	scanf("%d",&n);
	printpai(1);
	
}

