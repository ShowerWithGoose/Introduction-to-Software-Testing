
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
 
void Print(int*a, int n) {
	int i ; 
	for ( i = 1; i <= n; i++) {
		if (i == n)	printf("%d\n", a[i]);
		else printf("%d ", a[i]);
	}
}
void perm(int*a, int*b,int n,int Index) {
	int i;
	if (Index== n+1) {
		static int cnt = 0;
		Print(a, n);
		return;
	}
	for ( i = 1; i <= n; i++) {
		if (!b[i]) {
			a[Index] = i;
			b[i] = 1;
			perm(a, b, n, Index + 1);
			b[i] = 0;
		}
	}
	return;
}
int main() {
	int n;
	int a[51], b[51] = { 0 };

	scanf("%d", &n);

	perm(a, b, n, 1);
	return 0;
}




