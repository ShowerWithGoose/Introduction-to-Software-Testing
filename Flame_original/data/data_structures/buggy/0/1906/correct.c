#include <stdio.h>
#include <string.h>

int main() {
	char a[50], b[1000] = {'\0'};
	gets(a);
	int i, j;
	j = 0;
	i = 0;
	while (a[i] != '\0') {
		if (a[i + 1] != '-') {
			b[j] = a[i];
			j++;
			i++;
		} else {
			if (((a[i] >= '0' && a[i + 2] <= '9') || (a[i] >= 'a' && a[i + 2] <= 'z') || (a[i] >= 'A' && a[i + 2] <= 'Z'))
			        && a[i] < a[i + 2]) {
				b[j] = a[i];
				j++;
				for (; b[j - 1] + 1 <= a[i + 2]; j++) {
					b[j] = b[j - 1] + 1;
				}
				j = j - 1;
				i = i + 2;
			} else {
				b[j] = a[i];
				for (int n = 0; n <= 2; n++) {
					b[j] = a[i];
					j++;
					i++;
				}
			}
		}
	}
	b[j] = '\0';
	printf("%s", b);
	return 0;
}
