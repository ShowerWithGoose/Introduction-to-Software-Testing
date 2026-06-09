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
        for(p=list;p!=NULL&&strcmp(q->s,p->s)>0;r=p,p=p->link) // @@ The variable 'r' is used in the loop body (assignment r=p) but is not initialized before the first iteration. If the loop condition fails immediately (e.g., inserting a word that should be at the head), 'r' remains NULL or uninitialized, leading to undefined behavior when accessed later.
        ;
        if(p==list){
            if(strcmp(q->s,p->s)==0){
            list->n+=q->n;
            free(q);    
            }
            else{
            r=list; // @@ This line attempts to set r, but if the loop above didn't run, r was uninitialized. More critically, if p==list and they are not equal, we want to insert before list. The logic here sets r=list, then q->link=r (so q->link=list), then list=q. This part is logically okay for head insertion IF r wasn't needed. However, the previous loop's lack of initialization for r is the primary crash risk.
            q->link=r;
            list=q;}
        }
        else{
            if(strcmp(q->s,p->s)==0){
                p->n+=q->n;
                free(q);
            }
            else{
                r->link=q; // @@ If the loop terminated because p became NULL (end of list), r points to the last node. This is correct. However, if the loop terminated because strcmp <= 0, r points to the node before p. This is also correct. The main issue remains the uninitialized r if the loop body never executes.
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
    c[++i]='\0'; // @@ Buffer overflow risk: if the word length equals maxword-1, i becomes maxword-1, then ++i makes it maxword, accessing c[maxword] which is out of bounds (valid indices 0 to maxword-1). Also, logic error: i is already incremented inside the loop for each char. After the loop, i points to the last valid character index. c[++i] puts null terminator at next position. This is correct for indexing, but the bound check is missing.
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