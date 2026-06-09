#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	char s[100];
	int count;
	struct node *next;
	
}NODE;
int cnt;
int getword(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF) 
		return c;
		else
		continue;
	}
	do{
		*w++=tolower(c);
		
	}while(isalpha(c=getc(fp)));
	*w='\0';
	return 1;
	
}
int main()
{
	FILE *in,*out;
	NODE *p,*q,*r,*head,*t;
	in=fopen("article.txt","r");
	int flag;
	head=NULL;
	while(flag!=EOF)
	{
		p=(NODE*)malloc(sizeof(NODE));
		flag=getword(in,p->s);
		p->next=NULL;
		
		if(head==NULL)
		{
			p->count=1;
			head=p;
			q=p;
			continue;
		}
	
		if(strcmp(q->s,p->s)==0)
		{
			q->count++;
			free(p);
			continue;
		}
		if(strcmp(q->s,p->s)<0)
		{
			p->count=1;
			q->next=p;
			
			q=p;
			
		}
		if(strcmp(q->s,p->s)>0)
		{
			p->count=1;
			for(t=head;t->next!=NULL;t=t->next)
			{
				if(strcmp(t->s,p->s)==0)
				{
					t->count++;
					free(p);
					break;
				}
				if(strcmp(head->s,p->s)>0)
				{
					p->next=head;
					head=p;
					break;
				}
				if(strcmp(t->next->s,p->s)>0)
				{
					p->next=t->next;
					t->next=p;
					break;
				}
			}
			
		}
		
	}
	int i=0;
	
	for(t=head->next;t!=NULL;t=t->next)
	{
		printf("%s %d\n",t->s,t->count);
		
	}
	
}

