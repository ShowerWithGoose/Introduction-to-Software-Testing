#include <stdio.h>
#include <string.h>

int type(char a, char b) {
	int t1 = 4, t2 = 4;
	if (a <= 'z' && a >= 'a')
		t1 = 0;
	else if (a <= 'Z' && a >= 'A')
		t1 = 1;
	else if (a <= '9' && a >= '0')
		t1 = 2;
	if (b <= 'z' && b >= 'a')
		t2 = 0;
	else if (b <= 'Z' && b >= 'A')
		t2 = 1;
	else if (b <= '9' && b >= '0')
		t2 = 2;
	return t1 == t2;
}

int main() {
	char a[100];
	scanf("%s", a);
	int i = 0;
	int len = strlen(a);
	while (a[i] != '\0') {
		if (i + 1 < len) {
			if (a[i] == '-' && type(a[i - 1], a[i + 1]) && a[i - 1] < a[i + 1]) {
				char p = a[i - 1] + 1;
				while (p < a[i + 1])
					putchar(p++);
			} else {
				putchar(a[i]);
			}
		} else {
			putchar(a[i]);
		}
		i++;
	}
}


