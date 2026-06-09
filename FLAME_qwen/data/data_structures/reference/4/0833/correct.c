#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
typedef struct dci
{
	char s[100];
	int count;
    struct dci *link;
}word;
void search(char*);
word *list=NULL;
int main() 
{
char w[100],a;
int i=0;
FILE*in;
word *p;
in=fopen("article.txt","r");
while((a=fgetc(in))!=EOF)
{		
    if(a>='A'&&a<='Z')
	a=a-'A'+'a';
	if(a<'a'||a>'z')
	{search(w);i=0;w[i]='\0';continue;}
	w[i++]=a,w[i]='\0';

}
for(p=list;p!=NULL;p=p->link)
 printf("%s %d\n",p->s,p->count);
fclose(in);
	return 0;	
	}

	
void search(char *w)
{
	word *p=list,*q;
	if(w[0]=='\0')
	return;
    if(p==NULL)
    {
    	list=(word*)malloc(sizeof(word));
    	strcpy(list->s,w);
    	list->count=1,list->link=NULL;
    	return;
	}
	if(strcmp(list->s,w)>0)
	{
		q=(word*)malloc(sizeof(word));
		q->link=p,q->count=1,strcpy(q->s,w);
		list=q;
		return;
	}
	while(1)
	{
		if(strcmp(p->s,w)==0)
		{p->count++;return;}
		if(p->link==NULL||strcmp(p->link->s,w)>0)
		{
			q=(word*)malloc(sizeof(word));
			strcpy(q->s,w),q->count=1;
			q->link=p->link,p->link=q;
			return;
		}
        p=p->link;	
	}	
}




