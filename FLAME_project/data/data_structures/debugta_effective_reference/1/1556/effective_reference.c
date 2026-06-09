#include <stdio.h>
#define MAX 11
int mark[MAX]={0};
char stack[MAX]; 
void rank(int m,int n);
int N;
int main()
{
	scanf("%d",&N);
	rank(0,N);
	return 0;
}
void rank(int m,int n)
{
	int i,k;
	if(n==0){
		stack[m]='\0';
		for(k=0;stack[k]!='\0';k++)
		printf("%c ",stack[k]);
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++)
	     if(mark[i]==0){
	     	mark[i]=1;
	     	stack[m]='0'+i;
	     	rank(m+1,n-1);
	     	mark[i]=0;
		 }
}






