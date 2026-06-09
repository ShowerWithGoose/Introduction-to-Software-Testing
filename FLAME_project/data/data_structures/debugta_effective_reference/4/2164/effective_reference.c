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
	NODE *t,*q,*r,*list,*p;
	in=fopen("article.txt","r");
	int flag;
	list=NULL;
	while(flag!=EOF)
	{
		t=(NODE*)malloc(sizeof(NODE));
		flag=getword(in,t->s);
		t->next=NULL;
		
		if(list==NULL)
		{
			t->count=1;
			list=t;
			q=t;
			continue;
		}
	
		if(strcmp(q->s,t->s)==0)
		{
			q->count++;
			free(t);
			continue;
		}
		if(strcmp(q->s,t->s)<0)
		{
			t->count=1;
			q->next=t;
			
			q=t;
			
		}
		if(strcmp(q->s,t->s)>0)
		{
			t->count=1;
			for(p=list;p->next!=NULL;p=p->next)
			{
				if(strcmp(p->s,t->s)==0)
				{
					p->count++;
					free(t);
					break;
				}
				if(strcmp(list->s,t->s)>0)
				{
					t->next=list;
					list=t;
					break;
				}
				if(strcmp(p->next->s,t->s)>0)
				{
					t->next=p->next;
					p->next=t;
					break;
				}
			}
			
		}
		
	}
	int i=0;
	
	for(p=list->next;p!=NULL;p=p->next)
	{
		printf("%s %d\n",p->s,p->count);
		
	}
	
}

