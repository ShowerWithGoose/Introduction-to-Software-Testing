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
    scanf("%s",filename); // @@ [The problem requires reading from "article.txt", but this reads the filename from stdin, which violates the input specification.]
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
    while(isalpha(c=fgetc(in))==0) // @@ [This loop skips non-alphabetic characters correctly, but if the file starts with EOF, fgetc returns EOF and isalpha(EOF) is undefined behavior. Also, assignment inside condition may cause confusion but is syntactically valid. However, more critically: when a non-alpha char follows letters, the loop exits and the do-while processes the next alpha sequence—but if the file ends right after letters, the final word may not be returned properly because the do-while exits on non-alpha (including EOF), but then returns without checking if it actually read any letters. However, the real critical error is below:]
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
    word[i]='\0'; // @@ [Missing return statement: function should return 0 to indicate success, but falls off without returning anything, leading to undefined behavior. This causes the while loop in main to not terminate correctly or behave unpredictably.]
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