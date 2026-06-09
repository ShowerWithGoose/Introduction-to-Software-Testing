#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 128
#define MAXLEN 1024

struct words{
	char word[MAXSIZE];
	int count;
	struct words *link;
};
typedef struct words *Wordsptr, Words;
Wordsptr head = NULL, tail, p, r;

char w[MAXSIZE];

int judge(char c) {
	return (c >= 'a' && c <='z') ? 1 : 0;
}

void lower(char *s) {
	int i, len = strlen(s);
	for (i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}

int getword(char *s) {
	int i = 0,len = strlen(s), j;
	while (i < len) {
		j = 0;
		if (!judge(s[i])) i++;
		while (judge(s[i])) {
			w[j] = s[i];
			j++;
			i++;
		}
		w[j] = '\0';
		if (judge(w[0]))
			insert(w);
	}
}

void insert(char *s) {
	r = (Wordsptr)malloc(sizeof(Words));
	strcpy(r->word, s);
	r->count = 1;
	r->link = NULL;
	if (head == NULL) {
		head = tail = r;
	}
	else {
		tail = head;
		while (1) {
			if (tail == NULL) {
				p->link = r;
				return;
			}
			else if (strcmp(head->word, s) > 0) {
				r->link = head;
				head = r;
				return;
			}
			else if (strcmp(tail->word, s) == 0) {
				tail->count++;
				return;
			}
			else if (strcmp(tail->word, s) < 0) {
				p = tail;
				tail = tail->link;
			}
			else if (strcmp(tail->word, s) > 0) {
				r->link = tail;
				p->link = r;
				return; 
			}
		}
	}
}

int main() {
	FILE *in;
	in = fopen("article.txt", "r");
	
	char str[MAXLEN];
	while (fgets(str, MAXLEN - 1, in) != NULL) {
		lower(str);
		getword(str);
	}
	
	tail = head;
	while (tail != NULL) {
		printf("%s %d\n", tail->word, tail->count);
		tail = tail->link;
	}
	
	fclose(in);
	
	return 0;
}

