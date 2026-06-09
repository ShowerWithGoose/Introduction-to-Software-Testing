#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 110

char s[MAXLEN], t[MAXLEN];
int num[100];

int main() {
	int i, count = 0, top = 0, flag = 0, j = -1;
	scanf("%s", s);
	if (s[0] == '0') {
		for (i = 2; s[i] != '\0'; i++) {
			if (s[i] == '0' && flag == 0)
				count++;
			else {
				t[top++] = s[i];
				if (isdigit(s[i + 1]) && flag == 0) {
					flag = 1;
					t[top++] = '.';
				}
			}
		}
		count++;
		t[top++] = 'e';
		t[top++] = '-';
		while (count) {
			num[++j] = count % 10;
			count /= 10;
		}
		for (i = j; i >= 0; i--)
			t[top++] = num[i] + '0';
		t[top] = '\0';
		printf("%s", t);
	}
	else {
		t[top++] = s[0];
		t[top++] = '.';
		for (i = 1; s[i] != '\0'; i++) {
			if (s[i] != '.') 
				t[top++] = s[i];
			else count = i - 1;
		}
		t[top++] = 'e';
		while (count) {
			num[++j] = count % 10;
			count /= 10;
		}
		if (j == -1) t[top++] = '0';
		for (i = j; i >= 0; i--)
			t[top++] = num[i] + '0';
		t[top] = '\0';
		printf("%s", t);
	}
	return 0;
}

