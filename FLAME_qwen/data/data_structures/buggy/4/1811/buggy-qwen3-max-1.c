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
    in=fopen("D:/article.txt","r"); // @@ [The problem specifies the file is "article.txt" in the current directory, but this uses an absolute Windows path "D:/article.txt", which may not exist or be accessible. Also, no check for NULL file pointer after fopen.]
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ [The loop starts from r->link (i.e., skips the first node). If head is not NULL, the first word is never printed. Should start from r = head.]
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter;
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){ // @@ [This condition is redundant and slightly incorrect: tolower() already ensures lowercase, but comparing with 'a' and 'z' excludes non-English letters? However, more critically, it should use isalpha() per problem definition. Also, the condition 'a' <= tolower(letter) is always true if tolower(letter) is between 'a'-'z', but the logic is convoluted. However, the bigger issue is below:]
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ [This condition is wrong: getin is an array passed as a pointer, so it's never NULL. It should check if i > 0 to indicate a word was being built. As written, when a non-letter is encountered and i==0 (e.g., leading spaces), it still sets getin[0]='\0' and breaks, returning a zero-length word. Also, function doesn't return EOF properly at end of file.]
            getin[i]='\0';
            break;
        }
    }
} // @@ [Missing return statement: function should return EOF if no word was read at EOF, otherwise return something like 1. As written, it falls off without returning a value, causing undefined behavior.]

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