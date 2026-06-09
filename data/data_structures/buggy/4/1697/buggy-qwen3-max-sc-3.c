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
        for(p=list;p!=NULL&&strcmp(q->s,p->s)>0;r=p,p=p->link)
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
            if(strcmp(q->s,p->s)==0){
                p->n+=q->n;
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
    char ch,c[maxword]={0}; // @@ [char ch should be int to properly handle EOF, as fgetc returns int]
    in=fopen("article.txt","r");
    while((ch=fgetc(in))!=EOF){ // @@ [fgetc returns int; storing in char may cause EOF comparison to fail on systems where char is unsigned]
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
    ch=tolower(ch);
    int i=0,j;
    c[i]=ch;
    while(1){
    ch=fgetc(in); // @@ [same issue: ch is char, but fgetc returns int; may misinterpret EOF or high-bit characters]
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
        i++;
        ch=tolower(ch);
        c[i]=ch;
    }
    else break;    
    }
    c[++i]='\0'; // @@ [off-by-one error: after loop, i is index of last letter; incrementing before '\0' skips one position, possibly causing buffer overflow or incorrect string]
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