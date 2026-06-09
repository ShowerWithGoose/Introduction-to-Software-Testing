#include<stdio.h>
#include<string.h>
int num[11]={0};
char stack[11]="";
int N;
void f(int m,int n);
int main()
{
	scanf("%d",&N);
	f(0,N);
	return 0;
}
void f(int m,int n)
{
	int i=0,j=0;
	if(n==0)
	{
		for(j=0;j<m;j++)
		{
			printf("%c ",stack[j]);
		}
		printf("\n");
		return;
	} 
	for(i=1;i<=N;i++)
	{
		if(num[i]==0)
		{
			num[i]=1;
			stack[m]='0'+i;
			f(m+1,n-1);
			num[i]=0;
		}
	}
	return;
} 


