#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  32
#define  LETTER  'a'
struct node {
	char s[MAXWORD];
	int count;
	struct node *link;
};
struct node *list = NULL; 
int searchWord(char *w);
int getWord(FILE *fp,char *w);
int insertWord( struct node *p, char *w);
char type(int c) {
	if( c >= 'a' && c <= 'z'|| c >= 'A' && c <= 'Z')
		return ( LETTER );
	else return (c);
}
int main() {
	char s[MAXWORD];
	FILE *fp;
	fp = fopen("article.txt", "r");
	struct node *p;
	while( getWord(fp,s) != EOF) {
		//printf("%s ",word);
		searchWord(s);
	}
	for(p=list; p != NULL; p=p->link)
		printf("%s %d\n", p->s, p->count);
	fclose(fp);
	return 0;
}
int insertWord(struct node  *r, char *w) {
	struct node  *q;
	q = (struct node * )malloc(sizeof(struct node));
	if(q == NULL) return -1;
	strcpy(q->s, w);
	q->count = 1;
	q->link = NULL;
	if(list == NULL)
		list = q;
	else if (r == NULL) {
		q->link = list;
		list = q;
	} else {
		q->link = r->link;
		r->link = q;
	}
	return 0;
}
int searchWord(char *w) {
	struct  node *p, *q=NULL;
	for(p=list; p != NULL; q=p,p=p->link) {
		if(strcmp(w, p->s) < 0)
			break;
		else if(strcmp(w, p->s) == 0) {
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




