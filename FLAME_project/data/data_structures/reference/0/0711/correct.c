#include<stdio.h>
#include<string.h>
char s[1000], x[1000];
int main() {
	int i, j, n;
	gets(s);//输入字符串
	n = strlen(s); //计算字符串中有多少字符
	x[0] = s[0]; //第一位字符无需检查
	for (i = 1, j = 1; i <= n - 1; i++, j++) { //逐字符检查有无“―”
		if (s[i] == '-') { //是，则进一步分析
			if ('0'  <= s[i - 1] && s[i - 1]  < s[i + 1] && s[i + 1] <= '9') { //0与9之间的情况
				x[j] = s[i - 1] + 1;//补充'-'代表的字符 
				for (; x[j] < s[i + 1]-1; j++) {
					x[j + 1] = x[j] + 1;
				}
			} else if ('a' <= s[i - 1] && s[i - 1]  < s[i + 1] && s[i + 1] <= 'z') { //a与z
				x[j] = s[i - 1] + 1;
				for (; x[j] < s[i + 1]-1; j++) {
					x[j + 1] = x[j] + 1;
				}
			}			else if  ('A' <= s[i - 1] && s[i - 1] < s[i + 1] && s[i + 1] <= 'Z') { //A与Z
				x[j] = s[i - 1] + 1;
				for (; x[j] < s[i + 1]-1; j++) {
					x[j + 1] = x[j] + 1;
				}
			}			else  x[j] = s[i];
		} else x[j] = s[i];
	}
	for (i = 0; i <= j - 1; i++) { //逐字符输出
		printf("%c", x[i]);
	}
}

