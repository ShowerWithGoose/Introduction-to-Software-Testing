#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define Maxword 50

struct node {
	char word[Maxword];
	int count;
	struct node *next;
};
struct node *Wordlist = NULL; //全局变量

int legal(char c){
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int getword(FILE *fp, char *w) {
	char c;
	int count=0;
	while ((c = fgetc(fp)) != EOF) {
		if (!legal(c) && count<=0)
			continue;
		else if (!legal(c) && count>0)
			break;
		*w++=tolower(c);
		count++;
	}
	*w='\0';
	if (count>0)
		return 1;//成功读取
	return -1;
		
}
//文件指针设置为全局变量？？

void insertword(char *w) {
	struct node *q, *p=NULL, *r=NULL;
	q = (struct node *)malloc(sizeof (struct node));
	strcpy(q->word, w);
	q->count = 1;
	q->next = NULL;
	if (Wordlist == NULL) {
		Wordlist = q;
		return ;
	}
	for (p = Wordlist; p != NULL; r = p, p = p->next) {
		if (strcmp(w, p->word) < 0) { //插入p前
			if (p == Wordlist) {
				q->next = Wordlist;
				Wordlist = q;
				return ;
			} else {
				q->next=p;
				r->next=q;
				return ;
			}
		}
		else if (strcmp(w,p->word)==0){
			p->count++;
			free(q);
			q=NULL;
			return ;
		}
	}
	if (p==NULL)
		r->next=q;
	return ;
}

int main(int argc, char *argv[]) {
	FILE *in;
	char w[Maxword] = {};
	struct node *tmp;
	if ((in = fopen("article.txt", "r")) == NULL) {
		printf("Can't open the file!\n");
		return -1;
	}
	while (getword(in, w)!=EOF) {
		//printf("%s\n",w);
		insertword(w);
	}
	for(tmp=Wordlist;tmp!=NULL;tmp=tmp->next)
		printf("%s %d\n",tmp->word,tmp->count);

	return 0;
}
//che清零

