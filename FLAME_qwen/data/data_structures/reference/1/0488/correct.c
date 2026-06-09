#include<stdio.h>
#include<string.h>

int h[11],N,num[11];
void print(int n);

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		h[i]=1;
	print(N);
	return 0;
}

void print(int n){
	int i,j;
	if(n==0){
		for(int j=1;j<=N;j++)
			printf("%d ",num[j]);
		printf("\n");
		return;
	}
	for(i=1;i<=N;i++){
		if(h[i]){
			h[i]=0;
			num[N-n+1]=i;
			print(n-1);
			h[i]=1;
		}
	}
	
}



