

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char word[32];
    int count;
    struct node *link;
};
struct node *wordlist = NULL; 

int getword(FILE *in);
void searchword();
void insertword(struct node *p);

char word[32];

int main()
{
    struct node *p, *q=NULL;
    FILE *in;
    in = fopen("article.txt", "r"); 
    while(getword(in) != EOF) 
    {
        searchword(); 
    }
    p=wordlist;
    while( p != NULL) 
    { 
        printf("%s %d\n", p->word, p->count);
         p=p->link;
	}
    return 0;
}
int getword(FILE *in)
{
    int c, i=0;
    while(!isalpha(c = fgetc(in)))
    {
        if(c == EOF)
            return c;
        else
            continue;
    }
    do{
        word[i] = tolower(c);
        i++;
    }while(isalpha(c = fgetc(in)));
    word[i] = '\0';
    return 1;
}

void searchword()
{
    struct node *p, *q=NULL; 
    for(p=wordlist; p != NULL; q=p,p=p->link)
    {
        if(strcmp(word, p->word) < 0)
            break;
        else if(strcmp(word, p->word) == 0)
        {
            p->count++;
            return;
        }
    }
    return insertword(q);
}

void insertword(struct node *p)
{
    struct node *q;
    q = (struct node*)malloc(sizeof(struct node));
    strcpy(q->word,word);
    q->count = 1;
    q->link = NULL;
    if(wordlist == NULL)
        wordlist = q;
    else if(p == NULL)
    {
        q->link = wordlist;
        wordlist = q;
    }
    else
    {
        q->link = p->link;
        p->link = q;
    }
}

