#include <stdio.h>
int S[105];
void prin() {
	int a, b;
	int i = -1;
	while(scanf("%d", &a)) {
		if (a == -1) break;
		else if (a == 0) {
			if (i == -1) printf("error ");
			else {
				printf("%d ", S[i]);
				i--;
			}
		}
		else if (a == 1) {
			scanf("%d", &b);
			if (i == 100) printf("error ");
			else S[++i] = b;
		}
	}
	return;
}
int main() {
	prin();
	return 0;
}

