/*example1c.c*/
#include<stdio.h>

int judge(char ch);
int main() {
	char ch[1000];
	gets(ch);
	int sum_sum = 0, sum_and, sum_sup;
	int i, j = 0;
	for (i = 0; judge(ch[i]) != 5; i++) {
		if (ch[i] != ' ') {
			ch[j++] = ch[i];
		}
	}
	ch[j] = '=';
	ch[j + 1] = '\0';
	int it;
	for (it = 0; judge(ch[it]) <= 4 && judge(ch[it]) >= 2; i++) {
		if (judge(ch[it]) == 2) {
			it++;
			sum_sup = 0;
			for (; judge(ch[it]) == 4; it++) {
				sum_sup = sum_sup * 10 + ch[it] - '0';
			}
			sum_and *= sum_sup;
		} else if (judge(ch[it]) == 3) {
			it++;
			sum_sup = 0;
			for (; judge(ch[it]) == 4; it++) {
				sum_sup = sum_sup * 10 + ch[it] - '0';
			}
			sum_and /= sum_sup;
		} else {
			sum_and = 1;
			sum_sup = 0;
			for (; judge(ch[it]) == 4; it++) {
				sum_sup = sum_sup * 10 + ch[it] - '0';
			}
			sum_and *= sum_sup;
		}
	}
	sum_sum += sum_and;
	while (ch[it] != '=') {
		if (ch[it] == '+') {
			it++;
			for (; judge(ch[it]) <= 4 && judge(ch[it]) >= 2; i++) {
				if (judge(ch[it]) == 2) {
					it++;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and *= sum_sup;
				} else if (judge(ch[it]) == 3) {
					it++;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and /= sum_sup;
				} else {
					sum_and = 1;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and *= sum_sup;
				}
			}
			sum_sum += sum_and;
		}
		if (ch[it] == '-') {
			it++;
			for (; judge(ch[it]) <= 4 && judge(ch[it]) >= 2; i++) {
				if (judge(ch[it]) == 2) {
					it++;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and *= sum_sup;
				} else if (judge(ch[it]) == 3) {
					it++;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and /= sum_sup;
				} else {
					sum_and = 1;
					sum_sup = 0;
					for (; judge(ch[it]) == 4; it++) {
						sum_sup = sum_sup * 10 + ch[it] - '0';
					}
					sum_and *= sum_sup;
				}
			}
			sum_sum -= sum_and;
		}		
	}
	printf("%d",sum_sum);
	return 0;
}
int judge(char ch) {
	if (ch == '+') {
		return 0;
	} else if (ch == '-') {
		return 1;
	} else if (ch == '*') {
		return 2;
	} else if (ch == '/') {
		return 3;
	} else if (ch == '=') {
		return 5;
	}
	return 4;
}



