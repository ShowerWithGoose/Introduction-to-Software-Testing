#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Word {
	char s[20];
	int time;
} word[1024];

char str[10000];

int cmp(const void *a, const void *b) {
	struct Word *p = (struct Word *)a;
	struct Word *q = (struct Word *)b;
	return strcmp(p->s, q->s);
}

int main() {
	int cnt = 0, k = 0;
	char c;
	FILE *in;
	in = fopen("article.txt", "r");
	while ((c = fgetc(in)) != EOF) {
		str[cnt++] = c; //所有字符读入str
	}
	cnt = 0; //用来记录单词个数
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			word[cnt].s[k] = tolower(str[i]);
			k++;
		} else {
			cnt++;//如果不是单词。就把k归零，且单词数量+1
			k = 0;
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (isalpha(word[i].s[0]))
			word[i].time = 1;
	}
	qsort(word, cnt, sizeof(word[0]), cmp);

	for (int i = 0; i < cnt - 1; i++) {
		if (strcmp(word[i].s, word[i + 1].s) == 0) { //单词相同
			word[i + 1].time += word[i].time;
			word[i].time = 0;
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (word[i].time != 0) {
			printf("%s %d\n", word[i].s, word[i].time);
		}
	}
	return 0;
}

