#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAXWORD 32
struct node
{
	char word[MAXWORD];
	int count;
	struct node *link;
};
struct node *Wordlist=NULL;
int insertWord(struct node *p,char *w)
{
	struct node *q;
	q=(struct node*)malloc(sizeof(struct node));
	if(q==NULL)
	return -1;
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(Wordlist==NULL)
	Wordlist=q;
	else if(p==NULL)
	{
		q->link=Wordlist;
		Wordlist=q;
	}
	else
	{
		q->link=p->link;
		p->link=q;
	}
	return 0;
}
int searchWord(char *w)
{
	struct node *p,*q=NULL;
	for(p=Wordlist;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(w,p->word)<0)
		break;
		else if(strcmp(w,p->word)==0)
		{
			p->count++;
			return 0;
		}
	}
	return insertWord(q,w);
}

int main()
{
	char word[MAXWORD];
	FILE *bfp;
	struct node *p;
	int i=0;
	char ch;
	bfp=fopen("article.txt","r");
	while((ch=fgetc(bfp))!=EOF)
	{
		if(tolower(ch)>='a'&&tolower(ch)<='z')
		word[i++]=tolower(ch);
		else if((tolower(ch)<'a'||tolower(ch)>'z')&&word[0]!='\0')
		{
			word[i]='\0';
			searchWord(word);
			memset(word,0,sizeof(word));
			i=0;
		}
		else
		continue;
	}
	for(p=Wordlist;p!=NULL;p=p->link)
	printf("%s %d\n",p->word,p->count);
	return 0;
}

