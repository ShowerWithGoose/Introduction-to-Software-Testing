#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	char word[50];
	int num;
	struct node* next;
	struct node* fore;
};
void lprintf(struct node*);
void add(struct node*,char*);
int getword(char*,FILE*);
int main(){
	FILE *f=fopen("article.txt","r");
	char s[50];
	struct node* list=(struct node*)malloc(sizeof(struct node));
	list->next=list->fore=NULL;
	getword(list->word,f);
	list->num=1;
	for(;getword(s,f);){
		add(list,s);
	}
	lprintf(list);
	fclose(f);
	return 0;
}
void add(struct node* list,char* s){
	struct node* first=list;
	struct node* p=(struct node*)malloc(sizeof(struct node));
	for(;first->fore!=NULL;first=first->fore);
	for(;strcmp(s,first->word)>0;first=first->next){
		if(first->next==NULL){
			first->next=p;
			p->fore=first;
			p->next=NULL;
			strcpy(p->word,s);
			p->num=1;
			return;
		}
	}
	if(!strcmp(s,first->word)){
		first->num++;
		return;
	}
	strcpy(p->word,s);
	p->num=1;
	p->next=first;
	p->fore=first->fore;
	if(first->fore!=NULL)first->fore->next=p;
	first->fore=p;
}
int getword(char* s,FILE* f){
	int i;
	char c;
	while(!isalpha(c=fgetc(f))&&c!='\0'&&c!=EOF);
	if(!isalpha(c))return 0;
	*s=c+(isupper(c)!=0)*32;
	for(i=1;isalpha(c=fgetc(f));i++)*(s+i)=c+(isupper(c)!=0)*32;
	*(s+i)='\0';
	return 1;
}
void lprintf(struct node* list){
	struct node *p=list;
	for(;p->fore!=NULL;p=p->fore);
	for(;p!=NULL;p=p->next)printf("%s %d\n",p->word,p->num);
}

