#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void x(int *a, int n) ;
int arrange(int *a, int n, int cur) ;
int main() {
	int N;
	scanf("%d", &N);
	int *a=(int *)malloc(N * sizeof(int)); 
	arrange(a, N, 0);
	return 0;
}
int arrange(int *a, int n, int cur) { 
	int i,j ;
	if(cur == n) {
		x(a, n);
	} else {
		for(i = 1; i <= n; i++) { 
			int ok = 1;
			for(j = 0; j < cur; j++) { 
				if(a[j] == i) {
					ok = 0;
					break;
				}
			}
			if(ok) {
			a[cur] = i;
				arrange(a, n, cur + 1);
			}
		}
	}
}
void x(int *a, int n) { 
	int i;
	for(i = 0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

