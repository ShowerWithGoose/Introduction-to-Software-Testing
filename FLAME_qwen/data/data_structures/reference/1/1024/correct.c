#include<stdio.h>
#define MAX 11
int Mark[MAX]={0},N;
char Stack[MAX];
void rank(int m,int n){
	int i,j=0;
	if(n==0){
		Stack[m]='\0';
		for(j=0;j<N;j++){
			printf("%c ",Stack[j]);	
		}
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++){
		if(Mark[i]==0){
			Mark[i]=1;
			Stack[m]='0'+i;
			rank(m+1,n-1);
			Mark[i] = 0;
		}
	}
}
int main(){
	int m,n;
	scanf("%d",&N);
	n=N;
	m=0;
	rank(m,n);
}

