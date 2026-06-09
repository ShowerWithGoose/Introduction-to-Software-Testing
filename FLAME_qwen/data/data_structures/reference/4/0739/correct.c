#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 46

struct node{
	char word[MAXWORD];
	int count;
	struct node *link;
} ;

struct node *first = NULL;

int Fgetword(FILE *fbp, struct node *crt){
	char ch;
	int k = 0;
	ch = fgetc(fbp);
	while(!isalpha(ch)){
		if(ch == EOF){
			return EOF;
		}
		else {
			ch = fgetc(fbp);
			continue;
		}
	}
	crt->word[k++] = tolower(ch);
	while(((ch = fgetc(fbp)) != EOF) && isalpha(ch)){
		crt->word[k++] = tolower(ch);
	}
	crt->word[k] = '\0';
	return 1;
}

void Searchword(struct node* crt){
	struct node *p, *q;
	
	if (strcmp(crt->word, first->word) < 0) {
		crt->link = first;
		first = crt;
		return;
	}
	
	p = first;
	for(q = first;q != NULL;p = q, q = q->link){
		if(strcmp(crt->word, q->word) == 0){
			q->count++;
			break;
		}
		else if(strcmp(crt->word, q->word) < 0){
			crt->link = q;
			p->link = crt; 
			break;
		}
	}
	if(q == NULL){
		p->link = crt;
	}
	return;
}
int main() {
	struct node *p, *q, *cr; 
	FILE *in;
	in = fopen("article.txt", "r");
	cr = (struct node *)malloc(sizeof(struct node));
	cr->count = 1;
	cr->link = NULL;
	while(Fgetword(in, cr) != EOF){
		if(first == NULL){
			first = (struct node*)malloc(sizeof(struct node));
			strcpy(first->word, cr->word);
			first->count = 1;
			first->link = NULL;
			cr = (struct node *)malloc(sizeof(struct node));
			cr->count = 1;
			cr->link = NULL;
			continue; 
		}
		Searchword(cr);
		cr = (struct node *)malloc(sizeof(struct node));
		cr->count = 1;
		cr->link = NULL;
		//memset(cr->word, 0, MAXWORD);
	}
	for(p = first;p != NULL;p = p->link){
		printf("%s %d\n", p->word, p->count);
	}
	return 0;
}





