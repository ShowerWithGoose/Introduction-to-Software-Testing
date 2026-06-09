#include <stdio.h>
int mark[100] = {0};
char putl[201];
void putll(int m, int n);
int N;
int main() {
	scanf("%d", &N);
	putll(0, N);
	return 0;
}
void putll(int m, int n) {
	int i;
	if (n == 0) {
		putl[2*N-1]='\0';
		puts(putl);
		return;
	}
	for (i = 1; i <= N; i++) {
		if (mark[i] == 1) {
			continue;
		}
		mark[i] = 1;
		putl[2 * m] = '0' + i;
		putl[2 * m+1] = ' ';
		putll(m + 1, n - 1);
		mark[i]=0;
	}
	return ;
}



