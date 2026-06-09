#include <stdio.h>
#include <string.h>
#include <math.h>
char nota[110], po[110];
int findnota(int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (nota[i] == '.') return i;
	} 
}
int findfistnum(int len) {
	int i;
	for (i = 0; i < len; i++) {
		if ('0' < nota[i] && nota[i] <= '9') return i;
	}
}
int powfind(int len) {
	int re, i = 0;
	int m = findnota(len);
	int n = findfistnum(len);
	(m < n) ? (re = m - n) : (re = m - n - 1);
	return re;
}
void prin(int len) {
	int m = findnota(len);
	int n = findfistnum(len);
	printf("%c", nota[n]);
	if (n < len - 1) printf(".");
	for (int i = n + 1; i < len; i++) {
		if (i == m) continue;
		printf("%c", nota[i]);
	}
	printf("e");
	return;
}
void prinpow(int len) {
	int num = powfind(len);
	if (num == 0) {
		printf("0");
		return;
	}
	if (num < 0) printf("-");
	num = abs(num);
	int i = 0;
	while(0 < num) {
		po[i++] = num % 10 + '0';
		num /= 10;
	}
	for (i; 0 < i; i--) printf("%c", po[i - 1]);
	return;
}
int main() {
	scanf("%s", nota);
	int len = strlen(nota);
	prin(len);
	prinpow(len);
	return 0;
}



