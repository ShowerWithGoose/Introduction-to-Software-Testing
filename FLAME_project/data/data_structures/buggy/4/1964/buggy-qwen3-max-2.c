#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int LENLIST=0;
typedef struct node
{
    char word[105];
    int num;
    struct node* pNext;
}NODE,*PNODE;
void creat_list(PNODE,PNODE*,char*);
int getWord(FILE*,char*);
void sort_list(PNODE);
void print_list(PNODE);
int main()
{
    char word[105];
    FILE *pf;
    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        printf("NO!!!");
        exit(-1);
    }
    PNODE pTail=pHead;
    pTail->pNext=NULL;
    pf=fopen("article.txt","r");
    
    while(getWord(pf,word)==1)
    {
        creat_list(pHead,&pTail,word);
    }
    sort_list(pHead);
    print_list(pHead);
    
    return 0;
}

void creat_list(PNODE pHead,PNODE* pTail,char* word)
{
    PNODE p=pHead;
    int flag=0;
    for(int i=1;i<=LENLIST;i++,p=p->pNext)
    {
        if(strcmp(p->word,word)==0)
        {
            flag=1;
            (p->num)++;
        }
    }
    if(flag==0)
    {
        PNODE pNew=(PNODE)malloc(sizeof(NODE));
        if(pNew==NULL)
        {
            printf("NO!!!");
            exit(-1);
        }
        strcpy(pNew->word,word);
        pNew->num=1;
        pNew->pNext=NULL;
        (*pTail)->pNext=pNew;
        *pTail=pNew;
        LENLIST++;
    }
    
    return ;
}

int getWord(FILE* pf,char* word)
{
    char c;
    int i=0;
    while(!isalpha(c=fgetc(pf)))
    {
        if(c==EOF)
        return -1;
    }
    do
    {
        word[i++]=tolower(c);
    }while(isalpha(c=fgetc(pf))); // @@ [After reading a non-alpha character that ends the word, the file pointer is left at that character. However, the next call to getWord will skip non-alpha characters correctly, so this is not the main issue. The real problem is in creat_list logic.]
    word[i]='\0';
    return 1;
}

void sort_list(PNODE pHead)
{
    int i,j;
    PNODE p=pHead->pNext;
    PNODE q=NULL;
    for(i=1;i<=LENLIST-1;i++,p=p->pNext)
    {
        for(j=i+1,q=p->pNext;j<=LENLIST;j++,q=q->pNext)
        {
            if(strcmp(p->word,q->word)>0)
            {
                int num;
                char s[100];
                num=p->num;
                strcpy(s,p->word);
                p->num=q->num;
                strcpy(p->word,q->word);
                q->num=num;
                strcpy(q->word,s);
            }
        }
    }
    return ;
}

void print_list(PNODE pHead)
{
    PNODE p=pHead->pNext;
    while(p!=NULL)
    {
        printf("%s %d\n",p->word,p->num);
        p=p->pNext;
    }
    
    return ;
}