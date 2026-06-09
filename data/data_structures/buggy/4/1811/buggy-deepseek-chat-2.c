#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    char word[50];
    int n;
    struct node *link;
};

struct node *head=NULL;
int getWord(FILE *in,char getin[]);
int searchWord(char getin[]);
int insertWord(struct node *p,char getin[]);

int main(){
    char getin[50];
    FILE *in;
    struct node *r;
    in=fopen("D:/article.txt","r");
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ The loop skips the first node (head) by starting with r->link, which may cause the first word to be omitted from output.
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter;
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ The condition `getin!=NULL` is always true because getin is a pointer to an array; it should check `i>0` to ensure a word was started.
            getin[i]='\0';
            break;
        }
    }
} // @@ Missing return statement; the function should return 1 when a word is found and EOF when end-of-file is reached without any word.

int insertWord(struct node *p,char getin[]){
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(q==NULL){
        return -1;
    }
    strcpy(q->word,getin);
    q->n=1;
    q->link=NULL;
    if(head==NULL){
        head=q;
    }
    else if(p==NULL){
        q->link=head;
        head=q;
    }
    else{
        q->link=p->link;
        p->link=q;
    }
    return 0;
}

int searchWord(char getin[]){
    struct node *p,*q=NULL;
    for(p=head;p!=NULL;q=p,p=p->link){
        if(strcmp(getin,p->word)<0){
            break;
        }
        else if(strcmp(getin,p->word)==0){
            p->n++;
            return 0;
        }
    }
    return insertWord(q,getin);
}