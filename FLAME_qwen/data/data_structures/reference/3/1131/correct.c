#include <stdio.h>
#include <string.h>
int main()
{
	char a[100], b, c;int i=0, j, q, p=0, k = 0, flag = 0, count[3] = { 0 };
	gets(a);
	for (i = 0;a[i] != '\0';i++) {
		if (flag == 1) {
			count[0]++;
		}
		if (a[i] == '.') {
			p = i;
		}
		if (a[i] >= '1' && a[i] <= '9') {
			flag = 1;
			count[1]++;
		}
	}
	q = i ;flag = 0;
	if (a[0] == '-') {
		for (i = 0;i < q;i++) {
			a[i] = a[i + 1];
		}
		printf("-");
		q = q - 1;
	}
	if (a[0] != '-') {
		if (a[0] == '0') {
			for (i = 0;i < q;i++) {
				if (a[i] != '.') {
					k++;
					if (a[i] != '0' || flag == 1) {
						printf("%c", a[i]);
						flag = 1;
						k--; 
					if (count[0] >= 2) {
						printf(".");
						count[0] = 0;
					}
					} 
				}
			}
			printf("e-%d", k);
		}
		else {
			if (p == 0&&count[1]==1) {
				printf("%c", a[0]);
			printf("e%d", q - 1);
		}
			else {
				printf("%c.", a[0]);
				for (i = 1;i < q;i++) {
					if (a[i] != '.') {
						printf("%c", a[i]);
					}
				}
				printf("e%d", p-1);
				}
			}
	}
	return 0;
}

