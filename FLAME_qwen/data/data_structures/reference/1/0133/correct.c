#include<stdio.h>
int a[100]= {0};
int b[100]= {0};
int N;
void f(int N,int book,int *a,int *b);
int main() {
	scanf("%d",&N);
	f(N,1,a,b);
	return 0;
}
void f(int N,int book,int *a,int *b) {
	int i;
	if(book==N+1) {
		for(i=1; i<=N; i++) {
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for(i=1; i<=N; i++) {
		if(b[i]==0) {
			b[i]=1;
			a[book]=i;
			f(N,book+1,a,b);
			b[i]=0;
		}
	}
}




