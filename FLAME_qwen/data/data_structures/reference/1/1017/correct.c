#include<stdio.h>
void rank(int m,int n,int N);
char stack[11];
int mark[11]={0};
void rank(int m,int n,int N){
	int i;
	if(n==0){
		stack[m]='\0';
		for(int e=0;e<N-1;e++){
			printf("%c ",stack[e]);
		}
		printf("%c\n",stack[N-1]);
		return;
	}
	for(i=1;i<=N;i++){
		if(mark[i]==0){
			mark[i]=1;
			stack[m]='0'+i;
			rank(m+1,n-1,N);
			mark[i]=0;
		}
	}
} 

int main(){
	int n,m=0,N;
	scanf("%d",&n);
	N=n;
	rank(m,n,N);
	return 0;
}




