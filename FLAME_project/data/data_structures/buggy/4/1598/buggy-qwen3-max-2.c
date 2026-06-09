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
    
    bfp=fopen("input.txt", "r"); // @@ [The problem specifies the input file should be "article.txt", but the code opens "input.txt". This causes a runtime error (e.g., file not found) or reads wrong input.]
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
    char c;
    int i=0;
    while((c=fgetc(bfp))!=EOF) {
        if(isalpha(c)){
            w[i++]=tolower(c);
            while((c=fgetc(bfp))!=EOF&&isalpha(c)&&i<MAXWORD-1){
                w[i++]=tolower(c);
            }
            w[i]='\0';
            return 0; // @@ [The function returns 0 on success, but the main loop expects it to return something != EOF to continue. However, the reference program returns 1 on success and EOF on end. Returning 0 here causes the loop condition `!=EOF` to always be true (since 0 != EOF), leading to infinite loop or incorrect termination. Also, after reading last word, it may not return EOF properly.]
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
    free(q); // @@ [Immediately freeing the allocated node `q` after inserting it into the list causes undefined behavior. The node becomes invalid, leading to crashes or garbage output when traversing the list.]
    return 0;
}