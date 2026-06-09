#include<stdio.h>
#define MAX 11
int Mark[MAX]={0};
char Stark[MAX];
void rank(int m,int n,int N);
void rank(int m,int n,int N){
	int i;
	if(n==0)
	{
		Stark[m]='\0';
		for(i=0;i<N;i++){
			printf("%c ",Stark[i] );
		}
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++)
	{
		if(Mark[i]==0)
		{
			Mark[i]=1;
			Stark[m]='0'+i;
			rank(m+1,n-1,N);
			Mark[i]=0;
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	rank(0,N,N);
}


