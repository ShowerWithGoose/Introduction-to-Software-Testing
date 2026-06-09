#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tollower(c) c>='A'&&c<='Z'?'a'-'A'+c:c
struct wordlist
{
    char word[100];
    int count;
    struct wordlist *link;
};
struct wordlist *list;
int searchWord(char *w)
{
    struct wordlist *p,*q=NULL;
    for(p=list;p!=NULL;q=p,p=p->link)
    {
        if(strcmp(w,p->word)<0)
        {
            break;
        }
        else if(strcmp(w,p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    return insertWord(q,w);
}

int insertWord(struct wordlist *p,char *w)
{
    struct wordlist *q;
    q=(struct wordlist *)malloc(sizeof(struct wordlist));
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(list==NULL)
    {
        list=q;
    }
    else if(p==NULL)
    {
        q->link=list;
        list=q;
    }
    else
    {
        q->link=p->link;
        p->link=q;
    }
    return 0;
}

int getword(FILE *fp,char *w)
{
    int c;
    while(!isalpha(c=fgetc(fp)))
    {
        if(c==EOF)
        {
            return c;
        }
        else
        {
            continue;
        }
    }
    do
    {
        *w++=tollower(c);
    }while(isalpha(c=fgetc(fp)));
    *w='\0';
    return 1;
}

int main()
{
    int i,j,k;
    char word[100];
    struct wordlist *p;
    FILE *fp;
    fp=fopen("article.txt","r");
    while(getword(fp,word)!=EOF)
    {
        i=searchWord(word);
    }
    for(p=list;p!=NULL;p=p->link)
    {
        printf("%s %d\n",p->word,p->count);
    }
    return 0;
}



