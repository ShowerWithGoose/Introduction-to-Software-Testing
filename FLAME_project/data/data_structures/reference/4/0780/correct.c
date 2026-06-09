#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10000

typedef struct Node
{
    char s[100];
    int cnt;
    struct Node *pNext;
}NODE,*PNODE;

void sort(PNODE Head,int len)
{
    int i,x;
    char s_[100];
    PNODE p;
    for(i=0;i<len;i++)
        for(p=Head->pNext;p->pNext!=NULL;p=p->pNext)
        {
            if(strcmp(p->s,p->pNext->s)>0)
            {
                strcpy(s_,p->s);
                strcpy(p->s,p->pNext->s);
                strcpy(p->pNext->s,s_);
                x=p->cnt;
                p->cnt=p->pNext->cnt;
                p->pNext->cnt=x;
            }
            else if(strcmp(p->s,p->pNext->s)==0)
            {
                p->cnt+=p->pNext->cnt;
                p->pNext->cnt=0;
            }
        }
}
void clear(PNODE Head)
{
    PNODE q,p=Head;
    while(p!=NULL)
    {
        q=p->pNext;
        free(p);
        p=q;
    }
}

int main()
{
    FILE *fp= fopen("article.txt","r");
    char s[MAXN],word[100];
    PNODE Head=(PNODE) malloc(sizeof(NODE)),p=Head;
    Head->pNext=NULL;
    int i,j,len=0;
    while(fgets(s,MAXN,fp)!=NULL)
    {
        j=0;
        for(i=0;i<strlen(s);i++)
        {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            {
                if(s[i]>='A' && s[i]<='Z')
                    s[i]+='a'-'A';
                word[j++]=s[i];
            }
            else
            {
                word[j]='\0';
                j=0;
                if(strlen(word)>0)
                {
                    PNODE pNew=(PNODE) malloc(sizeof(NODE));
                    pNew->cnt=1;
                    strcpy(pNew->s,word);
                    p->pNext=pNew;
                    pNew->pNext=NULL;
                    p=pNew;
                    len++;
                }
            }
        }
    }
    sort(Head,len);
    p=Head->pNext;
    while(p!=NULL)
    {
        if(p->cnt!=0)
            printf("%s %d\n",p->s,p->cnt);
        p=p->pNext;
    }
    clear(Head);
    fclose(fp);
    return 0;
}

