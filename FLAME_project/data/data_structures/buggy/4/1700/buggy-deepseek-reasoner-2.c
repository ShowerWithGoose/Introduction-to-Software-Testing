#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node
{
    char word[32];
    int count;
    struct node*next;    
};
struct node *wordlist=NULL;
int getword(FILE *in,char *word);
int insertword(struct node*p,char *word);
int searchword(char *word);
int main()
{
    char filename[100];
    char word[32];
    FILE *in;
    scanf("%s",filename); // @@ Should use a fixed filename "article.txt" as specified; reading from stdin causes file open failure.
    if((in=fopen(filename,"r"))==NULL)
    {
        fprintf(stderr,"%s can't open!\n",filename);
        return -1;
    }
    while(getword(in,word)!=EOF)
    {
        if(searchword(word)==-1)
        {
            fprintf(stderr,"full\n");
            return -1;
        }
    }
    struct node*p;
    for(p=wordlist;p!=NULL;p=p->next)
    {
        printf("%s %d\n",p->word,p->count);
    }
    fclose(in);
    return 0;
}
int getword(FILE *in,char *word)
{
    int i=0;
    char c;
    while(isalpha(c=fgetc(in))==0)
    {
        if(c==EOF)
        {
            return c;
        }
        else
        {
            continue;
        }
    }
    
    do
    {
        word[i++]=tolower(c);
    } while(isalpha(c=fgetc(in)));
    word[i]='\0'; // @@ Missing return value; function should return 1 to indicate a word was successfully read (non-EOF).
}
int searchword(char *word)
{
    struct node*p=NULL,*q=NULL;
    for(p=wordlist;p!=NULL;q=p,p=p->next)
    {
        if(strcmp(word,p->word)<0)
        {
            break;
        }
        else if(strcmp(word,p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    return insertword(q,word);
}
int insertword(struct node*p,char *word)
{
    struct node*q=NULL;
    q=(struct node*)malloc(sizeof (struct node));
    strcpy(q->word,word);
    q->count=1;
    q->next=NULL;
    if(wordlist==NULL)//空链表 
    {
        wordlist=q;
    }
    else if(p==NULL)//插到头节点前 
    {
        q->next=wordlist;
        wordlist=q;
    }
    else
    {
        q->next=p->next;
        p->next=q;
    }
    return 0; 
}