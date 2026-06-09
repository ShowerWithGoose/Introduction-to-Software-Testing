#define _CRT_SECURE_NO_WARNINGS
#define tolower(c) (c>='A'&&c<='Z'? c+'a'-'A':c)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 32
struct node {
	char word[MAXWORD];
	int count;
	struct node* link;
};
struct node* Wordlist = NULL;
int getWord(FILE* fp, char* w) {
	int c;
	while (!isalpha(c = fgetc(fp))) 
		if (c == EOF) {
			return c;
		}
		else {
			continue;
		}
	do {
		*w++ = tolower(c);
	} while (isalpha(c = fgetc(fp)));
	*w = '\0';
	return 1;
}
int insertWord(struct node* q, char* w) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	if (p == NULL) {
		return -1;
	}
	strcpy(p->word, w);
	p->count = 1;
	p->link = NULL;
	if (Wordlist == NULL) {
		Wordlist = p;
	}
	else if (q == NULL) {
		p->link = Wordlist;
		Wordlist = p;
	}
	else {
		p->link = q->link;
		q->link = p;
	}
	return 0;
}
int searchWord(char* w) {
	struct node* p, * q = NULL;
	for (p = Wordlist; p != NULL; q = p, p = p->link) {
		if (strcmp(w, p->word) < 0) {
			break;
		}
		else if(strcmp(p->word,w)==0) {
			(p->count)++;
			return 0;
		}
	}
	return insertWord(q, w);
}
int main() {
	char filename[32] = "article.txt", word[MAXWORD];
	FILE* fp;
	struct node* p;
	if ((fp = fopen(filename, "r")) == NULL) { //打开一个文件
		printf("can't open!\n");
		return -1;
	}
	while (getWord(fp, word) != EOF) //从文件中读入一个单词
		if (searchWord(word) == -1) { //在单词表中查找插入单词
			printf("Memory is full!\n");
			return -1;
		}
	for (p = Wordlist; p != NULL; p = p->link) //遍历输出单词表
	{
		printf("%s %d\n", p->word, p->count);
	}
	return 0;

}

