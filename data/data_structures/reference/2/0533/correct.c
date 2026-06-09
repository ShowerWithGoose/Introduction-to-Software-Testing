#include <stdio.h>
#include <string.h>

int main(void) {
	char a[10000] = {0};
	int i = 0;
	gets(a);


	for ( i = 0; i < strlen(a) - 1; i++ ) {
		if (a[i] == ' ') {
			int j;
			for (j = i; j <= strlen(a) - 2; j++) {
				a[j] = a[j + 1];
			}
			a[j] = 0;
			i--;
		}
	}
	if (a[i] == ' ')
		a[i] = 0; //space cut

	int b[10000] = {0};
	int left = 0, right = -1, j = 0;
	for (i = 0; i <= strlen(a) - 1; i++) {
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '=') {
			left = right + 1;
			right = i;
			int num = 0;
			for (int k = left; k <= right - 1; k++) {
				num = num * 10 + a[k] - '0';
			}
			b[j++] = num;
			b[j++] = -a[i];//b[j]已经指向下一个了 符号ascii取负值
		}
	}			//digit combine
	j--;

	for (i = 0; i <= j; i++) {
		if (b[i] == -'/' || b[i] == -'*') {
			if (b[i] == -'*') {
				b[i - 1] = b[i - 1] * b[i + 1];
			} else {
				b[i - 1] = b[i - 1] / b[i + 1];
			}
			for (int y = i; y <= j - 2; y++) {
				b[y] = b[y + 2];
			}
			b[j - 1] = b[j - 2] = 0;
			j -= 2;
			i--;
		}
	}

	for (i = 0; i <= j; i++) {
		if (b[i] == -'+' || b[i] == -'-') {
			if (b[i] == -'+') {
				b[i - 1] = b[i - 1] + b[i + 1];
			} else {
				b[i - 1] = b[i - 1] - b[i + 1];
			}
			for (int y = i; y <= j - 2; y++) {
				b[y] = b[y + 2];
			}
			j -= 2;
			i--;
		}
	}



	for (int x = 0; x <= j - 1; x++)
		printf("%d ", b[x]);

	return 0;
}

