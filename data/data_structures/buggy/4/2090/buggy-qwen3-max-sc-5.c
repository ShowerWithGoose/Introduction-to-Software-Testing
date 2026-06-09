#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char word[30];
    int count;
    struct node *next;
};
struct node *wordlist=NULL;
int getword(FILE *in,char *w){
    int c;
    while(!isalpha(c=fgetc(in))){ // @@ [The expression !isalpha(c=fgetc(in)) evaluates isalpha on the ASCII value, but isalpha expects an unsigned char or EOF. However, more critically, if fgetc returns EOF (which is negative), passing it directly to isalpha causes undefined behavior. But this is not the main compilation error.]
        if(c==EOF) return EOF;
        else continue;
    }
    do{
        *w++=tolower(c);
    }while(isalpha(c=fgetc(in))); // @@ [Same issue as above: isalpha may receive negative value (EOF) which is undefined behavior, but again, not a compilation error.]
    *w='\0';
    return 1;
}
void insertword(struct node *p,char* w){
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->count=1;
    strcpy(q->word,w);
    q->next=NULL;
    if(p==NULL){
        q->next=wordlist;
        wordlist=q;
    }
    else{
        q->next=p->next;
        p->next=q;
    }
}
void searchword(char* w){
    struct node *p,*q=NULL;
    for(p=wordlist;p!=NULL;q=p,p=p->next){
        if(strcmp(w,p->word)<0){
            insertword(q,w);
            break;
        }
        else if(strcmp(w,p->word)==0){
            p->count++;
            break;
        }
        else if(p->next==NULL){
            insertword(p,w);
        }
    }
}
int main(){
    struct node *p;
    FILE *in;
    in=fopen("article.txt","r");
    char s[30];
    getword(in,s); // @@ [If the file is empty or contains no words, getword may return EOF immediately, but the program proceeds to allocate and initialize wordlist unconditionally, leading to undefined behavior. However, this is a runtime/logic error, not compilation.]
    wordlist=(struct node*)malloc(sizeof(struct node)); // @@ [This line assumes the first call to getword succeeded (i.e., didn't return EOF). If the file is empty, s is uninitialized or partially written, causing undefined behavior. But again, not a compilation error.]
    wordlist->count=1;
    strcpy(wordlist->word,s);
    wordlist->next=NULL;
    while(getword(in,s)!=EOF) searchword(s);
    for(p=wordlist;p!=NULL;p=p->next){
        printf("%s %d\n",p->word,p->count);
    }
    fclose(in);
    return 0;
}