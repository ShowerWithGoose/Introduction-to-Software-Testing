#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 32
struct node
{
    char word[MAXWORD];
    int count;
    struct node *link;
};
struct node *Wordlist = NULL;
int getWord(FILE *bfp,char *w);
int searchWord(char *w);
int insertWord(struct node *p, char *w);

int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct node *p;
    
    bfp=fopen("input.txt", "r"); // @@ The filename should be "article.txt" as per problem description. If the file does not exist, fopen returns NULL, leading to a runtime error when fgetc is called.
    while(getWord(bfp,word)!=EOF){
        searchWord(word);
    }
    fclose(bfp);
    for(p=Wordlist;p!=NULL;p=p->link)
        printf("%s %d\n",p->word,p->count);
        
    return 0;
}

int getWord(FILE *bfp,char *w)
{
    char c; // @@ Should be declared as 'int' because fgetc() returns an int to properly handle EOF. Using char causes incorrect comparison with EOF, leading to infinite loop or failure to detect EOF, resulting in runtime errors.
    int i=0;
    while((c=fgetc(bfp))!=EOF) { // @@ Due to 'c' being char, the comparison with EOF may never succeed or may misbehave, causing the loop to run indefinitely or terminate prematurely.
        if(isalpha(c)){
            w[i++]=tolower(c);
            while((c=fgetc(bfp))!=EOF&&isalpha(c)&&i<MAXWORD-1){
                w[i++]=tolower(c);
            }
            w[i]='\0';
            return 0;
        }
    }
    return EOF;
}

int searchWord(char *w)
{
    struct node *p,*q=NULL; 
    for(p=Wordlist;p!=NULL;q=p,p=p->link){
        if (strcmp(w,p->word)<0){
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;
        }
    }
    return insertWord(q,w);
}

int insertWord(struct node *p, char *w)
{
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(q==NULL){
        return -1;
    }
    strcpy(q->word,w);
    q->count=1;
    q->link=NULL;
    if(Wordlist==NULL){
        Wordlist=q;
    }
    else if(p==NULL){
        q->link=Wordlist;
        Wordlist=q;
    }
    else{
        q->link=p->link;
        p->link=q;
    }
    free(q); // @@ This frees the newly inserted node immediately, causing a use-after-free error when the list is later traversed, leading to undefined behavior and likely a runtime crash.
    return 0;
}