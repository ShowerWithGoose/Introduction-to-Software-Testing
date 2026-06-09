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
    
    bfp=fopen("article.txt", "r"); // @@ The problem description specifies the input file name as "article.txt", but the code uses "input.txt". This will likely cause a crash (NULL pointer dereference) if "input.txt" does not exist or is not opened correctly, leading to Runtime Error.
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
    free(q); // @@ The newly allocated node 'q' is freed immediately after being linked into the list. This causes the list to contain dangling pointers. Accessing these nodes later (e.g., in printf or subsequent searches) results in Undefined Behavior, typically a Runtime Error (Segmentation Fault). This line should be removed.
    return 0;
}