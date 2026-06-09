#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define WORDLEN 32
struct st{
	char word[WORDLEN];
	int cnt;
	struct st *next;
};
typedef struct st Node;
typedef struct st *Nodeptr;
int getword(FILE *, char *);
int main()
{
	char word[WORDLEN];
	Nodeptr list = NULL, p, q, r;
	FILE *fp;
	fp = fopen("article.txt", "r");
	q = (Nodeptr)malloc(sizeof(Node));
	list = q;
	q->next = NULL;
	while( getword(fp, word)!=EOF ) {
		for( p=list->next, q=list; 1; p=p->next, q=q->next ) {//q为p前序结点的指针 
			if( p!=NULL && strcmp(word, p->word)==0 ) {
				p->cnt++;
				break;
			}
			else if( p==NULL || strcmp(word, p->word)<0 ) {
				r = (Nodeptr)malloc(sizeof(Node));
				strcpy(r->word, word);
				r->cnt = 1;
				r->next = p;
				q->next = r;
				break;
			}
		}
	}
	for( p=list->next; p!=NULL; p=p->next ) {
		printf("%s %d\n", p->word, p->cnt);
	}
	fclose( fp );
	return 0;
}
int getword(FILE *fp, char *w)
{
	char c;
	int num = 0;
	while( (c=fgetc(fp))!=EOF ) {
		if( !isalpha(c) && num==0 ) continue;
		else if( !isalpha(c) ) break;
		else {
			w[num++] = tolower(c);
		}
	}
	w[num] = '\0';
	if( num > 0 ) return 1;
	else return EOF;
}

