#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int fx(char a[], int num1[], int num2[]) {
	int i, ret = 0, temp = 0;
	int cnt1 = 0, cnt2 = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (ret == 0) {
			if (a[i] >= '0' && a[i] <= '9') {
				temp = a[i] - '0';
				ret = 1;
			}
			if (i == strlen(a) - 1) {
				if ((cnt1 + cnt2) % 2 == 0) {
					num1[cnt1] = temp;
					cnt1++;
					temp = 0;
					ret = 0;
				} else {
					num2[cnt2] = temp;
					cnt2++;
					temp = 0;
					ret = 0;
				}
			}
		} else {
			if (a[i] >= '0' && a[i] <= '9') {
				temp = temp * 10 + a[i] - '0';
				if (i == strlen(a) - 1) {
					if ((cnt1 + cnt2) % 2 == 0) {
						num1[cnt1] = temp;
						cnt1++;
						temp = 0;
						ret = 0;
					} else {
						num2[cnt2] = temp;
						cnt2++;
						temp = 0;
						ret = 0;
					}
				}
			} else {
				if ((cnt1 + cnt2) % 2 == 0) {
					num1[cnt1] = temp;
					cnt1++;
					temp = 0;
					ret = 0;
				} else {
					num2[cnt2] = temp;
					cnt2++;
					temp = 0;
					ret = 0;
				}
			}
		}
	}
	return cnt1;
}

int main() {
	char s1[2000], s2[2000];
	int ch1x[200] = {0}, ch1y[200] = {0}, ch2x[200], ch2y[200], resx[500] = {0}, resy[500] = {0};
	gets(s1);
	gets(s2);
	//printf("%s", s1);
	int cnt1, cnt2;
	cnt1 = fx(s1, ch1x, ch1y);
	cnt2 = fx(s2, ch2x, ch2y);
//	printf("%d %d", cnt1, cnt2);
	int i, j, ret = 0, tempx, tempy, flag = -1, temp;
	for (i = 0; i < cnt1; i++) {
		for (j = 0; j < cnt2; j++) {
			tempx = ch1x[i] * ch2x[j];
			tempy = ch1y[i] + ch2y[j];
			for (int k = 0; k < ret; k++) {
				if (tempy == resy[k]) {
					flag = k;
					break;
				}
			}
			if (flag >= 0) {
				resx[flag] += tempx;
			} else {
				resx[ret] = tempx;
				resy[ret] = tempy;
				ret++;
			}
			flag = -1;
		}
	}
	/*for (i = 0; i < cnt1; i++) {
		printf("%d %d\n", ch1x[i], ch1y[i]);
	}*/
	for (i = 0; i < ret; i++) {
		for (j = i; j < ret; j++) {
			if (resy[i] < resy[j]) {
				temp = resy[i];
				resy[i] = resy[j];
				resy[j] = temp;
				temp = resx[i];
				resx[i] = resx[j];
				resx[j] = temp;
			}
		}
	}
	for (i = 0; i < ret; i++) {
		printf("%d %d ", resx[i], resy[i]);
	}
	return 0;
}

