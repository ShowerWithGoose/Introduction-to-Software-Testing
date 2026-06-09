#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Words {
	char word[100];
	int num;
};

int cmp(const void* a, const void* b)
{
	struct Words* c = (struct Words*)a;
	struct Words* d = (struct Words*)b;
	return strcmp(c->word, d->word);
}

int isalpha(char a) {
	if (('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z')) {
		return 1;
	}
	return 0;
}

char lower(char a) {
	if ('A' <= a && a <= 'Z') {
		a += 32;
	}
	return a;
}

int main() {
	struct Words words[1000];
	char in, txt[10086];
	int index = 0, wordlen = 0, len = 0;
	FILE* fp = fopen("article.txt", "r");
	while ((in = fgetc(fp)) != EOF) {
		txt[len++] = in;
	}
	len--;
	for (int i = 0; i < len; i++) {
		if (isalpha(txt[i])) {
			words[index].word[wordlen++] = lower(txt[i]);
		}
		else {
			words[index].word[wordlen] = '\0';
			index++;
			wordlen = 0;
		}
	}
	qsort(words, index, sizeof(words[0]), cmp);
	for (int i = 0; i < index; i++) {
		if (strlen(words[i].word)) {
			words[i].num = 1;
		}
		else {
			words[i].num = 0;
		}
	}
	for (int i = 0; i < index - 1; i++) {
		for (int j = i + 1; j < index; j++) {
			if (strcmp(words[i].word, words[j].word) == 0) {
				words[i].num += words[j].num;
				words[j].num = 0;
			}
		}
	}
	for (int i = 0; i < index; i++) {
		if (words[i].num != 0) {
			printf("%s %d\n", words[i].word, words[i].num);
		}
	}
	
}
