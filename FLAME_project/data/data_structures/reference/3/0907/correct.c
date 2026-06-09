#include <stdio.h>
#include <string.h>
char s[500];
int len, L = 0, F = 0, sp;

int main() {
	gets(s);
	len = strlen(s);
	if (s[0] == '-') {
		for (int i = 0; i < len - 1; i++) {

			s[i] = s[i + 1];
		}

		F = 1;
		len--;
	}

	for (int i = len - 1; i >= 1; i--) {

		if (s[i] == '0')
			L++;
	}

	int p = 0;

	for (p = 0; p < len; p++) {

		if (s[p] == '.')
			break;
	}

	if (p != len) {
		for (int i = p; i < len; i++) {

			s[i] = s[i + 1];
		}

		len--;
	}

	for (int i = 0; i < len; i++) {

		if (s[i] >= '1' && s[i] <= '9') {
			sp = i + 1;
			break;
		}
	}
	if (F)
		printf("-");
	printf("%c", s[sp - 1]);
	for(int i=len-1;i>=0;i--){
		if(s[i]=='0') len--;
		else break;
	}
	if(sp<len) printf(".");
	for (int i = sp; i < len; i++) {
		printf("%c", s[i]);
	}
	printf("e%d", p - sp);
	return 0;
}


