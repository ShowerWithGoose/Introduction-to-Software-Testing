#include <string.h>
#include <stdio.h>

char str[1000];
char ans[1000];

int main() {
	gets(str);
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '-') {
			ans[k] = str[i];
			k++;
			continue;
		} else {
			if (str[i - 1] >= '0' && str[i - 1] < str[i + 1] && str[i + 1] <= '9') {
				while (1) {
					ans[k] = ans[k - 1] + 1;
					if (ans[k] == str[i + 1] - 1) {
						k++;
						break;
					}
					k++;
				}
			} else if (str[i - 1] >= 'a' && str[i - 1] < str[i + 1] && str[i + 1] <= 'z') {
				while (1) {
					ans[k] = ans[k - 1] + 1;
					if (ans[k] == str[i + 1] - 1) {
						k++;
						break;
					}
					k++;
				}
			} else if (str[i - 1] >= 'A' && str[i - 1] < str[i + 1] && str[i + 1] <= 'Z') {
				while (1) {
					ans[k] = ans[k - 1] + 1;
					if (ans[k] == str[i + 1] - 1) {
						k++;
						break;
					}
					k++;
				}
			} else {
				ans[k] = str[i];
				k++;
			}
		}
	}
	ans[k] = '\0';
	printf("%s", ans);
	return 0;
}


