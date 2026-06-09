#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define maxword 20
struct word{
    char s[maxword];
    int n;
    struct word *link;
};
typedef struct word *Wordptr;
typedef struct word Word;
Wordptr list=NULL;
void insertword(Wordptr q){
    Wordptr p=NULL,r=NULL;
    if(list==NULL){
        list=q;
    }
    else{
        for(p=list;p!=NULL&&strcmp(q->s,p->s)>0;r=p,p=p->link) // @@ The variable 'r' is used in the loop update expression but is not initialized before the first iteration. If the loop condition fails immediately (e.g., inserting a word that should be at the head), 'r' remains NULL, leading to undefined behavior or crash when accessed later.
        ;
        if(p==list){
            if(strcmp(q->s,p->s)==0){
            list->n+=q->n;
            free(q);    
            }
            else{
            r=list; // @@ This line attempts to fix 'r' but relies on the previous logic being reachable. However, the main issue is the uninitialized 'r' in the for loop declaration above.
            q->link=r;
            list=q;}
        }
        else{
            if(strcmp(q->s,p->s)==0){
                p->n+=q->n;
                free(q);
            }
            else{
                r->link=q; // @@ If 'r' was not properly set (due to the loop logic error or edge cases), this dereferences a NULL or garbage pointer, causing Runtime Error.
                q->link=p;
            }
        }    
}}
int main(){
    FILE *in;
    Wordptr p=NULL,q=NULL;
    char ch,c[maxword]={0};
    in=fopen("article.txt","r");
    while((ch=fgetc(in))!=EOF){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
    ch=tolower(ch);
    int i=0,j;
    c[i]=ch;
    while(1){
    ch=fgetc(in);
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
        i++;
        ch=tolower(ch);
        c[i]=ch;
    }
    else break;    
    }
    c[++i]='\0'; // @@ Potential buffer overflow if word length equals maxword-1, but more critically, the logic for reading words is flawed because it consumes the next non-letter character from the stream without putting it back, potentially skipping valid start-of-word characters if not handled carefully by the outer loop. However, the primary runtime error source is likely the linked list insertion.
    q=(Wordptr)malloc(sizeof(Word));
    q->link=NULL;
    strcpy(q->s,c);
    q->n=1;
    insertword(q);
    for(j=i-1;j>=0;j--)
    c[j]='\0';    
    }
    
    }    
    for(q=list;q!=NULL;q=q->link){
        printf("%s %d\n",q->s,q->n);
        
    }
    
    
    
    
    return 0;
}