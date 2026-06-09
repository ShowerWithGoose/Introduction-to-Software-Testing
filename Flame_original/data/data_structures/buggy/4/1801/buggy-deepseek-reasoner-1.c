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
        printf("file not found\n"); // @@ Error: Should exit or return after file open failure to avoid using NULL pointer.
    }

    char word[50]={0},op; // @@ Error: `op` should be declared as `int` to properly handle EOF.
    articleptr p;
    int i=0;
    while((op=fgetc(in))!=EOF) // @@ Error: Using `char op`; `fgetc` returns `int`, comparing `char` to EOF may cause infinite loop if `char` is unsigned.
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
            if(searchword(word)==-1)
            {
                printf("memory is full\n");
            }
        }
    } // @@ Error: Last word is not processed if file ends with a letter. Missing code after loop to handle final word.

    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->next->word,p->next->count); // @@ Error: Should print `p->word` and `p->count`; accessing `p->next` when `p` is the last node leads to undefined behavior.
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