#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define MAXWORD 32
struct node {
	char word[MAXWORD];
	int count;
	struct node *link;
};
struct node *head=NULL;
int legal(char c);
int get(FILE*in,char *w);
int search(char *w);
int insert(struct node *p,char *w);
int main()
{
	char word[MAXWORD];
	FILE *in;
	in=fopen("article.txt","r");
	struct node *p;
	while(get(in,word)!=0)
	{
		search(word);
	}
	for(p=head;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->count);
	}
	return 0;
}
int legal(char c)
{
	if(c>='a'&&c<='z')
	{
		return 1;
	}
	else
		return 0;
}
int get(FILE*in,char *w)
{
	char c;
	int count=0; 
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			c+='a'-'A';
		}
		if(legal(c)==0&&count<=0)
		{
			continue;
		}
		else if(legal(c)==0&&count>0)
		{
			break;
		}
		w[count]=c;
		count++;
	}
	w[count]='\0';
	if(count>0)
	{
		return 1;
	}
	else
		return 0;
}
int search(char *w)
{
	struct node *p,*q=NULL;
	for(p=head;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(w,p->word)<0)
		{
			break;
		}
		else if(strcmp(w,p->word)==0)
		{
			p->count+=1;
			return 0;
		}
	}
	return insert(q,w);
}
int insert(struct node *p,char *w)
{
	struct node *q;
	q=(struct node * )malloc(sizeof(struct node));
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(head==NULL)
	{
		head=q;
	}
	else if(p==NULL)
	{
		q->link=head;
		head=q;
	}
	else
	{
		q->link=p->link;
		p->link=q;
	}
	return 0;
}

