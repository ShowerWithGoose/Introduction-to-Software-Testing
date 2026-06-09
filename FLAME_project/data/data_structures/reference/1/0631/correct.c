#include<stdio.h>
#include<string.h>
int row[11];
void organize(int line[], int n,int m) 
{
	int i,j;
	if(m==n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d",line[i]);
			if(i!=n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
		return;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(line[j]==i)
				{
					break;
				}
			}
			if(j==m)
			{
				line[j]=i;
				organize(line,n,m+1);
			}
		}
		return;
	}	
} 
int main()
{
	int n;
	scanf("%d",&n);
	organize(row,n,0);
	return 0;
}







