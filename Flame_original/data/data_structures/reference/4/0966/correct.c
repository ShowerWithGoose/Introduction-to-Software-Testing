//article
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct word {
	char op[100];
	int n;
	struct word *LINK;
};
typedef struct word* WORD;
FILE *in;
int getWord(FILE *fp, char *w);
int str_cmp(char *a, char *b);
int main() {
	char fp[100];
	in = fopen("article.txt", "r");
	WORD first = NULL, last = NULL, jp = NULL, tp = NULL, kp = NULL;
	while (getWord(in, fp) != EOF) {
		jp = (WORD)malloc(sizeof(struct word));
		strcpy(jp->op, fp);
		jp->n = 1;
		jp->LINK = NULL;
		if (first == NULL) {
			first = last = jp;
		} else {
			tp = first;
			while (str_cmp(tp->op, jp->op) < 0 && tp != NULL) {
				kp = tp;
				tp = tp->LINK;
			}
			if (tp == NULL) {
				last->LINK = jp;
				last = jp;
			} else if (str_cmp(tp->op, jp->op) == 0) {
				tp->n += jp->n;
			} else if (tp == first) {
				jp->LINK = first;
				first = jp;
			}  else {
				jp->LINK = tp;
				kp->LINK = jp;
			}
		}
	}
	jp = first;
	while (jp != NULL) {
		printf("%s %d\n", jp->op, jp->n);
		tp = jp;
		jp = tp->LINK;
		free(tp);
	}
	return 0;
}




int getWord(FILE *fp, char *w) {
	int c;
	while (!isalpha(c = fgetc(fp))) {
		if (c == EOF)return c;
		else continue;
	}
	do {
		*w++ = tolower(c);
	} while (isalpha(c = fgetc(fp)));
	*w = '\0';
	return 1;
}
int str_cmp(char *a, char *b) {
	int i;
	if (a == NULL || b == NULL) {
		return 0;
	}
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
		if (a[i] > b[i]) {
			return 1;
		} else if (a[i] < b[i]) {
			return -1;
		}
	}
	if (a[i] == '\0') {
		if (b[i] != '\0') {
			return -1;
		} else {
			return 0;
		}
	}
	return 1;
}

