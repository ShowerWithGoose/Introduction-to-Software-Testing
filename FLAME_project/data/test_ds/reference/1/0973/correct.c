#include <stdio.h>
#include <string.h>

int main() {
	char s1[100] = {}, s2[200] = {};
	gets(s1);
	int i2 = 0;
	for (int i1 = 0; i1 < strlen(s1); i1++) {
		if (s1[i1] == '-') {
			if (s1[i1 - 1] >= 'a' && s1[i1 + 1] <= 'z') {
				for (int k = 1; k < s1[i1 + 1] - s1[i1 - 1]; k++) {
					s2[i2++] = s1[i1 - 1] + k;
				}
			} else if (s1[i1 - 1] >= 'A' && s1[i1 + 1] <= 'Z') {
				for (int k = 1; k < s1[i1 + 1] - s1[i1 - 1]; k++) {
					s2[i2++] = s1[i1 - 1] + k;
				}

			} else if (s1[i1 - 1] >= '0' && s1[i1 + 1] <= '9') {
				for (int k = 1; k < s1[i1 + 1] - s1[i1 - 1]; k++) {
					s2[i2++] = s1[i1 - 1] + k;
				}
			} else {
				s2[i2++] = s1[i1];
			}
		} else {
			s2[i2++] = s1[i1];
		}
	}
	puts(s2);
	return 0;
}


