#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
	char word[100];
	int count;
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodep;
Nodep head = NULL;

int get(FILE *fp1, char word[]) {
	int i = 0;
	char c;
	while ((c = fgetc(fp1)) != EOF) {
		if (isalpha(c)) {
			word[i] = tolower(c);
			i++;
		} else if (i > 0) {
			word[i] = '\0';
			return 0;
		}

	}
	return -1;
}

int search_and_paixu(char *c) {
	Nodep p, q = NULL, r;
	for (p = head; p != NULL; p = p->next) {
		if (strcmp(c, p->word) == 0) {
			p->count++;
			return 0;
		} else if (strcmp(c, p->word) < 0) {
			break;
		}
		q = p;
	}
	r = (Nodep)malloc(sizeof(Node));
	strcpy(r->word, c);
	r->count = 1;
	r->next = NULL;
	if (head == NULL) {
		head = r;
	} else if (q == NULL) {
		r->next = head;
		head = r;
	} else {
		r->next = q->next;
		q->next = r;
	}
	return 0;


}

int main(void) {
	char word[100];
	Nodep p;
	FILE *fp1 = fopen("article.txt", "r");
	while (get(fp1, word) != -1) {
		search_and_paixu(word);
	}
	for (p = head; p != NULL; p = p->next) {
		printf("%s %d\n", p->word, p->count);
	}
	return 0;

}


