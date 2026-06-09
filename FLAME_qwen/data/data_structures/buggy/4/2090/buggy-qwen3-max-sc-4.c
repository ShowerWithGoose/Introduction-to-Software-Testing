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
    while(!isalpha(c=fgetc(in))){
        if(c==EOF) return EOF;
        else continue;
    }
    do{
        *w++=tolower(c);
    }while(isalpha(c=fgetc(in)));
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
    getword(in,s); @@
    wordlist=(struct node*)malloc(sizeof(struct node)); @@
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