#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c) c>='A'&&c<='Z'?c-'A'+'a':c;
#define MAXWORD 20
#define MAXSIZE 500
#define LETTER 'a'
#define DIGIT '0'
struct st
    {
        char word[MAXWORD];
        int count;
        struct st *link;
    }*Wordstab=NULL;
int getWord(FILE *bfp,char *w);
int insertWord(char *w,struct st* p);
int searchWord(char *w,struct st *Wordstab);

char type(int c);
int N=0;


int main()
{
    FILE *in=fopen("article.txt","r");
    
    char word[MAXWORD];
    struct st*p;
    if(in==NULL){
        printf("article.txt can't open!\n");
        return -1;
    }
    while(getWord(in,word)!=EOF)
        if(searchWord(word,Wordstab)==-1){
          printf("Wordstab is full!\n");
        return -1;
    }
    for(p=Wordstab;p!=NULL;p=p->link)
    {
        printf("%s %d\n",p->word,p->count);
    }
    return 0;
}

int getWord(FILE *bfp,char* w)
{
    int c,i=0;
    while(type(c=fgetc(bfp))!=LETTER)
     if(c==EOF) return c;
    w[i++]=tolower(c);
    while((c=fgetc(bfp))!=EOF){
        if(type(c)!=LETTER)
        break;
        w[i++]=tolower(c);
    }
    w[i]='\0';
    return 1;
}

int searchWord(char *w,struct st *Wordstab)
{
    struct st *p,*q=NULL;
    for(p=Wordstab;p!=NULL;q=p,p=p->link)
    {
        if(strcmp(w,p->word)<0)
         break;
        else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;
        }
    }
    return insertWord(w,q);
}

int insertWord(char *w,struct st* p)
{
    struct st *q;
    q=(struct st*)malloc(sizeof(struct st));
    if(q==NULL)return -1;
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(Wordstab==NULL)
       Wordstab=q;
    else if(p==NULL){
        q->link=Wordstab;
        Wordstab=q;
    }
    else {
        q->link=p->link;
        p->link=q;
    }
    return 0;
}

/*int cmp(const void*s1,const void*s2)
{
   struct st*a=(struct st*)s1;
   struct st*b=(struct st*)s2;
   return strcmp(a->word,b->word);
}*/

char type(int c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
      return (LETTER);
    else if(c>='0'&&c<='9')
      return (DIGIT);
    else return (c);
}


