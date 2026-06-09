#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char word[32];
	int count;
	struct node *next;		
};
int getword(FILE *fp,char *w);
int search(char *w);
int insert(struct node *p,char *w);
struct node *head=NULL,*p,*q,*r;
int main()
{
	int i=0,j,a;
	char word[32];
	FILE *fp;
	
	fp=fopen("article.txt","r");
	
	while(1)
	{
		memset(word, '\0', 32);
		a=getword(fp,word);	
		if(word[0]>'z'||word[0]<'a') 
			;
		
		else
		{	
			i++;
			if(i==1)
			{
				head=(struct node *)malloc(sizeof(struct node));
				strcpy(head->word,word);
				head->count=0;
				head->count++;
				head->next=NULL;
			}	
			else
			{
				search(word);
			}
			
			
			
		}if(a==-1)
			break;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%s %d\n",p->word,p->count);
	}
	return 0;
}

int getword(FILE *fp,char *w)	
{
	char ch;
	int i=0;
	ch=fgetc(fp);
	while((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A')) 
	{				
		if((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))
		{
			w[i++]=tolower(ch);
			ch=fgetc(fp);
		}
		else
		ch=fgetc(fp);
		
	}
	
	if(ch==EOF) 
	return -1;
	
	return 0; 
}

int search(char *w)
{
	q=NULL;
	for(p=head;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(p->word,w)>0)
		{
			break;
		}
		else if(strcmp(p->word,w)==0)
		{
			p->count++;
			return 0;
		}
	}
	
	if(q==NULL)
	{	
		q=(struct node *)malloc(sizeof(struct node));
		strcpy(q->word,w);
		q->count=0;
		q->count++; 
		q->next=head;
		head=q;
	}
	else if(p==NULL)
	{
		r=(struct node *)malloc(sizeof(struct node));
		strcpy(r->word,w);
		r->count=0;
		r->count++;
		r->next=NULL;
		q->next=r;
	}
	else
	return insert(q,w);	
}

int insert(struct node *p,char *w)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	strcpy(q->word,w);
	q->count=0;
	q->count++;
	q->next=p->next;
	p->next=q;
	return 0;
}

 




