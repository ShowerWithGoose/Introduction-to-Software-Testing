#include <stdio.h>
#include <string.h>
char str_a[100000];
char str_b[100000];

int main() {
	int ia, ib, len, fu = 0, xiao = -1, lenb, a = 1, b = 0, c;
	scanf("%s", str_a);
	len = strlen(str_a);
	if (str_a[0] == '0') {
		fu = 0;
	} else
		fu = 1;
	for (ia = 0; ia < len; ia++) {
		if (str_a[ia] == '.')
			xiao = ia;
	}
	if (xiao == -1)
		xiao = len;
	if (fu == 1) {
		for (ia = 0, ib = 0; ia < len; ia++) {
			if (str_a[ia] != '.')
				str_b[ib++] = str_a[ia];
			if (ia == 0)
				str_b[ib++] = '.';
		}
		lenb = strlen(str_b);
		a = 1;
		if (str_b[lenb - 1] == '0') {
			a = 0;
			str_b[lenb - 1] = '\0';
		}
		if (a == 0)
			for (ib = lenb - 2; ib >= 0; ib--) {
				if (a == 0) {
					if (str_b[ib] == '0') {
						str_b[ib] = '\0';
					} else
						a = 1;
				}
			}
		lenb = strlen(str_b);
		if (lenb == 2)
			str_b[1] = '\0';
		printf("%se%d", str_b, xiao - 1);
	}

	else if (fu == 0) {
		for (ia = 0; ia < len; ia++)
			if (str_a[ia] <= '9' && str_a[ia] >= '1') {
				c = ia;
				break;
			}
		for (ia = 0, ib = 0, b = 0; ia < len; ia++) {
			if (str_a[ia] <= '9' && str_a[ia] >= '1') {
				b++;
				str_b[ib++] = str_a[ia];
			}
			if (b == 1)
				str_b[ib++] = '.';
			if (str_a[ia] == '0' && b > 0) {
				str_b[ib++] = str_a[ia];
			}
		}
		if (strlen(str_b) == 2)
			str_b[1] = '\0';
		printf("%se-%d", str_b, c - xiao);
	}









	return 0;
}
