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
        printf("file not found\n"); // @@ Missing return or exit; program continues with NULL file pointer, causing crash on fgetc.
    }

    char word[50]={0},op;
    articleptr p;
    int i=0;
    while((op=fgetc(in))!=EOF) // @@ Using NULL file pointer (in) due to previous error leads to segmentation fault.
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
            if(searchword(word)==-1) // @@ Calls searchword with empty string (word is "") when consecutive non-alphabetic characters occur, leading to insertion of empty-word nodes.
            {
                printf("memory is full\n");
            }
        }
    }
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->next->word,p->next->count); // @@ Incorrect: should be p->word, p->count. Accessing p->next when p is the last node causes undefined behavior (segmentation fault).
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