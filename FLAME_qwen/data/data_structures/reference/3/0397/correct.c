#include <stdio.h>

char s[110];

void SwapBackward(int i) {
	int tmp = s[i];
	s[i] = s[i + 1];
	s[i + 1] = tmp;
	return;
}

int main() {
	gets(s);
	
	int AfterE, i;
	if (s[0] == '0') {
		AfterE = -1;
		for (i = 2; s[i] == '0'; i++) {
			AfterE--;
		}
		printf("%c", s[i]);
		if (s[i + 1] != '\0') {
			printf(".");
			for ( i = i + 1; s[i] != '\0'; i++) {
				printf("%c", s[i]);
			}
		}
		printf("e%d", AfterE);
	} else {
		AfterE = 0;
		while (s[AfterE + 1] != '.') {
			AfterE++;
		}
		printf("%c.", s[0]);
		
		for (int i = 1; s[i] != '\0'; i++) {
			if (s[i] != '.') printf("%c", s[i]);
		}
		printf("e%d", AfterE);
		
	}
	
	return 0;
}

