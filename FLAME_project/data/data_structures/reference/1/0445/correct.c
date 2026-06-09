#include <stdio.h>
int a[20]; 
int n;
void insert(int u, int v) {
	int re = a[v];
	for (int i = v - 1; u <= i; i--) a[i + 1] = a[i];
	a[u] = re;
	return;
}
void reinsert(int u, int v) {
	int re = a[u];
	for (int i = u + 1; i <= v; i++) a[i - 1] = a[i];
	a[v] = re;
	return;
} 
void arrange(int lo, int hi) {
	if (hi - lo == 1) {
		for (int i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = lo; i < hi; i++) {
//		for (int j = lo; j < hi; j++) a[j] = com[j];
		insert(lo, i);
		arrange(lo + 1, hi);
		reinsert(lo, i);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) a[i] = i + 1;
	arrange(0, n);
	return 0; 
} 



