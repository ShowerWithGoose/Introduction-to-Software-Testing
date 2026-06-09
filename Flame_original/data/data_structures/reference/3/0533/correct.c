#include <stdio.h>

int main() {
	char left[105] = {0};
	int right[105] = {0};
	int l = 0, r = 0, r1 = 0;
	char flag = 1;

	while (scanf("%c", &left[++l]) != EOF) {

		if (left[l] == '.') {
			l--;
			break;
		}
		if (left[l] == '\r' || left[l] == '\n') {
			l--;
			break;
		}
	}

	if (l == 1 && left[1] == '0') {
		flag = '-';
	}
	if (l == 1 && left[1] != '0') {
		flag = '0';
	}

	int go = 1;
	while (scanf("%1d", &right[++r]) != EOF ) {
		if (right[r] == 0 && go == 1)
			;
		if (go == 1 && right[r] != 0) {
			r1 = r;
			go = 0;
		}
		if (right[r] == '\r' || right[r] == '\n')
			break;
	}

	r--;

	if (flag == '-') {
		printf("%d", right[r1]);
		if (r1 == r) {
			printf("e-%d", r1);
		} else {
			printf(".");
			for (int j = r1 + 1; j <= r; j++)
				printf("%d", right[j]);
			printf("e-%d", r1);
		}
	} else if (flag == '0') {
		printf("%c", left[1]);
		if (r1 == 0) {
			printf("e0");
		} else {
			printf(".");
			for (int i = 1; i <= r; i++)
				printf("%d", right[i]);
			printf("e0");
		}
	} else {
		printf("%c.", left[1]);
		for (int i = 2; i <= l; i++)
			printf("%c", left[i]);
		for (int i = 1; i <= r; i++)
			printf("%d", right[i]);
		printf("e%d", l - 1);  //????????
	}
	return 0;
}

