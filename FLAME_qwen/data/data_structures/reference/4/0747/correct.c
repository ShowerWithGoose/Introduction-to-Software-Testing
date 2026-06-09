#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char Word[40];
struct node
{
    char word[40];
    int count;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;

int getword(FILE *fp)
{
    int i=0;
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        {
            Word[i]=tolower(c);
            i++;
        }
        else if(i>0)
        {
            Word[i]='\0';
            return 1;
        }
    }
    Word[i]='\0';
    return 1;
}
int main()
{
    Nodeptr Wordlist=NULL,p,q,r;
    FILE *in;
    in = fopen("article.txt", "r");
    getword(in);
    while(Word[0]!='\0')
    {
        q=(Nodeptr)malloc(sizeof(Node));
        strcpy(q->word,Word);
        q->count=1;
        q->link=NULL;
        for(r=p=Wordlist;p!=NULL;r=p,p=p->link)
        {
            if(strcmp(p->word,q->word)==0)
            {
                p->count++;
                break;
            }
            else if(strcmp(p->word,q->word)>0)
            {
                if(p==Wordlist)
                {
                    q->link=Wordlist;
                    Wordlist=q;
                }
                else
                {
                    q->link=p;
                    r->link=q;
                }
                break;
            }
        }
        if(Wordlist==NULL)
        {
            Wordlist=q;
        }
        else if(p==NULL)
        {
            r->link=q;
        }
        getword(in);
    }
    for(p=Wordlist;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
    fclose(in);
    return 0;
}





