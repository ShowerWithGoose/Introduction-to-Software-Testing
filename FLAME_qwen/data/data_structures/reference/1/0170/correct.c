#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int record[11]={0};
int result[11];
int N;
void maze(int);
int main()
{
	scanf("%d",&N);
	maze(N);
	
	return 0;
}
void maze(int n)
{
	int i,j;
	if(n==0){
		for(j=0;j<N;j++){
			printf("%d ",result[j]);
		}
		printf("\n");
		return;
	}
	for(i=0;i<N;i++){
		if(record[i]==0){
			record[i]=1;
			result[N-n]=i+1;
			maze(n-1);
			record[i]=0;
		}
	}
}

