#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
struct node {
   char word[35];
   int count;
   struct node *link;
} ; 
struct node *Wordlist = NULL; 
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);
int main()
{
    char  word[35];
    FILE *bfp=fopen("article.txt","r");
    struct node *p;
     while( getWord(bfp,word) != EOF) 
    { 
      searchWord(word);
    } 

    for(p=Wordlist; p != NULL; p=p->link) 
    {
    	printf("%s %d\n", p->word, p->count);
	}
     return 0;
}
int getWord(FILE *bfp,char word[35])
{
	int c;
	while(!isalpha(c=fgetc(bfp)))
	{
		if(c==EOF)
		{
			return c;
		}else{
			continue;
		}
		
	}
	int i=0;
	do{
		word[i]=tolower(c);
		i++;
	}while(isalpha(c=fgetc(bfp)));
	word[i]='\0';
	return 1;
}
int searchWord(char *w)
{
    struct node *p, *q=NULL; //q为p的前序结点指针
    for(p=Wordlist; p != NULL; q=p,p=p->link)
   {
    if(strcmp(w, p->word) < 0) 
   {
	   break;
   }else if(strcmp(w, p->word) == 0)
   {
      p->count++;
      return 0 ;
	} 
   }
    return insertWord(q, w);
}
int insertWord(struct node *q, char *w){
struct node *p; 
p=(struct node * )malloc(sizeof(struct node));
   if(p==NULL) 
   {
   	return -1;
   } 
    strcpy(p->word, w);
    p->count = 1;
    p->link = NULL;
   if(Wordlist == NULL) 
     Wordlist = p;
   else if (q==NULL)
   { 
       p->link = Wordlist;
       Wordlist = p;
    }else 
	{
     p->link = q->link;
     q->link = p;
    }
    return 0;
} 

