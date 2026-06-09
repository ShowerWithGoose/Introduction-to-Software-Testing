#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct NODE {
	char word[32];
	int count;
	struct NODE* link;
};

typedef struct NODE Node;
typedef struct NODE* Nodeptr;

int getword(FILE* IN, char[32]);

int main() {
	FILE* IN;
	char word[32];
	int judge;
	Nodeptr list = NULL, p, q, r;
	IN = fopen("article.txt", "r");
	while ((judge=getword(IN, word))) {
		if (judge == -1)
			continue;
		q = (Nodeptr)malloc(sizeof(Node));
		strcpy(q->word, word);
		q->count = 1;
		q->link = NULL;
		if (list == NULL)
			list = q;
		else {
			if (strcmp(list->word, word) > 0) {
				q->link = list;
				list = q;
				continue;
			}
			if (strcmp(list->word, word) == 0) {
				list->count++;
				continue;
			}
			p = list;
			for (r = list; r != NULL && strcmp(word, r->word) > 0; r = r->link) {
				p = r;
			}
			if (r == NULL) {
				p->link = q;
			}
			else if (strcmp(word, r->word) == 0) {
				r->count++;
			}
			else {
				q->link = p->link;
				p->link = q;
			}
		}
	}
	r = list;
	while (r != NULL) {
		printf("%s %d\n", r->word, r->count);
		r = r->link;
	}
	return 0;
}

int getword(FILE* IN, char word[32]) {
	int ch;
	int i = 0;
	while ((ch = fgetc(IN)) != EOF && ((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))) {
		if (ch >= 'A' && ch <= 'Z')
			ch = ch - 'A' + 'a';
		if (ch >= 'a' && ch <= 'z')
			word[i++] = ch;
	}
	word[i] = '\0';
	if (ch == EOF&&i==0)
		return 0;
	if (i == 0)
		return -1;
	return 1;
}
