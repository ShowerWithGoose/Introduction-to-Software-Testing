#include<stdio.h>
#include<string.h>
#include<ctype.h> 

void del_char(char* str, char ch);
int main() {
	int sum = 0;
	char s[500];//输入的运算公式
	gets(s);
	del_char(s,' ');//删掉字符串中的空格
	int num = 0;
	int put[50];//设一个存放各阶段计算结果的数组
	int n = -1;
	char sign = '+';
	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) {
			num = num * 10 + s[i] - '0';//第一个整数num
		}
		if (!isdigit(s[i])) {
			if (sign == '+') put[++n] = num;
			if (sign == '-') put[++n] = -num;
			if (sign == '*') put[n] *= num;
			if (sign == '/') put[n] /= num;
			sign = s[i];
			num = 0;
		}
	}
	for (int i = 0; i <= n; i++) {
		sum += put[i];
	}
	printf("%d", sum);

	
	return 0;
}
void del_char(char* str, char ch) {

	char* p = str;
	char* q = str;
	while (*q) {

		if (*q != ch) {
			*p++ = *q;
		}
		q++;

	}
	*p = '\0';

}

