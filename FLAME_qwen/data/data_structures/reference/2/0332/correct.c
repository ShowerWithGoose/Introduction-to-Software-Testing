#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int change(int, int);
char s[10000];
char l[10000];
int main() {

	gets(s);
	for (int i = 0, j = 0; i < (int)strlen(s); i++) {
		if (s[i] != ' ' && s[i] != '=') {
			l[j++] = s[i];
		}
	}
	int len = (int)strlen(l);
	char fuhao[5000] = {'\0'};
	int num[5000] = {0}, loca[5000] = {0};
	for (int i = 0, j = 0; i < len; i++) {
		if (!isdigit(l[i])) {
			fuhao[j] = l[i];
			loca[j++] = i;
		}
	}

	int lenfuhao = (int )strlen(fuhao);
	if (lenfuhao == 0) {
		printf("%s", l);
		return 0;
	}
	num[0] = change(0, loca[0] - 1);
	num[lenfuhao] = change(loca[lenfuhao - 1] + 1, len - 1);
	for (int i = 0; i < lenfuhao - 1; i++) {
		num[i + 1] = change(loca[i] + 1, loca[i + 1] - 1);
	}
	for (int i = 0; i < lenfuhao; i++) {
		if (fuhao[i] == '*') {
			num[i + 1] = num[i + 1] * num[i];
			num[i] = 0;
		}
		if (fuhao[i] == '/') {
			num[i + 1] = num[i] / num[i + 1];
			num[i] = 0;
		}
	}
	int newnum[500] = {0};
	int key;//需要加的数字数目
	for (int i = 0, j = 0; i <= lenfuhao; i++) {
		if (num[i])newnum[j++] = num[i];
		key = j;
	}
	for (int i = 0, j = 0; i <= lenfuhao; i++) {
		if (fuhao[i] == '+') {
			newnum[j + 1] = newnum[j + 1] + newnum[j];
			j++;
		}
		if (fuhao[i] == '-') {
			newnum[j + 1] = newnum[j] - newnum[j + 1];
			j++;
		}

	}
	printf("%d", newnum[key - 1]);
	return 0;
}
int change(int a, int b) {
	int ans = 0;
	for (int i = a; i <= b; i++) ans += (l[i] - '0') * pow(10, b - i );
	return ans;
}



