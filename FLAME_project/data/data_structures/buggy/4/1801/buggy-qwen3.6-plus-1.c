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
    }

    char word[50]={0},op;
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
            if(strlen(word) > 0) // @@ The original code calls searchword even when word is empty (e.g., consecutive non-alpha characters), which creates empty string nodes or causes logic errors. We should only process non-empty words.
            if(searchword(word)==-1)
            {
                printf("memory is full\n");
            }
        }
    }
    // Handle the last word if the file doesn't end with a non-alpha character
    if (i > 0) {
        word[i] = '\0';
        searchword(word);
    }
    
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->word,p->count); // @@ The original code used p->next->word and p->next->count, which skips the first node and causes a segmentation fault (Runtime Error) when p->next is NULL at the last iteration. It should print the current node's data.
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