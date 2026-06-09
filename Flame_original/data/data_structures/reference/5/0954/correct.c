#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct multi {
	int coe;
	int index;
} s[1000], ss[1000], answer[1000];

int cmp(const struct multi *a, const struct multi *b) {
	return b->index - a->index;
}

int main() {
	int i = 0;
	int j = 0;
	char c;
	int flag = 0;
	int count = 0;
	while (1) {
		scanf("%d", &s[i].coe);
		scanf("%d", &s[i].index);
		c = getchar();
		i++;
		if (c == '\n') {
			break;
		}
	}
	while (1) {
		scanf("%d", &ss[j].coe);
		scanf("%d", &ss[j].index);
		c = getchar();
		j++;
		if (c == '\n') {
			break;
		}
	}
	int x;
	int y;
	for (int o = 0; o < i; o++) {
		for (int p = 0; p < j; p++) {
			flag = 0;
			x = s[o].coe * ss[p].coe;
			y = s[o].index + ss[p].index;
			for (int k = 0; k < count; k++) {
				if (y == answer[k].index) {
					answer[k].coe += x;
					flag = 1;
				}
			}
			if (flag == 0) {
				answer[count].index = y;
				answer[count].coe = x;
				count++;
			}
		}
	}
	qsort(answer, count, sizeof(answer[0]), cmp);
	for (int k = 0; k < count; k++) {
		if (answer[k].coe != 0)
			printf("%d %d ", answer[k].coe, answer[k].index);
	}
	return 0;
}
