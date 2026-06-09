#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  32
#define  LETTER  'a'
struct node {
	char word[MAXWORD];
	int n;
	struct node *link;
};
struct node *head = NULL; 
int searchWord(char *getin);
int getWord(FILE *bfp,char *getin);
int insertWord( struct node *p, char *getin);
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
	for(p=head; p != NULL; p=p->link)
		printf("%s %d\n", p->word, p->n);
	fclose(bfp);
	return 0;
}
int insertWord(struct node  *p, char *getin) {
	struct node  *q;
	q = (struct node * )malloc(sizeof(struct node));
	if(q == NULL) return -1;
	strcpy(q->word, getin);
	q->n = 1;
	q->link = NULL;
	if(head == NULL)
		head = q;
	else if (p == NULL) {
		q->link = head;
		head = q;
	} else {
		q->link = p->link;
		p->link = q;
	}
	return 0;
}
int searchWord(char *getin) {
	struct  node *p, *q=NULL;
	for(p=head; p != NULL; q=p,p=p->link) {
		if(strcmp(getin, p->word) < 0)
			break;
		else if(strcmp(getin, p->word) == 0) {
			p->n++;
			return 0 ;
		}
	}
	return insertWord(q, getin);
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




