#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char word[30];
    int count;
    struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr p,q,r,list;
int getWord(FILE *fp, char *w)
{
    int c;
    while(!isalpha(c=fgetc(fp)))
        if(c == EOF)
            return c;
        else continue;
    do
    {
        *w++ = tolower(c);
    } while(isalpha(c=fgetc(fp)));
    *w='\0';
    return 1;
}
void insert(Nodeptr p,char *w)
{
    Nodeptr q;
    q=(Nodeptr)malloc(sizeof(Node));
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(list==NULL)
    {
        list=q;
    }
    else if(p==NULL)
    {
        q->link=list;
        list=q;
    }
    else
    {
        q->link=p->link;
        p->link=q;
    }

}
int search(char *w)
{
    Nodeptr p,q=NULL;
    for(p=list;p!=NULL;q=p,p=p->link)
    {
        if(strcmp(w,p->word)<0)
            break;
        else if(strcmp(w,p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    insert(q,w);
}
FILE *in;
char w[30];
int main()
{
    in=fopen("article.txt","r");
    while(getWord(in,w)!=EOF)
    {
        search(w);
    }
    for(p=list;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
    return 0;
}

