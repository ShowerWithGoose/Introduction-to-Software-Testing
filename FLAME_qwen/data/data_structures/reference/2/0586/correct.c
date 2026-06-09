#include <stdio.h>
#include <string.h>
char str_a[1000000];
char str_b[1000000];
char str_d[1000000];
int str_c[1000000];

int main() {

	int i, j, len, a, ic, id, ia, ib, num;
	gets(str_a);
	len = strlen(str_a);
	len -= 1;
	for (i = 0, j = 0; i < len; i++) {
		if (str_a[i] != ' ') {
			str_b[j] = str_a[i];
			j++;
		}
	}
	len = strlen(str_b);
	for (ib = 0, ic = 0, id = 0, a = 0; ib < len; ib++) {
		if (str_b[ib] <= '9' && str_b[ib] >= '0') {
			a += str_b[ib] - '0';
			a *= 10;
		} else {
			a /= 10;
			str_c[ic] = a;
			a = 0;
			str_d[id] = str_b[ib];
			id++;
			ic++;
		}
		if (ib == len - 1) {
			a /= 10;
			str_c[ic] = a;
		}
	}

	len = strlen(str_d);
	for (id = 0; id < len; id++) {
		if (str_d[id] == '*') {
			str_c[id] = str_c[id] * str_c[id + 1];
			str_c[id + 1] = str_c[id];
		}
		if (str_d[id] == '/') {
			str_c[id] = str_c[id] / str_c[id + 1];
			str_c[id + 1] = str_c[id];
		}
	}
	num = 0;
	a = 1;
	for (id = 0; id < len; id++) {
		if (str_d[id] == '+' || str_d[id] == '-') {
			if (a == 1)
				num += str_c[id];
			if (a == 2)
				num -= str_c[id];
			if (str_d[id] == '+')
				a = 1;
			if (str_d[id] == '-')
				a = 2;
		}
		if (id == len - 1) {
			if (a == 1)
				num += str_c[id + 1];
			if (a == 2)
				num -= str_c[id + 1];
		}
	}
	printf("%d\n", num);
	return 0;

}
