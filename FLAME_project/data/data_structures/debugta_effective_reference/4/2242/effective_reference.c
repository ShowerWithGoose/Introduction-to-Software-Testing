#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char wor[32];
struct Word {
	char word[32];
	int time;
	struct Word *next;
};
struct Word *fir = NULL;
int getword(FILE *fp, char *w) {
	char c;
	while (!isalpha(c = fgetc(fp))) {
		if (c == EOF) {
			return c;
		} else continue;
	}
	while (isalpha(c)) {
		*w++ = tolower(c);
		c = fgetc(fp);
	}
	*w = '\0';
	return 1;
}
void insertword(struct Word *q, struct Word *p) {
	struct Word *n;
	n = (struct Word *)malloc(sizeof(struct Word));
	strcpy(n->word, wor);
	n->time = 1;
	n->next = NULL;
	if (fir == NULL) {
		fir = n;
	} else if (p == NULL) {
		n->next = fir;
		fir = n; //保护头指针
	} else {
		p->next = n;
		n->next = q;
	}
}
void searchword() {
	struct Word *q, *p = NULL;
	for (q = fir; q != NULL; p = q, q = q->next) {
		if (strcmp(q->word, wor) > 0) {
			insertword(q, p);
			break;
		} else if (strcmp(q->word, wor) == 0) {
			q->time++;
			break;
		}
	}
	if(q==NULL){
		insertword(q, p);
	}
}
int main() {
	struct Word *q;
	FILE *in;
	in = fopen("article.txt", "r");
	while (getword(in, wor) != EOF) {
		searchword();
	}
	for (q = fir; q != NULL; q = q->next) {
		printf("%s %d\n", q->word, q->time);
	}
	fclose(in);
	return 0;
}

