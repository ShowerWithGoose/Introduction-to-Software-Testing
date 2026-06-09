#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct word{
	char words[20];
	int count;
	struct word *link;
}word;
word *head=NULL,*p,*q,*r;

int main()
{
	FILE *in;
	int flag=0;
	int i=0;
	int j;
	char c;
	int num=0;
	char m[81];
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
	if(c>='a'&&c<='z'||c<='Z'&&c>='A')
	{m[num]=c;
	num++;
	continue;
	}
	else 
	{
	if(m[0]<'A'||m[0]>'Z'&&m[0]<'a'||m[0]>'z')
	continue;
	else
	{
	m[num]='\0';
	num=0;
	}
	}
	for(i=0;m[i]!='\0';i++)
	{if(m[i]>='A'&&m[i]<='Z')
	m[i]+=32;
	}
		p=(word*)malloc(sizeof(word));
	    p->link=NULL;
	    strcpy(p->words,m);
		p->count=1;
		if(head==NULL)
		{
		head=p;
	    }
		else
		{
		r=head;
		while(strcmp(r->words,p->words)<0)
		{
		q=r;
		r=r->link;
		if(r==NULL)
		break;
		}
		if(r==NULL) 
		{q->link=p;
		}
		else if(strcmp(r->words,p->words)==0)
		{
		r->count++;
		free(p);
		}
		else if(r==head)
		{
		 p->link=head;
	     head=p;	
	    }
		else
		{p->link=r;
		q->link=p;
		} 
		
		}}
		r=head;
	while(r!=NULL)
	{
		if(*r->words<'A'||*r->words>'Z'&&*r->words<'a'||*r->words>'z')
		{r=r->link;
		continue;
		}
	printf("%s %d\n",r->words,r->count);
	r=r->link;
	}
	p=head;
	while(p!=NULL)
	{
	q=p;
	p=p->link;
	free(q);
	}
	fclose(in);
	return 0;
}

