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
        for(p=list;p!=NULL&&strcmp(q->s,p->s)>0;r=p,p=p->link) // @@ r may be uninitialized if list not empty but p becomes NULL before loop executes? Actually r is only set if loop executes at least once; if list has one node and it's less than q, loop runs once, r gets p (which is list), then p becomes NULL. That's fine. However, later uses of r assume it was initialized.
        ;
        if(p==list){
            if(strcmp(q->s,p->s)==0){
            list->n+=q->n;
            free(q);    
            }
            else{
            r=list;
            q->link=r;
            list=q;}
        }
        else{
            if(strcmp(q->s,p->s)==0){ // @@ p can be NULL (if all words less than q), leading to null pointer dereference.
                p->n+=q->n; // @@ same issue: p may be NULL.
                free(q);
            }
            else{
                r->link=q;
                q->link=p;
            }
        }    
}}
int main(){
    FILE *in;
    Wordptr p=NULL,q=NULL;
    char ch,c[maxword]={0}; // @@ 'ch' should be declared as 'int' to properly detect EOF from fgetc().
    in=fopen("article.txt","r");
    while((ch=fgetc(in))!=EOF){ // @@ 'ch' is char; fgetc returns int. If char is signed, EOF (-1) may be misinterpreted.
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
    c[++i]='\0';
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