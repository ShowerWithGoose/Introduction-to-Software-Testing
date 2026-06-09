#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _word{
	char w[30];
	int freq;
	struct _word *next;
}word;
word list[10005],*p=NULL,*q=NULL;
int n=0;
int judgeLetter(char letr){
	if((letr>='a'&&letr<='z')||(letr>='A'&&letr<='Z'))
		return 1;
	else 
		return 0;
}
char replaceLetter(char letr){
	char x=letr;
	if(letr>='A'&&letr<='Z')
		x=x+'a'-'A';
	return x;
}
void add(char wrd[]){
	int j;
	p=&list[0];
	q=&list[0];
	while(p!=NULL){
		j=strcmp(p->w,wrd);
		//printf("##j=%d\n",j);//test
		if(j<0){
		//	printf("#001\n");
			q=p;
			if(p->next==NULL){
				strcpy(list[++n].w,wrd);
				p->next=&list[n];
				list[n].freq=1;
				list[n].next=NULL;
				return;
			}
			p=p->next;
			continue;	
		}
		else if(j==0){
		//	printf("#002\n");
			(p->freq)++;
			return;
		}
		else if(j>0){
		//	printf("#003\n");
			strcpy(list[++n].w,wrd);
			q->next=&list[n];
			list[n].freq=1;
			list[n].next=p;
			return;
		}
	}
	return;
}
void extract(char l[]){
	char wrd[30];
	int i=0,j;
	while(l[i]!='\0'){
		j=0;
		if(!judgeLetter(l[i])){
			i++;
			continue;
		}
		while(judgeLetter(l[i]))
			wrd[j++]=replaceLetter(l[i++]);
		wrd[j]='\0';
		add(wrd);
	}
	return;
}
int main()
{
	FILE *fpin;
	char line[1005];
	fpin=fopen("article.txt","r");
	list[0].w[0]='A';
	list[0].w[1]='\0';
	list[0].next=NULL;
	while(fgets(line,1000,fpin))
		extract(line);	
	p=&list[0];
	while(p->next!=NULL){
		p=p->next;
		printf("%s %d\n",p->w,p->freq);
	}
	return 0;
} 

