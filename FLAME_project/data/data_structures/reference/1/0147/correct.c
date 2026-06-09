#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 11
int Mark[MAX]={0};
char Stack[MAX];
int N;
void rank(int m,int n)
{
	int i,j;
	if(n==0)
	{
		Stack[m]='\0';
		printf("%c",Stack[0]);
		for(j=1;j<m;j++)
		printf(" %c",Stack[j]);
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++)
	{
		if(Mark[i]==0)
		{
			Mark[i]=1;
			Stack[m]='0'+i;
			rank(m+1,n-1);
			Mark[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&N);
	rank(0,N);
	return 0;
}



