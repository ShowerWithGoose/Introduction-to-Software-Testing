#include <stdio.h>
#include <string.h>

int main() {
//	char s[100];
//	gets(s);
	char t[100];
//	int j = 0;
//	for (int i = 0; i < strlen(s); i++) {
//	if (s[i] != '\0') {
//		t[j] = s[i];
//		j++;
//	}
//}
//	t[j] = '\0';
	int a1 = 0;
	char sign1 = '+';
	while (sign1 != '=') {
		int a2;
		char sign2;
		scanf( "%d %c", &a2, &sign2);
		while (sign2 == '*' || sign2 == '/') {
			int a3;
			char sign3;
			scanf( "%d %c", &a3, &sign3);
			if (sign2 == '*') {
				a2 = a2 * a3;
			} else if (sign2 == '/') {
				a2 = a2 / a3;
			}
			sign2 = sign3;
		}
		if (sign1 == '+') {
			a1 += a2;
		} else if (sign1 == '-') {
			a1 -= a2;
		}
		sign1 = sign2;
	}
	printf("%d", a1);
}
