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
    scanf("%s",filename); // @@ The problem states the file name is fixed as "article.txt" and located in the current directory. Reading it from input causes the program to fail if the input doesn't match or if the file isn't found, leading to the "can't open!" error observed in the buggy output. It should be hardcoded or handled according to the specific requirement which implies a fixed filename.
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
    word[i]='\0';
    return 1; // @@ The function is expected to return a value (specifically 1 on success or EOF on failure) to be used in the while loop condition in main(). Missing return statement leads to undefined behavior.
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
    if (q == NULL) return -1; // @@ Missing check for malloc failure. If malloc fails, q is NULL, and subsequent strcpy will cause a segmentation fault (Runtime Error).
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