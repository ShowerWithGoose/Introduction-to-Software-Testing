#include<stdio.h>
int MARK[11]={0};
char Stack[11];
void rank(int m,int n);
int main()
{
 	int N;
	scanf("%d",&N);
	rank(0,N);
	return 0;
}
void rank(int m,int n)
{
	int i;
	if(n==0)
	{
		for(i=0;i<m;i++)
		{
			if(i>0)
				printf(" %c",Stack[i]);
			else
				printf("%c",Stack[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n+m;i++)
	{
		if(MARK[i]==0)
		{
			MARK[i]=1;
			Stack[m]='0'+i;
			rank(m+1,n-1);
			MARK[i]=0;
		}
	}
}



