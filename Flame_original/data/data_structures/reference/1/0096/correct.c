#include<stdio.h>
#define max 11
int mark[max]={0};
char stack[max];
int N;

void rank(int m,int n){
	int i,j;
	if(n==0){
		stack[m]='\0';
		for(j=0;j<N;j++){
			printf("%c ",stack[j]);
		}
		printf("\n");
	//	puts(stack);
		return;
	}
	for(i=1;i<=N;i++){
		if(mark[i]==0){
			mark[i]=1;
			stack[m]='0'+i;
			rank(m+1,n-1);
			mark[i]=0;
		}
	}
}

int main(){
	scanf("%d",&N);
	rank(0,N);
	return 0;
}

