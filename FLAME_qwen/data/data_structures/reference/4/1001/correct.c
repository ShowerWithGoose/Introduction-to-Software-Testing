#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef struct word_num
{
	char s[50];
	int num;
	struct word_num* next;
}word;

void linksort(word** head1);
int read(FILE* in, char* s);

int main()
{
	int cmp=0;
	char* k = NULL, tmp[50];
	word* head = NULL, * p = NULL, * q = NULL, * r = NULL, *m = NULL;
	FILE* in;
	in = fopen("article.txt", "r");
	p = (word*)malloc(sizeof(word));
	head = q = p;
	while (read(in, p->s) != EOF) {
		p->num = 1;
		p = (word*)malloc(sizeof(word));
		q->next = p;
		q = p;
	}
	q->next = NULL;
	p = head;
	q = p->next;
	while (q != NULL) {
		q = q->next;
		p = p->next;
		if (q->next == NULL) {
			p->next = NULL;
			free(q);
			break;
		}
	}
	q = head;
	while (q != NULL) {
		k = q->s;
		for (int i = 0; k[i] != '\0'; i++) {
			if (k[i] >= 'A' && k[i] <= 'Z') {
				k[i] = k[i] + 'a' - 'A';
			}
		}
		q = q->next;
	}
	q = head;
	while (q != NULL) {
		cmp = strcmp(head->s, q->s);
		if (cmp > 0) {
			strcpy(tmp, q->s);
			strcpy(q->s, head->s);
			strcpy(head->s, tmp);
		}
		q = q->next;
	}
	q = head->next;
	p = q->next;
	while (p != NULL) {
		while (q != p) {
			cmp = strcmp(p->s, q->s);
			if (cmp < 0) {
				strcpy(tmp, q->s);
				strcpy(q->s, p->s);
				strcpy(p->s, tmp);
			}
			q = q->next;
		}
		q = head->next;
		p = p->next;
	}
	m = head;
	p = m->next;
	while (p != NULL) {
		cmp = strcmp(p->s, m->s);
		if (cmp == 0) {
			m->next = p->next;
			free(p);
			p = m->next;
			m->num++;
			continue;
		}
		m = m->next;
		p = p->next;
	}
	p = head;
	while (p != NULL) {
		printf("%s %d\n", p->s, p->num);
		p = p->next;
	}
	return 0;
}

int read(FILE* in, char* s)
{
	int c;
	while (c = fgetc(in)) {
		if (c == EOF)
			return c;
		else if (isalpha(c)) {
			*s = c;
			s++;
			break;
		}
	}
	while (isalpha(c = fgetc(in))) {
		if (c >= 'A' && c <= 'Z') {
			c = c + 'a' - 'A';
		}
		*s = c;
		s++;
		*s = '\0';
	}
	return c;
}
