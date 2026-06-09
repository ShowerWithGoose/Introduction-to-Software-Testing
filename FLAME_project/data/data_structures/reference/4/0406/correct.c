#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define max 45

struct node{
    char word[max];
    int cnt;
    struct node *link;
};

struct node *wordlist=NULL;

int getword(FILE *fp,char *w);
int insertword(struct node *p,char *w);
int searchword(char *w);


int main()
{
    char word[max];
    struct node *p;
    FILE *in;
    in=fopen("article.txt","r");

    if((in=fopen("article.txt","r"))==NULL)
    {
        printf("Can't open file article.txt!\n");
        fclose(in);
        return 0;
    }


    while((getword(in,word))!=EOF)
    {
        if(searchword(word)==-1)
        {
            printf("Memory is full!\n");
            return -1;
        }
    }

    //printf("%s %d\n",wordlist->word,wordlist->cnt);

    for(p=wordlist;p!=NULL;p=p->link)
    {
        printf("%s %d\n",p->word,p->cnt);
    }
    fclose(in);

    return 0;
}

int getword(FILE *fp,char *w)
{
    int c;
    while((isalpha(c=fgetc(fp)))==0)
    {
        if(c==EOF)
            return c;
        else continue;
    }
    do{
        *w++=tolower(c);
    }while(isalpha(c=fgetc(fp)));
    *w='\0';
    return 1;
}

int insertword(struct node *p,char *w)
{
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    if(q==NULL)
        return -1;
    strcpy(q->word,w);
    q->cnt=1;
    q->link=NULL;
    //printf("%s %d\n",q->word,q->cnt);
    if(wordlist==NULL)
    {
        wordlist=q;
    }else if(p==NULL)
    {
        q->link=wordlist;
        wordlist=q;
    }
    else{
        q->link=p->link;
        p->link=q;//将q接在节点p之后
    }
    return 0;
}

int searchword(char *w)
{
    struct node *p,*q=NULL;//q为p的前驱节点
    for(p=wordlist;p!=NULL;q=p,p=p->link)
    {
        if(strcmp(w,p->word)<0)
            break;
        else if(strcmp(w,p->word)==0)
        {
            p->cnt++;
            return 0;
        }
    }
    return insertword(q,w);
}



