#include <stdio.h>
int hash[10]={1,2,3,4,5,6,7,8,9,10};
int storey[10];
int flag[10]={0};
int n;
int top=0;
void fullperm(int m)
{
	if(m==n)
	{
		for (int i=0; i<n; i++)
			printf("%d ",storey[i]);
		printf("\n");
	}
	else
	{
		for (int i=0; i<n;i++ )
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				storey[top++]=hash[i];
				fullperm(m+1);
				top--;
				flag[i]=0;
			}
		}
	}
}
int main() 
{
	scanf("%d",&n);
	fullperm(0);
	return 0;
}


