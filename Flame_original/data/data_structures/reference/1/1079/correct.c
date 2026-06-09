#include <stdio.h>


int n, ans[12] = {0}, hashtable[12] = {0};

void generate(int index) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {

			printf("%d ", ans[i]);
		}

		printf("\n");
		return;
	}

	for (int j = 1; j <= n; j++) {

		if (hashtable[j] == 0) {
			ans[index] = j;
			hashtable[j] = 1;
			generate(index + 1);
			hashtable[j] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	generate(1);

	return 0;
}



