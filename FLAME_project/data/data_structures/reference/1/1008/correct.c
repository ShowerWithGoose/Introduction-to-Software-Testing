#include<stdio.h>
int Mark[15] = {0};
int a[15];
void rank(int m, int n);
int N;
int main(){
	scanf("%d",&N);
	rank(0, N);
	return 0;
}
void rank(int m, int n){
	int i, j;
	if(0 == n){
		for(j = 0; j < m; j++)
			printf("%d ", a[j]);
		printf("\n");
	}
	for(i = 1; i <= N; i++){
		if(Mark[i] == 0){
			Mark[i] = 1;
			a[m] = i;
			rank(m+1,n-1);
			Mark[i] = 0;
		}
	}
}

