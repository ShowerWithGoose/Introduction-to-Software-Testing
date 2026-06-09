#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int locateDecimalPoint(char* s)
{
	int i = 0, ans = 0;
	while (1) {
		if (*(s + i) == '.') {
			ans = i;
			break;
		}
		i++;
	}
	return ans;
}
int locateNumber(char* s)
{
	int i = 0, ans = 0;
	while (1) {
		if (*(s + i) >= 49 && *(s+i) <= 57) {
			ans = i;
			break;
		}
		i++;
	}
	return ans;
}
int main()
{
	char s[100] = { 0 };
	gets(s);
	int l = strlen(s);
	int p = locateDecimalPoint(s);
	if (s[0] != '0') {
		if (p == 1)
			printf("%se0", s);
		else{
			printf("%c.", s[0]);
			for (int i = 1; i < p; i++) {
				printf("%c", s[i]);
			}
			for (int i = p + 1; i < l; i++) {
				printf("%c", s[i]);
			}
			printf("e");
			printf("%d", p - 1);
		}
		
	}
	else {
		int q = locateNumber(s);
		printf("%c", s[q]);
		if (s[q + 1] != '\0') {
			printf(".");
		}
		for (int i = q + 1; i < l; i++) {
			printf("%c", s[i]);
		}
		printf("e-");
		printf("%d", q - 1);
	}
	return 0;
}

