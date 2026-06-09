#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word{
	char s[32];
	int count;
	struct word *link;
};
int getword(FILE *,char []);
struct word * insertword(struct word *,struct word *);
int main()
{
	struct word *p=NULL,*first=NULL,*fre=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	p=(struct word *)malloc(sizeof(struct word));
	p->count=1;
	p->link=NULL;
	if(getword(in,p->s)==-1)
		return 0;
	first=p;
	p=(struct word *)malloc(sizeof(struct word));
	p->count=1;
	p->link=NULL;
	while(getword(in,p->s)!=-1)
	{
		first=insertword(first,p);
		p=(struct word *)malloc(sizeof(struct word));
		p->count=1;
		p->link=NULL;
	}
	free(p);
	p=first;
	while(p!=NULL)
	{
		printf("%s %d\n",p->s,p->count);
		fre=p;
		p=p->link;
		free(fre);
	}
	return 0;	
}
int getword(FILE *x,char s[])
{
	int c,i;
	c=fgetc(x);
	while(c>'z'||c<'A'||(c>'Z'&&c<'a'))
	{
		if(c==EOF)
			return -1;
		c=fgetc(x);
	}
	for(i=0;(c<='z'&&c>='a')||(c>='A'&&c<='Z');i++)
	{
		if(c>='A'&&c<='Z')
			c=c+'z'-'Z';
		s[i]=c;
		c=fgetc(x);
	}
	s[i]='\0';
	return 1;
}
struct word * insertword(struct word *q,struct word *r)
{
	struct word *temp=NULL,*record=q;
	int j=0;
	j=strcmp(q->s,r->s);
	if(j>0)
	{
		r->link=q;
		return r;
	}
	if(j==0)
	{
		q->count++;
		free(r);
		return q;
	}
	while(j<0&&q->link!=NULL)
	{
		temp=q;
		q=q->link;
		j=strcmp(q->s,r->s);
	}
	if(j==0)
	{
		q->count++;
		free(r);
		return record;
	}
	if(j>0)
	{
		r->link=q;
		temp->link=r;
		return record;
	}
	q->link=r;
	return record;
}

