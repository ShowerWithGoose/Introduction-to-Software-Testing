#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node{
	char word[32];
	int count;
	struct Node *next;
}Node;
Node *t=NULL;
int getword(FILE *fp,char *w){
	int c;
	while(!isalpha(c=fgetc(fp))){
		if(c==EOF)
			return c;
			else	continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int insertword(Node *p,char *w){
	Node *q;
	q = (Node *)malloc(sizeof(Node));
	if(q==NULL)
		return -1;
	strcpy(q->word ,w);
	q->count = 1;
	q->next = NULL;
	if(t==NULL){
		t = q;
	}
	else if(p==NULL){
		q->next = t;
		t = q;
	}
	else{
		q->next = p->next ;
		p->next =q;
	}
	return 0;
}
int searchword(char *w){
	Node *p,*q=NULL;
	for(p=t;p!=NULL;q=p,p=p->next ){
		if(strcmp(w,p->word )<0)
			break;
		else if(strcmp(w,p->word )==0){
			p->count ++;
			return 0;
		}
	}
	return insertword(q,w);
}
int main(){
	char word[32];
	FILE *in;
	Node *p;
	in = fopen("article.txt","r");
	while(getword(in,word)!=EOF)
	if(searchword(word)==-1){
		return -1;
	}
	for(p=t;p!=NULL;p=p->next )
		printf("%s %d\n",p->word ,p->count );
	return 0;
}

