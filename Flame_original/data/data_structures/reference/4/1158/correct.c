#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char a[333][333], br[33], ci[555][22], c[22], num[555];
int i, j, k, n, len[333], h, m, s, t, p, q, l, sum;

int main( ) {
	FILE *in;
	in = fopen("article.txt", "r");
	while (fgets(a[i] + 1, 110, in) != NULL) {
		i++;
		len[i - 1] = strlen(a[i - 1] + 1);
	}
	h = i - 1;
	for (i = 0; i <= h; i++) {
		a[i][0] = ' ';
		for (j = 1; j <= len[i]; j++) {
			if (a[i][j] >= 'A' && a[i][j] <= 'Z') {
				a[i][j] = a[i][j] + 'a' - 'A';
			}
		}
		a[i][len[i] + 1] = ' ';
	}
	for (i = 0; i <= h; i++) {
		for (j = 1; j <= len[i] + 1; j++) {
			if (a[i][j] < 'a' || a[i][j] > 'z') {
				k = j - 1;
				while (a[i][k] >= 'a' && a[i][j] <= 'z') {
					k--;
				}
				if (k == j - 1) {
					continue;
				}
				for (m = k + 1; m < j; m++) {
					br[s] = a[i][m];
					s++;
				}
				s = 0;
				for (m = 0; m < p; m++) {
					if (strcmp(ci[m], br) == 0) {
						num[m]++;
						q = 1;
						break;
					}
				}
				if (q != 1) {
					for (m = k + 1; m < j; m++) {
						ci[p][s] = br[s];
						s++;
					}
					num[p]++;
					p++;
				}
				s = 0;
				q = 0;
				for (m = 0; m <= 30; m++) {
					br[m] = '\0';
				}
			}
		}
	}
	sum = p;
	for (i = 0; i <= p - 1; i++) {
		for (j = 0; j <= p - 2 - i; j++) {
A				:
			if (ci[j][l] > ci[j + 1][l]) {
				for (k = 0; k <= 20; k++) {
					c[k] = ci[j][k];
					ci[j][k] = ci[j + 1][k];
					ci[j + 1][k] = c[k];
					t = num[j];
					num[j] = num[j + 1];
					num[j + 1] = t;
				}
			} else if (ci[j][l] == ci[j + 1][l]) {
				l++;
				if (l <= 20) {
					goto A;
				}
			}
			l = 0;
		}
	}
	for (i = 0; i < sum; i++) {
		printf("%s %d\n", ci[i], num[i]);
	}
	return 0;
}



