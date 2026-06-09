#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a {
	char word[100];
	int n;
	struct a *next;
} list;
list *head;

int judge(char c) {
	if ( c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 2;
	else
		return 0;
}

int insertWord(char *word) {
	list *p, *q = NULL;
	for (p = head; p != NULL; q = p, p = p->next) {
		if (strcmp(p->word, word) > 0) {
			break;
		} else if (strcmp(p->word, word) == 0) {
			p->n++;
			return 0;
		}
	}
	if (q == 0) {		//插入到第一个前
		list *r = malloc(sizeof(list));
		r->n = 1;
		r->next = head;
		strcpy(r->word, word);
		head = r;

	} else {//在p前插入
		list *r = malloc(sizeof(list));
		r->n = 1;
		r->next = p;
		strcpy(r->word, word);
		q->next = r;
	}
}

int main(void) {
	FILE *in;
	in = fopen("article.txt", "r");
	char c, s[100] = {0};
	int i = 0;
	head = malloc(sizeof(list));
	head->n = 0;
	head->next = NULL;
	strcpy(head->word, "");

	while (c = fgetc(in), c != EOF) {

		if (judge(c) > 0) {
			s[0] = judge(c) == 1 ? c : c - 'A' + 'a';
			i = 0;
			while ( c = fgetc(in), judge(c) > 0 ) {
				s[++i] = judge(c) == 1 ? c : c - 'A' + 'a';
			}
			s[++i] = 0;
			insertWord(s);
		}
	}
	for (list *p = head->next; p != NULL; p = p->next) {
		printf("%s %d\n", p->word, p->n);
	}


	return 0;
}






