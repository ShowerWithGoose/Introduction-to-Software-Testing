#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXWORD 32
FILE *in;
typedef struct node{
	char word[MAXWORD];
	int count;
	struct node* next;
}NODE;
NODE *WordList=NULL;
int InsertWord(NODE *q,char *w)
{
	NODE *pnew;
	pnew=(NODE*)malloc(sizeof(NODE));
	if(pnew==NULL)  return -1;
	strcpy(pnew->word,w);
	pnew->count=1;
	pnew->next=NULL;
	if(WordList==NULL) 
	{
	  WordList=pnew;
	  strcpy(WordList->word,pnew->word);
	  WordList->count=pnew->count;
	}
	else if(q==NULL) 
	{
		q=(NODE*)malloc(sizeof(NODE));
		strcpy(q->word,w);
		q->count=1;
		q->next=WordList;
		WordList=q;
	 } 
	 else
	 {
	 	pnew->next=q->next;
		q->next=pnew;
	 }
	 return 0; 
}
int  SearchWord(char *w)
{
	NODE *p=NULL,*q=NULL;
	for(p=WordList;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(w,p->word)<0)   break;
		else if(strcmp(w,p->word)==0) 
		{
			p->count++;
			return 0;
		}
	}
	return InsertWord(q,w);
}
int getword(FILE *in,char *w)
{
	char c; 
	int num=0;
	while((c=fgetc(in))!=EOF)
	{
		if(isalpha(c)==0&&num<=0)
			continue;
		else if(isalpha(c)==0&&num>0)
			break;
		*(w+num)=tolower(c);
		num++;
	}
	*(w+num)='\0';
	if(num>0)  return 1;
	else       return 0;
}
int main()
{
	int m;
	char w[MAXWORD]="";
	NODE *phead;
	phead=NULL;
	in=fopen("article.txt","r");
	while(getword(in,w)!=0)
	{
		m=SearchWord(w);
		if(m==-1)  printf("fail\n");
	}
	for(phead=WordList;phead!=NULL;phead=phead->next)
	printf("%s %d\n",phead->word,phead->count);
	fclose(in);
	return 0;
}


