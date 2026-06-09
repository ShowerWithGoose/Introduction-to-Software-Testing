#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct {
	char word[10];
	int freq;
} unit;
struct note{
	unit data;
	struct note* link;
};
typedef struct note* noteptr;
typedef struct note note;
int readword(FILE* fptr,char* word)
{
	int k=0,flag=1;
	char ch;
	while(fscanf(fptr,"%c",&ch)!=EOF){
		if(ch>='a'&&ch<='z'){
			word[k++]=ch;
			flag=0;
			while(fscanf(fptr,"%c",&ch),ch>='a'&&ch<='z'||ch>='A'&&ch<='z'){
				word[k++]=ch;
				if(ch>='A'&&ch<='Z') word[k-1]+='a'-'A';
			}
			break;
		}
		else if(ch>='A'&&ch<='Z'){
			word[k++]=ch-'A'+'a';
			flag=0;
			while(fscanf(fptr,"%c",&ch),ch>='a'&&ch<='z'||ch>='A'&&ch<='z'){
				word[k++]=ch;
				if(ch>='A'&&ch<='Z') word[k-1]+='a'-'A';
			}
			break;
		}
	}
	if(flag) return 1;
	else return 0;
}
char words[10];
int main()
{
	FILE* article=fopen("article.txt","r");
	int i;
	noteptr list=NULL,p,q,r;
	
	while(readword(article,words)!=1){
		if(list==NULL){
			p=(noteptr)malloc(sizeof(note));
			strcpy(p->data.word,words);
			p->data.freq=1;
			p->link=NULL;
			list=p;
		}
		else{
			for(r=list,q=NULL;r!=NULL&&strcmp(words,r->data.word)>0;q=r,r=r->link);
			if(r==NULL){
				p=(noteptr)malloc(sizeof(note));
				strcpy(p->data.word,words);
				p->data.freq=1;
				p->link=NULL;
				q->link=p;
			}
			else if(strcmp(words,r->data.word)<0){
				p=(noteptr)malloc(sizeof(note));
				strcpy(p->data.word,words);
				p->data.freq=1;
				if(q==NULL){
					p->link=list;
					list=p;
				}
				else{
					p->link=q->link;
					q->link=p;
				}
			}
			else{
				r->data.freq++;
			}
		}
		memset(words,0,sizeof(words));
	}
	
	for(r=list;r!=NULL;r=r->link){
		printf("%s %d\n",r->data.word,r->data.freq);
	}
	return 0;
}

