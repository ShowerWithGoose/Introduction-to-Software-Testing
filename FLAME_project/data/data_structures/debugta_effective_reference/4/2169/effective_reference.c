#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char cot[80];
	int count;
} Wo;

int search(Wo *words, int sum, char word[]) {
	int i = 0;
	for (i = 0; i < sum; i++) {
		if (strcmp(words[i].cot, word) == 0)
			return i;
	}
	return -1;
}

int cmp(const Wo *e1, const Wo *e2) {
	return strcmp(e1->cot, e2->cot);
}

int main() {
	FILE *in;
	in = fopen("article.txt", "r");
	Wo words[20000] = {};
	int sum = 0;
	char line[1000] = {}, second[1000] = {};
	while (fgets(line, 1000, in) != NULL) {
		for (int i = 0; i < strlen(line); i++) {
			int k = 0;
			for (int i = i; i < strlen(line); i++) {
				if (line[i] >= 'a' && line[i] <= 'z')
					second[k++] = line[i];
				else if (line[i] >= 'A' && line[i] <= 'Z') {
					second[k++] = line[i] + 'a' - 'A';
				} else {
					i = i;
					break;
				}
			}
			if (search(words, sum, second) == -1) {
				strcpy(words[sum].cot, second);
				words[sum].count++;
				sum++;
			} else {
				words[search(words, sum, second)].count++;
			}
			memset(second, 0, sizeof(second));
		}
	}
	qsort(words, sum, sizeof(Wo), cmp);
	for (int i = 1; i < sum; i++) {
		printf("%s %d\n", words[i].cot, words[i].count);
	}
	return 0;
}
