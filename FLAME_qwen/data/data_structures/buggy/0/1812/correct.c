#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[501];
int main() {
	scanf("%s", s);
	for (int i = 0; i<strlen(s); i++) {
		if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (islower(s[i - 1]) && islower(s[i + 1])) || (isupper(s[i - 1]) && isupper(s[i + 1]))) && s[i - 1] < s[i + 1]) {
			int n, j;
			n = s[i + 1] - s[i - 1] - 2;
			j = strlen(s);
			for (; j >= i + 1; j--) {
				s[j + n] = s[j];
			}
			int m = i;
			for (char c = s[i - 1] + 1; m <= i + n + 1; c++, m++) {
				s[m] = c;
			}
		}
	}
	printf("%s",s);
	return 0;
}



