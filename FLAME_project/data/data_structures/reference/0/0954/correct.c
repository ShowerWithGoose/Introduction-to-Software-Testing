#include <stdio.h>
#include <string.h>

int main() {
	char str[5000];
	char expand[5000];
	scanf("%s", str);
	int i, j, k;
	int begin, over;
	k = strlen(str);
	for (i = 0, j = 0; i < k; i++) {
		if (str[i] == '-') {
			if (i == 0 || i == k - 1) {
				expand[j++] = str[i];
			} else {
				if ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0'
				        && str[i + 1] <= '9')) {
					begin = str[i - 1];
					over = str[i + 1];
					for (int m = begin + 1; m < over; m++) {
						expand[j++] = m;
					}
				} else {
					expand[j++] = str[i];
				}
			}

		} else {
			expand[j++] = str[i];
		}
	}
	expand[j] = '\0';
	puts(expand);
	return 0;
}
