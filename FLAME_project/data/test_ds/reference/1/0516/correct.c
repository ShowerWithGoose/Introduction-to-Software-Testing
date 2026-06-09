#include <stdio.h>
#include <string.h>
int main ()
{
	char s[10005];
	scanf("%s", s);
	int len = strlen (s);
	int i;
	for (i = 0; i < len - 2; i++) {
		if ((s[i] >= '0' && s[i + 2] <= '9' && s[i + 2] >= '0' && s[i] <= '9' && s[i + 1] == '-') || (s[i] >= 'A' && s[i + 2] >= 'A' && s[i] <= 'Z' && s[i + 2] <= 'Z' && s[i + 1] == '-') || (s[i] >= 'a' && s[i + 2] >= 'a' && s[i] <= 'z' && s[i + 2] <= 'z' && s[i + 1] == '-')) {
			int a = s[i + 2] - s[i];
			if (a <= 1) continue;
			else {
				int k;
				for (k = len - 1; k > i + 1; k --) {
					s[k + a - 2] = s[k];
				}
				int m;
				for (m = 0; m < a - 1; m ++) {
					s[i + m + 1] = s[i + m] + 1;
				}
				len += (a - 2);
				i += a - 1;
			}
		}
	}
	printf ("%s\n", s);
	return 0;
}

