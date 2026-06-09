#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int main () {
	char s[100];
	gets(s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != '-') {
			printf("%c", s[i]);
		} else {
			if (s[i + 1] - s[i - 1] > 0) {
				if ((s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'x')) {
					for (int j = 1; j < s[i + 1] - s[i - 1]; j++) {
						printf("%c", s[i - 1] + j);
					}
				}
				else printf("%c",s[i]);
			}
			else printf("%c",s[i]);
		}
	}

	return 0;
}



