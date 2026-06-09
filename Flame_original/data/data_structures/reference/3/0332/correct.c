#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main() {
	char s[105] = {'\0'};
	gets(s);
	int len = strlen(s);
	int loca1, loca2 = 0;
	if (s[0] == '-') {
		printf("-");
		for (int i = 0; i < len - 1; i++) {
			s[i] = s[i + 1];
		}
		len--;
		s[len] = '\0';
	}
	for (int i = 0; i < len; i++) {
		if (s[i] == '.') {
			loca1 = i;
			break;
		}
	}//ÕÒµ½.
	if (s[0] == '0' && loca1 == 1) {
		for (int i = 2; i < len; i++) {
			if (s[i] != '0') {
				loca2 = i;
				break;
			}
		}
		printf("%c", s[loca2]);
		if (len > 3) {
			printf(".");
		}
		for (int i = loca2 + 1; i < len; i++) {
			printf("%c", s[i]);
		}
		printf("e-%d", loca2 - loca1);
	} else if (s[0] != '0' && loca1 == 1) {
		printf("%s", s);
		printf("e0");
	} else {
		printf("%c.", s[0]);
		for (int i = 1; i < len; i++) {
			if (i != loca1)printf("%c", s[i]);
		}
		printf("e%d", loca1 - 1);
	}
	return 0;
}



