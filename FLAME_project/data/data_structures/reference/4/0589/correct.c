#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
FILE *in;

typedef struct wordlist {
	char word[100];
	int cnt;
	struct wordlist *ll;
	struct wordlist *rr;
} node;
char c;
char s[100];
int idx;
node *hh;

void Insert(char *s) {
	int flag;
	node *p = hh->rr;
	for (;  p != NULL && (flag = strcmp(p->word, s)) < 0 && p->rr != NULL ; ) {
		p = p->rr;
	}
	if (p == NULL) {
		hh->rr = (node *) malloc (sizeof(node));
		p = hh->rr;
		p->ll = hh;
		p->cnt = 1;
		p->rr = NULL;
		strcpy(p->word, s);
	} else if (flag == 0) {
		p->cnt ++;
	} else if (flag > 0) {
		node *q = (node *) malloc (sizeof(node));
		q->cnt = 1;
		strcpy(q->word, s);
		q->ll = p->ll;
		p->ll->rr = q;
		q->rr = p;
		p->ll = q;
	} else if (p->rr == NULL) {
		node *q2 = p;
		p->rr = (node *) malloc (sizeof(node));
		p = p->rr;
		p->ll = q2;
		p->rr = NULL;
		strcpy(p->word, s);
		p->cnt = 1;
	}
}

int main(void) {
	in = fopen("article.txt", "r");
	hh = (node *)malloc(sizeof(node));
	hh->ll = NULL, hh->rr = NULL;
	node *p = hh;
	while ((c = fgetc(in)) != EOF) {
		c = tolower(c);
		if (c < 'a' || c > 'z') {
			continue;
		}
		idx = 0;
		s[idx++] = c;
		while ((c = fgetc(in)) != EOF) {
			c = tolower(c);
			if (c < 'a' || c > 'z')
				break;
			else
				s[idx++] = c;
		}
		s[idx] = '\0';
		Insert(s);
		if (c == EOF)
			break;
	}
	p = hh;
	while (p != NULL && p->rr != NULL) {
		p = p->rr;
		printf("%s %d\n", p->word, p->cnt);
	}
	return 0;
}

