#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *o;

struct word {
	char wor[32];
	int cishu;
} ci[99999];

int comp(const void *a, const void *g) {
	struct word *h = (struct word *)a;
	struct word *l = (struct word *)g;
	return strcmp(h->wor, l->wor);
}
int  b, c;
char input[26], inp;

int main() {
	o = fopen("article.txt", "r");
	while ((inp = fgetc(o)) != EOF) {
		if ((inp >= 'a' && inp <= 'z') || (inp >= 'A' && inp <= 'Z')) {
			if (inp >= 'A' && inp <= 'Z') {
				inp = inp + 32;
				input[b] = inp;
				b++;
			} else {
				input[b] = inp;
				b++;
			}
		} else if (input[0] >= 'a' && input[0] <= 'z') {
			struct word *u;
			if (c == 0) {
				strcpy(ci[0].wor, input);
				ci[0].cishu++;
				c++;
			} else {
				qsort(ci, c, sizeof(struct word), comp);
				u = bsearch(input, ci, c, sizeof(struct word), comp);
				if (u == NULL) {
					strcpy(ci[c].wor, input);
					ci[c].cishu++;
					c++;
				} else
					u->cishu++;
			}
			memset(input, 0, sizeof(input));
			b = 0;
		}

	}
	if (input[0] >= 'a' && input[0] <= 'z') {
		struct word *u;
		if (c == 0) {
			strcpy(ci[0].wor, input);
			ci[0].cishu++;
			c++;
		} else {
			qsort(ci, c, sizeof(struct word), comp);
			u = bsearch(input, ci, c, sizeof(struct word), comp);
			if (u == NULL) {
				strcpy(ci[c].wor, input);
				ci[c].cishu++;
				c++;
			} else
				u->cishu++;
		}
		memset(input, 0, sizeof(input));
	}
	qsort(ci, c, sizeof(struct word), comp);
	for (int y = 0; y < c; y++) {
		printf("%s ", ci[y].wor);
		printf("%d", ci[y].cishu);
		printf("\n");
	}
	fclose(o);
	return 0;
}
