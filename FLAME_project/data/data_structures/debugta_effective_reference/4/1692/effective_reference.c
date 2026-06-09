#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  32
#define  LETTER  'a'
struct node {
	char word[MAXWORD];
	int count;
	struct node *link;
};
struct node *Wordlist = NULL; 
int searchWord(char *w);
int getWord(FILE *bfp,char *w);
int insertWord( struct node *p, char *w);
char type(int c) {
	if( c >= 'a' && c <= 'z'|| c >= 'A' && c <= 'Z')
		return ( LETTER );
	else return (c);
}
int main() {
	char word[MAXWORD];
	FILE *bfp;
	bfp = fopen("article.txt", "r");
	struct node *p;
	while( getWord(bfp,word) != EOF) {
		//printf("%s ",word);
		searchWord(word);
	}
	for(p=Wordlist; p != NULL; p=p->link)
		printf("%s %d\n", p->word, p->count);
	fclose(bfp);
	return 0;
}
int insertWord(struct node  *r, char *w) {
	struct node  *t;
	t = (struct node * )malloc(sizeof(struct node));
	if(t == NULL) return -1;
	strcpy(t->word, w);
	t->count = 1;
	t->link = NULL;
	if(Wordlist == NULL)
		Wordlist = t;
	else if (r == NULL) {
		t->link = Wordlist;
		Wordlist = t;
	} else {
		t->link = r->link;
		r->link = t;
	}
	return 0;
}
int searchWord(char *w) {
	struct  node *p, *q=NULL;
	for(p=Wordlist; p != NULL; q=p,p=p->link) {
		if(strcmp(w, p->word) < 0)
			break;
		else if(strcmp(w, p->word) == 0) {
			p->count++;
			return 0 ;
		}
	}
	return insertWord(q, w);
}
int getWord(FILE *fp,char *s) {
	int c,  i = 0;
	while(type(c=fgetc(fp))!= LETTER)
		if(c == EOF) return c;
		else continue;
	s[i++] = tolower(c);
	while((c=fgetc(fp))!=EOF) {
		if(type(c)!=LETTER)
			break;
		s[i++] = tolower(c);
	}
	s[i++]='\0';
	return 1;
}




