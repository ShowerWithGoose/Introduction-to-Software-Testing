#include <stdio.h>
#include <string.h>
#include <ctype.h>
char s[100];
int main() {
	gets(s);
	int len = strlen(s);
	int i;
	char k, m;
	for (i = 0; i < len; i++) {
		if (s[i] == '-') {
			int flag = 1;
			k = s[i - 1];
			m = s[i + 1];
			if (isdigit(k) && isdigit(m) && m > k) {
				flag = 0;
				char c = k + 1;
				while (c < m) {
					putchar(c);
					c++;
				}
			} else if (isupper(k) && isupper(m) && m > k) {
				flag = 0;
				char c = k + 1;
				while (c < m) {
					putchar(c);
					c++;
				}
			} else if (islower(k) && islower(m) && m > k) {
				flag = 0;
				char c = k + 1;
				while (c < m) {
					putchar(c);
					c++;
				}
			}
			if (flag) putchar('-');

		} else putchar(s[i]);


	}





	return 0;
}



