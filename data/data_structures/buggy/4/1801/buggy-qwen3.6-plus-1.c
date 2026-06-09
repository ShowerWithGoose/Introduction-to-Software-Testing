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
    if(in==NULL)
    {
        printf("file not found\n");
    } // @@ Missing return statement after error handling; causes segmentation fault when reading from NULL pointer

    char word[50]={0},op; // @@ op should be declared as int to properly handle EOF return value from fgetc
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
            if(searchword(word)==-1) // @@ Should verify i > 0 to avoid inserting empty strings when multiple non-letter characters appear consecutively
            {
                printf("memory is full\n");
            }
        }
    } // @@ Does not process the final word if the file ends with a letter; requires handling after the loop
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->next->word,p->next->count); // @@ Incorrectly uses p->next instead of p, causing segmentation fault on the last node and printing wrong data
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