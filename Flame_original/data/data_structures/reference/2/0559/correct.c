#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
char str[1000];
char initialNum[10];
int num[2000];
void spaceDelete(char *a);//去除空格
int addFunc(int *num, int n);


int main() {
	gets(str);
	spaceDelete(str);
	int len = strlen(str);
	int cnt = 1;
	int mul = 1;
	int sign = 2;//sign 为 1乘法；为 0除法
	for (int i = 0, j = 0; i < len; i++) {
		if (isdigit(str[i]) != 0) {
			initialNum[j] = str[i];
			j++;
		} else if (str[i] == '=') {
			if (sign == 2)
				num[i - 1] = atoi(initialNum) * cnt;
			else if (sign == 1) {
				num[i - 1] = atoi(initialNum) * cnt * mul;
				if (i >= 3) {
					num[i - j-2] = 0;
				}
			} else if (sign == 0) {
				num[i-1]=mul/atoi(initialNum);
				if(i>=3){
					num[i-j-2]=0;
				}
			}
			break;
		} else {
			if ((str[i] == '-' || str[i] == '+')&&sign==2) {

				if (str[i] == '-') {
					num[i - 1] = atoi(initialNum) * cnt;
					//中间隔一格
					cnt = -1;
				} else {
					num[i - 1] = atoi(initialNum) * cnt;
					cnt = 1;
				}
				if(sign==2)
				memset(initialNum, 0, sizeof(initialNum));
				j = 0;
			} else {
				if (str[i] == '*') {
					if (sign == 1) {
						num[i - 1] = atoi(initialNum) * mul;
						if (i >= 3) num[i - j-2] = 0;
						sign = 2; //表示已完成
					} else if (sign == 0) {
						num[i - 1] = mul / atoi(initialNum);
						if (i >= 3) num[i - j-2] = 0;
						sign = 2;
					}
					else if(sign==2){
						num[i - 1] = atoi(initialNum) * cnt;
					}
					mul = num[i - 1];
					sign = 1;
					memset(initialNum, 0, sizeof(initialNum));
					j = 0;
				}
				else if(str[i]=='/'){
					if (sign == 1) {
						num[i - 1] = atoi(initialNum) * mul;
						if (i >= 3) num[i - j-2] = 0;
						sign = 2; //表示已完成
					} else if (sign == 0) {
						num[i - 1] = mul / atoi(initialNum);
						if (i >= 3) num[i - j-2] = 0;
						sign = 2;
					}
					else if(sign==2){
						num[i - 1] = atoi(initialNum) * cnt;
					}
					mul = num[i - 1];
					sign=0;
					memset(initialNum, 0, sizeof(initialNum));
					j = 0;
				}
				else//体现乘法运算优先级 sign不为2
				{
					if (sign == 1) {
						num[i - 1] = atoi(initialNum) * mul;
						if (i >= 3) num[i - j-2] = 0;
						sign = 2; //表示已完成
					} else if (sign == 0) {
						num[i - 1] = mul / atoi(initialNum);
						if (i >= 3) num[i - j-2] = 0;
						sign = 2;
					}
					if(str[i]=='-') cnt=-1;
					if(str[i]=='+') cnt=1;
					memset(initialNum, 0, sizeof(initialNum));
					j = 0;
				}
			}
		}
	}
	int ans = addFunc(num, len);
	printf("%d\n", ans);
	return 0;
}
void spaceDelete(char *a) {
	char *p;
	p = a;
	while (*a) {
		if (*a != 32) {
			*p = *a;
			p++;

		}
		a++;
	}
	*p = '\0';
}
int addFunc(int *num, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += num[i];
	}
	return ans;
}

