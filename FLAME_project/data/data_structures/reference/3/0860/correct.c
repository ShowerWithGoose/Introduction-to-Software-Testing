#include <stdio.h>
#include <string.h>

int main() {
	int len, bit, i = 0;
	char num[105], *loc, *p;
	gets(num);
	len = strlen(num);
	loc = strchr(num, '.');
	if ((loc - num) >= 2 && (num[0] - '0') > 0) {
		bit = loc - num - 1;
		printf("%c%c", num[0], '.');
		i++;
		while (num[i] != '\0') {
			if (num[i] != '.')
				printf("%c", num[i]);
			i++;
		}
		printf("e%d", bit);
		return 0;
	} else if ((loc - num) == 1 && (num[0] - '0') > 0) {
		printf("%s", num);
		printf("%c%c", 'e', '0');
		return 0;
	} else if (num[0] == '0') {
		for (p = loc + 1; (*p) != '\0'; p++) {
			if (*p != '0') {
				bit = p - loc;
				break;
			}
		}
		if (p - num == len - 1) {
			printf("%se%c%d", p, '-', bit);
		} else
			printf("%c%c%se%c%d", *p, '.', p + 1, '-', bit);
	}
	return 0;
}


