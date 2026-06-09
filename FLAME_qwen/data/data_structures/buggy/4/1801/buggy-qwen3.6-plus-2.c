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
    } // @@ Missing return or exit statement here causes the program to proceed with a NULL file pointer, leading to a crash.

    char word[50]={0},op; // @@ op should be declared as int to correctly handle the EOF value returned by fgetc.
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
            if(searchword(word)==-1) // @@ Fails to check if i > 0 before calling searchword, resulting in empty strings being inserted into the list when consecutive non-letter characters are encountered.
            {
                printf("memory is full\n");
            }
        }
    } // @@ Does not process the last word if the file ends with an alphabetic character; need to handle the remaining word after the loop.
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->next->word,p->next->count); // @@ Incorrectly accesses p->next instead of p, which causes a segmentation fault when p->next is NULL and prints incorrect data.
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