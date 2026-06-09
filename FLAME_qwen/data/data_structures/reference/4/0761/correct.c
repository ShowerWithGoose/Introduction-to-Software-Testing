#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD  32
struct node 
{
    char word[MAXWORD];
    int count;
    struct node *link;
}; 
struct node *Wordlist=NULL; 
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);
int isNULL(char t);
int main()
{
    char filename[32], word[MAXWORD];
    FILE *bfp=fopen("article.txt","r");
    struct node *p;
    scanf("%s",filename);
    while(getWord(bfp,word)!=0)
    searchWord(word);
    for(p=Wordlist;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
    return 0;
} 
int isNULL(char tr)
{
	return !(((tr>='a'&&tr<='z')||(tr>='A'&&tr<='Z')));
}
int getWord(FILE *bfp,char *w)
{
	char sr;
	int count=0;
	while((sr=fgetc(bfp))!=EOF)
	{
		if(isNULL(sr)&&(count<=0)) continue;
		else if(isNULL(sr)&&(count>0)) break;
		if(sr>='a'&&sr<='z') w[count++]=sr;
		if(sr>='A'&&sr<='Z') w[count++]=sr+32;
	}
	w[count]='\0';
	if(count>0) return 1;
	else return 0;
}
int insertWord(struct node *p,char *w)
{
      struct node  *q;
      q=(struct node *)malloc(sizeof(struct node));
      if(q==NULL) return -1; 
      strcpy(q->word,w);
      q->count=1;
      q->link=NULL;              
      if(Wordlist==NULL)
           Wordlist=q;
      else if (p==NULL)
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
struct  node *p,*q=NULL;
for(p=Wordlist; p!=NULL;q=p,p=p->link)
{
    if(strcmp(w,p->word)<0) 
         break;
    else if(strcmp(w,p->word)==0)
	{
         p->count++;
         return 0;
    }
}
return insertWord(q, w);
}


