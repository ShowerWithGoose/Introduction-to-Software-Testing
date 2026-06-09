#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	char word[50];
	int count;
	struct node *link;
};
struct node *wordlist=NULL;
int getword(FILE *fp,char *w)
{
	char c;
	while(!isalpha(c=getc(fp)))
	if(c==EOF)return c;
	else continue;
	do
	{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int searchword(char *w)
{
	struct node *p,*q=NULL;
	for(p=wordlist;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(w,p->word)<0)
		{
			break;
		}
		else if(strcmp(w,p->word)==0)
		{
			p->count++;
			return 0;
		}
	}
	return insertword(q,w);
}
int insertword(struct node *p,char *w)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	if(q==NULL)return -1;
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(wordlist==NULL)
	{
		wordlist=q;
	}
	else if(p==NULL)
	{
		q->link=wordlist;
		wordlist=q;
	}
	else
	{
		q->link=p->link;
		p->link=q;
	}
	return 0;
}
int main()
{
	char word[50],ch;
	FILE *fp;
	struct node *p;
	int i=0,j,k;
	fp=fopen("article.txt","r");
	while(getword(fp,word)!=EOF)
	{
		if(searchword(word)==-1)
		{
			return -1;
		}
		
	}
    for(p=wordlist;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->count);
	}
	return 0;
}

