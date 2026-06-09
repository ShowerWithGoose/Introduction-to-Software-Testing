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
    while(!isalpha(c=fgetc(in))){ // @@ [The assignment `c=fgetc(in)` happens inside `!isalpha(...)`, but `isalpha` expects an unsigned char or EOF. If `char` is signed, negative values (from non-ASCII chars) cause undefined behavior in `isalpha`. However, the main issue is logic: this loop skips non-alphabetic chars correctly, but the bigger problem is elsewhere.]
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
            insertword(p,w); // @@ [This branch inserts a new word at the end when reaching the last node and the word is lexicographically greater. However, the loop continues after insertion because there's no `break`, leading to potential NULL dereference or duplicate insertion on next iteration. Also, if list is empty, this function isn't called properly from main.]
        }
    }
}
int main(){
    struct node *p;
    FILE *in;
    in=fopen("article.txt","r");
    char s[30];
    getword(in,s); // @@ [If the file is empty or contains no words, `getword` returns EOF immediately, but this call still tries to process `s` which may be uninitialized or contain garbage. Then it proceeds to allocate and copy `s` unconditionally, causing undefined behavior.]
    wordlist=(struct node*)malloc(sizeof(struct node)); // @@ [This unconditional allocation assumes the first word always exists. If the file is empty (first getword returns EOF), this creates a node with garbage `word` and count=1, leading to incorrect output.]
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