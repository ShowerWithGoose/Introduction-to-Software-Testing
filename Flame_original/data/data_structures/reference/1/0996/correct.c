#include<stdio.h>
#include<math.h>
#include<string.h>
#define max 11
int mark[max]={0};
int N;
char mark1[max];
void rank(int m,int n)
{
	int i;
	if(n==0)
	{
		mark1[m]='\0';
		for(i=0;i<N;i++)
		printf("%c ",mark1[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++)
	{
		if(mark[i]==0)
		{
			mark[i]=1;
			mark1[m]=i+'0';
			rank(m+1,n-1);
			mark[i]=0;
		}
	}
 } 
int main()
{
	scanf("%d",&N);
	rank(0,N);
	return 0;
}


