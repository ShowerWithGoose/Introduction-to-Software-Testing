#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int time;
	char words[20];
	struct node *next;
};
struct node *head = NULL;
char read_word[20];
void searchword(char *a);
void insertword(struct node *p, char *a);

int main() {
	FILE *in;
	char c;
	int cnt = 0;
	in = fopen("article.txt", "r");
	struct node *t;
	while (fscanf(in, "%c", &c) != EOF) {
		if (c >= 'a' && c <= 'z')
			read_word[cnt++] = c;
		else if (c >= 'A' && c <= 'Z') {
			c = c - 'A' + 'a';
			read_word[cnt++] = c;
		} else if (read_word[0] != '\0') {
			searchword(read_word);
			memset(read_word, 0, sizeof(read_word));
			cnt = 0;
		}
	}
	t = head;
	while (t != NULL) {
		printf("%s %d\n", t->words, t->time);
		t = t->next;
	}
	fclose(in);
	return 0;
}

void searchword(char *a) {
	struct node *p, *q = NULL;
	for (p = head; p != NULL; q = p, p = p->next) {
		if (strcmp(a, p->words) == 0) {
			p->time++;
			return;
		}
		if (strcmp(a, p->words) < 0)
			break;
	}
	insertword(q, a);
	return;
}

void insertword(struct node *q, char *a) {
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->time = 1;
	strcpy(p->words, a);
	p->next = NULL;
	if (head == NULL)
		head = p;
	else if (q == NULL) {
		p->next = head;
		head = p;
	} else {
		p->next = q->next;
		q->next = p;
	}
	return;
}
