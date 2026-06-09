#include <stdio.h>
#include <string.h>
#include <malloc.h>
char line[1024];
char wod[100];
typedef struct node {
	char word[100];
	int num;
	struct node* succ;
	struct node* pred;
}Node, *wordlist;
void lower(int len) {
	for (int i = 0; i < len; i++) {
		if ('A' <= line[i] && line[i] <= 'Z') {
			line[i] = line[i] + ('a' - 'A');
		}
	}
	return;
}
void compare(wordlist q) {
	wordlist start = q;
	int color = 0;
	int fist = 0;
	while(0 <= (q->num)) {
		if (strcmp(wod, q->word) == 0) {
			q->num = (q->num) + 1;
			return;
		}
		else if (strcmp(wod, q->word) < 0 && fist == 0) {
			fist = 1;
			color = 1;
			wordlist inser = (wordlist)malloc(sizeof(Node));
			inser->num = 1;
			strcpy(inser->word, wod);
			wordlist t = q->pred;
			t->succ = inser;
			inser->pred = t;
			inser->succ = q;
			q->pred = inser;
			return;
		}
		else if (0 < strcmp(wod, q->word)) {
			q = q->succ;
		}
	}
	if (color == 0) {
		strcpy(q->word, wod);
		q->num = 1;
		wordlist t = (wordlist)malloc(sizeof(Node));
		t->num = -1;
		t->pred = q;
		q->succ = t;
		t->succ = NULL;
		memset(t->word, 0, sizeof(char));
		return;
	}
}
void search(wordlist q, int len) {
	int k = 0;
	wordlist start = q;
	lower(len);
	for (int i = 0; i < len; i++) {
		if ('a' <= line[i] && line[i] <= 'z') {
			while('a' <= line[i] && line[i] <= 'z') {
				wod[k++] = line[i++];
			}
			i--;
			wod[k] = '\0';
			k = 0;
			compare(q);
		}
	}
}
int main() {
	Node list;
	wordlist start = &list;
	start->num = 0;
	start->pred = NULL;
	start->succ = NULL;
	memset(start->word, 0, sizeof(char));
	wordlist m = (wordlist)malloc(sizeof(Node));
	m->num = -1;
	m->pred = start;
	start->succ = m;
	m->succ = NULL;
	memset(m->word, 0, sizeof(char));
	FILE *in;
	in = fopen("article.txt","r");
	while(fgets(line, 1023, in) != NULL) {
		int len = strlen(line);
		search(start, len);
	}
	while(0 <= (start->num)) {
		if ((start->num) == 0) {
			start = start->succ;
			continue;
		}
		printf("%s ", start->word);
		printf("%d\n", start->num);
		start = start->succ; 
	}
	return 0;
}

