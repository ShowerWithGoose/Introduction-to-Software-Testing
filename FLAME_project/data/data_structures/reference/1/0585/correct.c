#include<stdio.h>
int a[10] ;
int flag[10];
int n;
void f(int i) {
	int k;
	if(i!=n) {
		for( k=0; k<n; k++) {
			if(!flag[k]) {
				a[i]=k+1;
				flag[k]=1;
				f(i+1);
				flag[k]=0;
			}
		}
	} else {
		for(int j=0; j<n; j++) {
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}
int main() {
	int i=0;
	scanf("%d",&n);
	for( i=0; i<n; i++) {
		flag[i]=0;
	}
	f(0);
	return 0;
}




