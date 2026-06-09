#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node
{
    char word[32];
    int count;
    struct node* next;
};
typedef struct node article;
typedef struct node* articleptr;

articleptr head=NULL;

int searchword(char *w);
int insertword(articleptr p,char *w);

int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    if(in==NULL) // @@ [File open failure should terminate program; missing return -1 or exit]
    {
        printf("file not found\n");
    }

    char word[50]={0},op; // @@ [op should be int to hold EOF correctly; using char may cause infinite loop]
    articleptr p;
    int i=0;
    while((op=fgetc(in))!=EOF)
    {
        if(isalpha(op))
        {
            word[i]=tolower(op);
            i++;
        }
        else 
        {
            word[i]='\0';
            i=0;
            if(searchword(word)==-1) // @@ [Should skip empty words; calling searchword on empty string inserts invalid word]
            {
                printf("memory is full\n");
            }
        }
    } // @@ [Missing code to insert the last word if file ends with a letter]
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->next->word,p->next->count); // @@ [Should be p->word and p->count; using p->next causes off-by-one and possible NULL dereference]
    }

    return 0;
}

int searchword(char *w)
{
    articleptr p,q=NULL;
    for(p=head;p!=NULL;q=p,p=p->next)
    {
        if(strcmp(w,p->word)==0)
        {
            p->count++;
            return 0;
        }
        else if(strcmp(w,p->word)<0)
        {
            break;
        }
    }
    return insertword(q,w);
}

int insertword(articleptr p,char *w)
{
    articleptr q;
    q=(articleptr)malloc(sizeof(article));
    if(q==NULL) return -1;
    strcpy(q->word,w);
    q->count=1;
    q->next=NULL;
    if(head==NULL) head=q;
    else if(p==NULL)
    {
        q->next=head;
        head=q;
    }
    else
    {
        q->next=p->next;
        p->next=q;
    }
    return 0;
}