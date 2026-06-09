#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct Word{
	char word[105];
	int count;
	struct Word *next;
};
struct Word *word_list=NULL;
int get_word(FILE *fp,char *w);
int search_word(char *w);

int insert_word(struct Word *p,char *w);
int main(){
	FILE *in;
	char word[105];
	struct Word *p;
	
	if((in=fopen("article.txt","r"))==NULL){
		fprintf(stderr,"can't open!");
		return -1;
	}
	while(get_word(in,word)!=EOF)
		//printf("%s ",word);
		if(search_word(word)==-1){
			fprintf(stderr,"memory is full");
			return -1;
		}
	
	
	for(p=word_list;p!=NULL;p=p->next){
		printf("%s %d\n",p->word,p->count);
	}
	fclose(in);
	return 0;
} 
int get_word(FILE *fp,char *w){
	int c;
	
	while(!isalpha(c=fgetc(fp))){
		if(c==EOF) return c;
		else continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int search_word(char *w){
	struct Word *p,*q=NULL;
	for(p=word_list;p!=NULL;q=p,p=p->next){
		if(strcmp(p->word,w)>0) break;
		else if(strcmp(p->word,w)==0){
			p->count++;
		    return 0;
		} 
	}
	return insert_word(q,w);
}
int insert_word(struct Word *p,char *w){
	struct Word *q;
	q=(struct Word *)malloc(sizeof(struct Word));
	if(q==NULL) return -1;
	strcpy(q->word,w);
	q->count=1;
	q->next=NULL;
	if(word_list==NULL){
		word_list=q;
	}
	else if(p==NULL){
		q->next=word_list;
		word_list=q;
	}
	else {
		q->next=p->next;
		p->next=q;
	}
	return 0;
}









