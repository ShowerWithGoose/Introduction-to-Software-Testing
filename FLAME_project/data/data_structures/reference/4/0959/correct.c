#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sort {
	char word[10];
	int count;
} qyx[2000], qyx1[2000], qyx2;



int main() {
	FILE *in;
	char x[3000];
	in = fopen("article.txt", "r");
	int i = 0;
	int j = 0;
	int flag = 0;
	char gju[10];
	while (fgets(x, 2000, in) != NULL) {
		for (int k = 0; k < strlen(x) + 1; k++) {
			if ((x[k] < 91 && x[k] > 64) || (x[k] > 96 && x[k] < 123)) {
				qyx[i].word[j++] = x[k];
				flag = 1;
			} else if (flag != 0) {
				qyx[i].word[j] = '\0';
				qyx[i++].count = 1;
				j = flag = 0;
			}
		}
	}
	for (int u = 0; u < i; u++) {
		for (int q = 0; q < strlen(qyx[u].word); q++) {
			if (qyx[u].word[q] < 97)
				qyx[u].word[q] += 32;
		}
	}
	for (int p = 0; p < i; p++) {
		for (int j = p + 1; j < i; j++) {
			if (strcmp(qyx[p].word, qyx[j].word) == 0) {
				strcpy(qyx[j].word, "\0");
				qyx[p].count += qyx[j].count;
			}
			if (strcmp(qyx[p].word, qyx[j].word) > 0) {
				qyx2 = qyx[p];
				qyx[p] = qyx[j];
				qyx[j] = qyx2;
			}
		}
	}
	for (int p = 0; p < i; p++) {
		if (strlen(qyx[p].word) != 0)
			printf("%s %d\n", qyx[p].word, qyx[p].count);
	}
}
