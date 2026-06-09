#include<stdio.h>
#include<string.h>
char s[500], x[500];
int a[500], c[500];
int main() {
	int n, i = 0, pots = 1, sum = 0, m = 0, q = 0;
	gets(s);//输入字符串
	n = strlen(s); //得字符串字符数量
	for ( i = 0; i <= n - 1; i++) {//将字符变为数字，以便计算
		if (s[i] >= '0' && s[i] <= '9') {
			c[m] = s[i] - '0';
			m++;
		} else if (s[i] == ' ')
		{}
		else {
			if (s[i] == '*') {
				c[m] = -1;
				m++;
			} else if (s[i] == '/') {
				c[m] = -2;
				m++;
			} else if (s[i] == '+') {
				c[m] = -3;
				m++;
			} else if (s[i] == '-') {
				c[m] = -4;
				m++;
			} else c[m] = -99; //符号先换算出相对应的负数
		}
	}

	for ( i = 0; i <= m - 1; i++) {
		if (c[i] >= 0 && c[i + 1] >= 0) { //考虑存在十位数百位数的情况
			c[i + 1] = 10 * c[i] + c[i + 1];//占据个位，其余位变为-5，后续除去
			c[i] = -5;
		}
	}

	for ( i = 0; i <= m - 1; i++) {
		if (c[i] != -5) { //提取所有数字与符号（除去上面的-5们）
			a[q] = c[i];
			q++;
		}
	}

	for ( i = 0; i <= q - 1 ; i++) {
		if (a[i] == -1 || a[i] == -2 ) { //计算乘除，把乘除式的前一个数变为-5，后一个数变为结果
			if (a[i] == -1) {
				a[i + 1] = a[i - 1] * a[i + 1];
				a[i - 1] = -5;
			} else
				a[i + 1] = a[i - 1] / a[i + 1];
			a[i - 1] = -5;
		}
	}

	for ( i = 0; i <= q - 1 ; i++) {
		if (a[i] == -4) {//判断加减
			pots = -1;
		} else if (a[i] == -3) { //同上
			pots = 1;
		}
		if (a[i] >= 0)//所有有用的数
			sum = sum + pots * a[i];

	}
	printf("%d", sum);
}

