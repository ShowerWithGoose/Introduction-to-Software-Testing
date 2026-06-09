#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char wor[32];
struct Word {
	char word[32];
	int sumw;
	struct Word *next;
};
struct Word *wordlist = NULL;
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
void insertword(struct Word *p, struct Word *q) {
	struct Word *t;
	t = (struct Word *)malloc(sizeof(struct Word));
	strcpy(t->word, wor);
	t->sumw = 1;
	t->next = NULL;
	if (wordlist == NULL) {
		wordlist = t;
	} else if (q == NULL) {
		t->next = wordlist;
		wordlist = t; //保护头指针
	} else {
		q->next = t;
		t->next = p;
	}
}
void searchword() {
	struct Word *p, *q = NULL;
	for (p = wordlist; p != NULL; q = p, p = p->next) {
		if (strcmp(p->word, wor) > 0) {
			insertword(p, q);
			break;
		} else if (strcmp(p->word, wor) == 0) {
			p->sumw++;
			break;
		}
	}
	if(p==NULL){
		insertword(p, q);
	}
}
int main() {
	struct Word *p;
	FILE *in;
	in = fopen("article.txt", "r");
	while (getword(in, wor) != EOF) {
		searchword();
	}
	for (p = wordlist; p != NULL; p = p->next) {
		printf("%s %d\n", p->word, p->sumw);
	}
	fclose(in);
	return 0;
}

