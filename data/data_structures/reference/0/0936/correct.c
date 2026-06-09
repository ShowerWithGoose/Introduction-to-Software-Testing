#include<stdio.h>
#include<string.h>
char s[10000007];
int main() {
	scanf("%s", s);
	int i = 0;
	while (s[i] != '\0') {
		if ((s[i] == '-') && (i >= 1)) {
			if ((s[i - 1] >= 'a') && (s[i - 1] <= 'z') && (s[i + 1] >= 'a') && (s[i + 1] <= 'z') && (s[i - 1] < s[i + 1])) {
				for (int j = 1; s[i - 1] + j < s[i + 1]; j++) {
					printf("%c", s[i - 1] + j);
				}
			} else if ((s[i - 1] >= 'A') && (s[i - 1] <= 'Z') && (s[i + 1] >= 'A') && (s[i + 1] <= 'Z') && (s[i - 1] < s[i + 1])) {
				for (int j = 1; s[i - 1] + j < s[i + 1]; j++) {
					printf("%c", s[i - 1] + j);
				}
			} else if ((s[i - 1] >= '0') && (s[i - 1] <= '9') && (s[i + 1] >= '0') && (s[i + 1] <= '9') && (s[i - 1] < s[i + 1])) {
				for (int j = 1; s[i - 1] + j < s[i + 1]; j++) {
					printf("%c", s[i - 1] + j);
				}
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
		i++;
	}
	return 0;
}

