#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Cleanspace(char *s) { //清除空格
	char *s_c = s;
	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ')
			s_c[j++] = s[i];
	}
	s_c[j] = '\0';
	s = s_c;
}

int mult(char *p, int a) { //计算乘除串
	int n = 0;
	for (; *p != '+' && *p != '-' && *p != '\0'; ) {
		if (*p == '*') {
			for (p = p + 1; *p != '*' && *p != '/' && *p != '\0' && *p != '+' && *p != '-'; p++)
				if (isdigit(*p))
					n = 10 * n + *p - '0';
			a *= n;
			n = 0;
		}
		if (*p == '/') {
			for (p = p + 1; *p != '*' && *p != '/' && *p != '\0' && *p != '+' && *p != '-'; p++)
				if (isdigit(*p))
					n = 10 * n + *p - '0';
			a /= n;
			n = 0;
		}
	}
	return a;
}

int ispure(char *s) { //判断是否是纯数字
	char *s_c = s + 1;
	for (s_c; *s_c != '+' && *s_c != '-' && *s_c != '\0'; s_c++)
		if (*s_c == '*' || *s_c == '/')
			return 0;
	return 1;//*p不动
}

int main() {
	char a[200], s[200];
	gets(a);
	int ans = 0, n = 0, m = 0, sign, i; //num用于存储每个字符串转换的数字
	Cleanspace(s);
	if (isdigit(a[0])) {
		s[0] = '+';
		for (i = 1; i <= strlen(a); i++)
			s[i] = a[i - 1];
		s[i] = '\0';	//无符号的第一个数加上+
	}
	char *p = s;
	for (p; *p != '\0'; ) {
		if (*p == '+' || *p == '-' ) {
			sign = (*p == '+') ? 1 : -1;
			if (ispure(p)) {
				for (p = p + 1; *p != '+' && *p != '-' && *p != '\0'; p++) {
					if (isdigit(*p))
						n = 10 * n + *p - '0';
				}
				ans += sign * n;
				n = 0;//加减纯数字
			} else { //加减乘除串
				for (p = p + 1; *p != '*' && *p != '/'; p++) {
					if (isdigit(*p))
						n = 10 * n + *p	 - '0';
				}
				for (; *p != '+' && *p != '-' && *p != '\0'; ) {//将指针调至合适位置
					if (*p == '*') {
						for (p = p + 1; *p != '*' && *p != '/' && *p != '\0' && *p != '+' && *p != '-'; p++)
							if (isdigit(*p))
								m = 10 * m + *p - '0';
						n *= m;
						m = 0;
					}
					if (*p == '/') {
						for (p = p + 1; *p != '*' && *p != '/' && *p != '\0' && *p != '+' && *p != '-'; p++)
							if (isdigit(*p))
								m = 10 * m + *p - '0';
						n /= m;
						m = 0;
					}
				}
				n = mult(p, n);
				ans += sign * n;
				n = 0;
			}
		}
	}
	printf("%d", ans);
	return 0;
}


