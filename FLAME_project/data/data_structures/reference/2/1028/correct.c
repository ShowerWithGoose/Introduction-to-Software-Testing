#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int suanshu(char*, int, int);
int zhunei(char*, int, int);
void qukongguo(char*s) {
	int i;
	int j = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') {
			s[j++] = s[i];
		}
	}
}
int main () {
	char s[1000];
	int jiajian[100];//以最低级运算“+、-”来做第一层分组
	int j = 0;
	int i;
	int jieguo = 0;
	gets(s);
	qukongguo(s);
	for (i = 0; s[i] != '='; i++) {
		if (s[i] == '+' || s[i] == '-') {
			jiajian[j++] = i;
		}
	}
	jiajian[j] = i;

	jieguo += zhunei(s, 0, jiajian[0] - 1);
	for (int k = 0; k < j; k++) {
		if (s[jiajian[k]] == '+') {
			jieguo += zhunei(s, jiajian[k] + 1, jiajian[k + 1] - 1);
		} else {
			jieguo -= zhunei(s, jiajian[k] + 1, jiajian[k + 1] - 1);
		}
	}
	printf("%d", jieguo);
	return 0;
}
int suanshu(char* s, int i, int j) {
	int shu = 0;
	int l = 1;
	for (; j >= i; j--) {
		shu += (s[j] - '0') * l;
		l *= 10;
	}
	return shu;
}
int zhunei(char* s, int i, int j) {
	int shuzi[10];
	int chengchu[10];
	int k = i;
	int u = 0;
	int shu = 0;
	int yinzi;
	for (; k <= j; k++) {
		if (s[k]=='*' || s[k]=='/') {
			chengchu[u++] = k;
		}
	}
	chengchu[u]=k;
	
	shu += suanshu(s, i, chengchu[0] - 1);
	for (k = 0; k < u; k++) {
		yinzi = suanshu(s, chengchu[k] + 1, chengchu[k + 1] - 1);
		if (s[chengchu[k]] == '*') {
			shu *= yinzi;
		} else shu /= yinzi;
	}
	return shu;
}



