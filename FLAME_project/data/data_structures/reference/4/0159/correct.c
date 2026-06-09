#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Word {
	char word[20];
	int n;
	struct Word* next;
} Word,*PWord;

PWord Add(PWord p0,char s[]) {
	if(p0==NULL) {
		PWord p1=(PWord)malloc(sizeof(Word));
		strcpy(p1->word,s);
		p1->n=1;
		p1->next=NULL;
		return p1;
	} else {
		PWord p1=p0;
		if(strcmp(p1->word,s)>0) {
			PWord p2=(PWord)malloc(sizeof(Word));
			strcpy(p2->word,s);
			p2->n=1;
			p2->next=p1;
			return p2;
		} else {
			while(p1->next!=NULL&&strcmp(p1->next->word,s)<=0) {//p1 <= s < p1->next
				p1=p1->next;
			}
			if(strcmp(p1->word,s)==0) {
				p1->n++;
			} else if(p1->next==NULL) {
				PWord p2=(PWord)malloc(sizeof(Word));
				p1->next=p2;
				strcpy(p2->word,s);
				p2->n=1;
				p2->next=NULL;
			} else {
				PWord p2=(PWord)malloc(sizeof(Word));
				p2->next=p1->next;
				p1->next=p2;
				strcpy(p2->word,s);
				p2->n=1;
			}
			return p0;
		}
	}
}

PWord Read(FILE* fp,PWord p0) {
	PWord p1=p0;
	char c;
	char s[20]= "";
	int i=0;
	c=fgetc(fp);

	while(c!=EOF) {
			if(isalpha(c)) {
				s[i++]=tolower(c);
			} else {
				s[i]='\0';
				if(strlen(s)!=0) {
					p1=Add(p1,s);
					s[0]='\0';
					i=0;
				}
			}
		c=fgetc(fp);
	}
	return p1;
}

int main() {
	FILE *IN=fopen("article.txt","r");
	PWord Head=NULL,p1=NULL;
	if(IN==NULL) {
		perror("Can't find the file!");
	}
	Head=Read(IN,Head);
	for(p1=Head; p1!=NULL; p1=p1->next) {
		printf("%s %d\n",p1->word,p1->n);
	}
	return 0;
}

