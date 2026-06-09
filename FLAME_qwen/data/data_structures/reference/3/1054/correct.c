#include<stdio.h>
#include<string.h>
int main() {
	char s[108] = { 0 };
	int dec = 0, len = 0, sta = 0;
	int flag = 0;
	gets(s);
	len = strlen(s);
	for (int i = 0; i <= len; i++) {
		if (s[i] == '.') {
			dec = i;
		}
	}
	if (dec == 1) {
		if (s[0] != '0') {
			s[len] = 'e';
			s[len + 1] = '0';
			puts(s);
		}
		else {
			for (int i = 2; flag == 0; i++) {
				if (s[i] != '0') {
					sta = i;
					flag = 1;
				}
			}
			if (sta + 1 == len) {
				printf("%c", s[sta]);
			}
			else {
				printf("%c.", s[sta]);
			}
			s[len] = 'e';
			s[len + 1] = '-';
			for (int i = sta + 1; i < len + 2; i++) {
				printf("%c", s[i]);
			}
			printf("%d", sta - 1);
		}

	}
	else {
		printf("%c.", s[0]);
		for (int i = 1; i <len; i++) {
			if (i != dec) {
				printf("%c", s[i]);
			}
			
		}
		printf("e%d", dec - 1);
	}
}


