#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 32
struct node{
	char word[MAXWORD];
	int count;
	struct node *link;
}; 
struct node *Wordlist = NULL;
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord(struct node *p,char *w);
int isletter(char c);
int main()
{
	char word[MAXWORD];
	FILE *bfp;
	struct node *p;
	bfp = fopen("article.txt","r");
	if((bfp = fopen("article.txt","r"))==NULL){
		fprintf(stderr,"%s can't open!\n","article.txt");
		return -1;
	}
	while(getWord(bfp,word)!=EOF)
		if(searchWord(word)==-1){
			fprintf(stderr,"Memory is full!\n");
			return -1; 
		}
	for(p = Wordlist;p!=NULL;p=p->link)
		printf("%s %d\n",p->word,p->count);
	return 0;
}
int insertWord(struct node*p,char *w)
{
	struct node *q;
	
	q = (struct node*)malloc(sizeof(struct node));
	if(q ==NULL) return -1;
	strcpy(q->word,w);
	q->count = 1;
	q->link=NULL;
	if(Wordlist ==NULL)
		Wordlist = q;
	else if(p==NULL){
		q->link = Wordlist;
		Wordlist = q;
	}
	else{
		q->link = p->link;
		p->link = q;
	}
	return 0;
}

int searchWord(char*w)
{
	struct node *p,*q=NULL;
	for(p=Wordlist;p!=NULL;q = p,p = p->link){
		if(strcmp(w,p->word)<0)
			break;
		else if(strcmp(w,p->word)==0){
			p->count++;
			return 0;
		}
	}
	return insertWord(q,w);
}
int getWord(FILE *bfp, char *w) {
 int c, i = 0;
 while (isletter(c = fgetc(bfp)) == 0)
  if (c == EOF)
   return c;
  else
   continue;
 w[i++] = tolower(c);
 while ((c = fgetc(bfp)) != EOF) {
  if (isletter(c) == 0)
   break;
  w[i++] = tolower(c);
 }
 w[i] = '\0';
 return 1;
}

int isletter(char c) {
 if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
  return 1;
 else
  return 0;
}

