#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 32

typedef struct _Alp
{
	char s[MAXWORD];
	int t;
	struct _Alp *next;
}Alp,*PAlp;

PAlp Wordlist=NULL;

int getWord(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	if(c==EOF) return c;
	else continue;
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}

int insertWord(PAlp p,char *w)
{
	 PAlp q;
	 q=(PAlp)malloc(sizeof(Alp));
	 if(q==NULL) return -1;
	 strcpy(q->s,w);
	 q->t=1;
	 q->next=NULL;
	 if(Wordlist==NULL) Wordlist=q;
	 else if(p==NULL)
	 {
	 	q->next=Wordlist;
	 	Wordlist=q;
	 }
	 else{
	 	q->next=p->next;
	 	p->next=q;
	 }
	 return 0;
	 }

int searchWord(char *w)
{
	PAlp p,q=NULL;
	for(p=Wordlist;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(w,p->s)<0)
		break;
		else if(strcmp(w,p->s)==0)
		{
			p->t++;
			return 0;
		}
	}
	return insertWord(q,w);
}

int main()
{
	FILE *in;
	char word[MAXWORD];
	PAlp p;
	in=fopen("article.txt","r");
	while(getWord(in,word)!=EOF)
	if(searchWord(word)==-1)
	{
		fprintf(stderr,"Memory is full!\n");
		return -1;
	}
	for(p=Wordlist;p!=NULL;p=p->next)
	printf("%s %d\n",p->s,p->t);
	return 0; 
}

