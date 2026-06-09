#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char cot[80];
	int count;
} Wo;

int search(Wo *head, int flag, char word[]) {
	int p = 0;
	for (p = 0; p < flag; p++) {
		if (strcmp(head[p].cot, word) == 0)
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
	Wo head[20000] = {};
	int flag = 0;
	char article[1000] = {}, piece[1000] = {};
	while (fgets(article, 1000, in) != NULL) {
		for (int p = 0; p < strlen(article); p++) {
			int c = 0;
			for (int i = p; i < strlen(article); i++) {
				if (article[i] >= 'a' && article[i] <= 'z')
					piece[c++] = article[i];
				else if (article[i] >= 'A' && article[i] <= 'Z') {
					piece[c++] = article[i] + 'a' - 'A';
				} else {
					p = i;
					break;
				}
			}
			if (search(head, flag, piece) == -1) {
				strcpy(head[flag].cot, piece);
				head[flag].count++;
				flag++;
			} else {
				head[search(head, flag, piece)].count++;
			}
			memset(piece, 0, sizeof(piece));
		}
	}
	qsort(head, flag, sizeof(Wo), cmp);
	for (int i = 1; i < flag; i++) {
		printf("%s %d\n", head[i].cot, head[i].count);
	}
	return 0;
}
