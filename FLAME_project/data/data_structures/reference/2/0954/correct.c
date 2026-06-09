#include <stdio.h>
#include <string.h>

int main () {
	char str[5000];
	char save[5000];
	int num[5000];//存放数字的数组
	char sign[5000];//存放符号的数组
	gets(str);
	int i = 0, j = 0, k = 0;
	i = strlen(str);
	for (j = 0, k = 0; j < i; j++) {
		if (str[j] != ' ') {
			save[k++] = str[j];
		}
	}//去除空格
	save[k] = '\0'; //添加结尾
	int number = 0;
	int si = 0;
	int flag = 1; //判断是否读到了符号
	int count = 0; //判断是几位数字
	int sum = 0; //计算每个数字
	int plus = 0, minus = 0, multi = 0, divide = 0;
	for (int j = 0; j < strlen(save); j++) {
		if (save[j] == '+' || save[j] == '-' || save[j] == '*' || save[j] == '/' || save[j] == '=') {
			sign[si++] = save[j];
			flag = 0;
		} else {
			flag = 1;
			sum = 10 * sum + (save[j] - '0');
		}
		if (flag == 0) {
			num[number++] = sum;
			sum = 0;
		}
	}
	sign[si] = '\0';
	for (int m = 0; m < strlen(sign); m++) {
		if (sign[m] == '*') {
			multi = num[m] * num[m + 1];
			num[m] = multi;
			num[m + 1] = multi;
			multi = 1;
		} else if (sign[m] == '/') {
			divide = num[m] / num[m + 1];
			num[m] = divide;
			num[m + 1] = divide;
			divide = 1;
		}
	}//运算乘除法
	for (int m = 0; m < strlen(sign); m++) {
		if (sign[m] == '+' || sign[m] == '-' || sign[m] == '=') {
			int set = m;
			while (set >= 0) {
				set--;
				if (sign[set] == '+' || sign[set] == '-') {
					break;
				} else {
					num[set] = num[m];
				}
			}
		}
	}
	int judge = 0;
	for (int m = 0; m < strlen(sign); m++) {
		if (sign[m] == '+') {
			plus = num[m] + num[m + 1];
			judge = 1;
		} else if (sign[m] == '-') {
			minus = num[m] - num[m + 1];
			judge = 2;
		}
		if (judge == 1) {
			num[m] = plus;
			num[m + 1] = plus;
		} else if (judge == 2) {
			num[m] = minus;
			num[m + 1] = minus;
		}
	}//加减运算
	if (judge == 1) {
		num[strlen(sign)] = plus;
	} else if (judge == 2) {
		num[strlen(sign)] = minus;
	}
	int answer = 0;
	answer = num[si - 1];
	printf("%d", answer);
	return 0;
}


