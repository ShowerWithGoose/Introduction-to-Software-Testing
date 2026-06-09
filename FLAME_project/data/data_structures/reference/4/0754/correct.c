#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct article{
	char word[100];
	int time;
	struct article *next;
}article;
article *head=NULL;
int getword(FILE *in,char *w)
{
	char a;
	int i=0;
	while((a=fgetc(in))!=EOF)
	{
		if(isalpha(a)!=0)
		w[i++]=tolower(a);
		else
		if(i>0)
		{
			w[i]='\0';
			return 1;
		}
	}
	return 0;
}
int search(char *w)
{
	article *p,*front=NULL;
	for(p=head;p!=NULL;front=p,p=p->next)
	{
		if(strcmp(p->word,w)==0)
		{
			p->time++;
			return 1;
		}
		else if(strcmp(w,p->word)<0)
		break;
	}
	return insert(front,w);
}
int insert(article *front,char *w)
{
	article *p;
	p=(article*)malloc(sizeof(article));
	strcpy(p->word,w);
	p->time=1;
	if(head==NULL)
	head=p;
	else if(front==NULL)
	{
		p->next=head;
		head=p;
	}
	else
	{
		p->next=front->next;
		front->next=p;
	}
	return 1;
}
int main()
{
	FILE *in;
	char w[200];
	article *p;
	in=fopen("article.txt","r");
	while(getword(in,w)!=0)
	search(w);
	for(p=head;p!=NULL;p=p->next)
	printf("%s %d\n",p->word,p->time);
	return 0;
}

