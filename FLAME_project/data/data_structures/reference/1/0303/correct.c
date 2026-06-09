#include <stdio.h>

int F[11];

int A[11];

void full(int n, int i){
	if(i > n){
		for(int j=1; j<=n; j++){
			printf("%d ", A[j]);
		}
		printf("\n");
		return ;
	}
	
	for(int j=1; j<=n; j++)
		if(!F[j]){
			F[j] = 1;
			A[i] = j;
			full(n, i+1);
			F[j] = 0;
		}
	
}

int main(){
	int N;
	scanf("%d", &N);
	full(N, 1);
	return 0;
}

