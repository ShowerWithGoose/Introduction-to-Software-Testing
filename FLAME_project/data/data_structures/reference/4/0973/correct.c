#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char cot[80];
	int count;
} Wo;

int search(Wo *line, int sum, char word[]) {
	int p = 0;
	for (p = 0; p < sum; p++) {
		if (strcmp(line[p].cot, word) == 0)
			return p;
	}
	return -1;
}

int cmp(const Wo *e1, const Wo *e2) {
	return strcmp(e1->cot, e2->cot);
}

int main() {
	FILE *in;
	in = fopen("article.txt", "r");
	Wo line[20000] = {};
	int sum = 0;
	char first[1000] = {}, second[1000] = {};
	while (fgets(first, 1000, in) != NULL) {
		for (int p = 0; p < strlen(first); p++) {
			int k = 0;
			for (int i = p; i < strlen(first); i++) {
				if (first[i] >= 'a' && first[i] <= 'z')
					second[k++] = first[i];
				else if (first[i] >= 'A' && first[i] <= 'Z') {
					second[k++] = first[i] + 'a' - 'A';
				} else {
					p = i;
					break;
				}
			}
			if (search(line, sum, second) == -1) {
				strcpy(line[sum].cot, second);
				line[sum].count++;
				sum++;
			} else {
				line[search(line, sum, second)].count++;
			}
			memset(second, 0, sizeof(second));
		}
	}
	qsort(line, sum, sizeof(Wo), cmp);
	for (int i = 1; i < sum; i++) {
		printf("%s %d\n", line[i].cot, line[i].count);
	}
	return 0;
}
