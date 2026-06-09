#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define eps 1e-10
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define arraynum(x) (sizeof(x)/sizeof(x[0]))
typedef struct node
{
    char word[32];
    int count;
    struct node *next;
}LNode,*LinkList;
int getword(FILE *in,char *s);
int PutList(LinkList L);
LinkList InsertbyOrder(LinkList L,char *s);
LinkList DestroyList(LinkList L);

int main()
{
    FILE *in=fopen("article.txt","r");
    char tempword[32];
    LinkList L=NULL;

    while(getword(in,tempword)!=EOF)
    {
        L=InsertbyOrder(L,tempword);
    }

    PutList(L);
    L=DestroyList(L);
    fclose(in);
    return 0;
}

int getword(FILE *in,char *s)
{
    int c;
    while(isalpha(c=fgetc(in))==0)
    {
        if(c==EOF) return c;
        else continue;
    }
    do
    {
        *s++=tolower(c);
    }while(isalpha(c=fgetc(in)));
    *s='\0';
    return 1;
}
int PutList(LinkList L)
{
    if(L==NULL)
    {
        printf("ERROR");
        return 0;
    }
    LNode *p;
    p=L;
    printf("%s %d\n",p->word,p->count);
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%s %d\n",p->word,p->count);
    }
    return 1;
}
LinkList InsertbyOrder(LinkList L,char *s)
{

    LinkList p,q,r;
    q=L;
    while(q!=NULL)
    {
        if(strcmp(q->word,s)==0)
        {
            q->count++;
            return L;
        }
        q=q->next;
    }
    p=(LinkList)malloc(sizeof(LNode));
    strcpy(p->word,s);
    p->count=1;
    if(L==NULL||strcmp(s,L->word)<0)
    {
        p->next=L;
        return p;
    }
    else
    {
        q=L;
        while(q!=NULL&&strcmp(s,q->word)>=0)
        {
            r=q;
            q=q->next;
        }
            p->next=q;
            r->next=p;
        return L;
    }
}
LinkList DestroyList(LinkList L)
{
    LNode *p=L;
    while(p!=NULL)
    {
        L=p->next;
        free(p);
        p=L;
    }
    return NULL;
}

