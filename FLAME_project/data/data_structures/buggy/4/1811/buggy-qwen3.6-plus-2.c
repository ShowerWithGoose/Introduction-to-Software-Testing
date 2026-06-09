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
    in=fopen("D:/article.txt","r"); // @@ The problem states the file is "article.txt" in the current directory, but here it uses an absolute path "D:/article.txt" which may not exist or be accessible, causing a crash if fopen returns NULL and is used without checking. Also, if the file doesn't exist, in is NULL, leading to runtime error in getWord.
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ This loop skips the first node (head) because it starts with r=r->link. It should start with r=head to print all words. If head is NULL, this will cause a segmentation fault (Runtime Error). Even if head is not NULL, it misses the first word.
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
        else if(getin!=NULL){ // @@ This condition `getin!=NULL` is always true as getin is an array. It should check if i > 0 to determine if a word has been accumulated. If i==0, it means we haven't started a word yet, so we should continue skipping non-letter characters. Currently, if a non-letter is encountered before any letter, it breaks immediately with an empty string or uninitialized data, and importantly, it does not return EOF when EOF is reached properly if the file ends with non-letters or if no word is found. Also, it lacks a return statement for the normal case where a word is found.
            getin[i]='\0';
            break;
        }
    }
    // @@ Missing return statement. The function is declared to return int, but reaches end without returning. This leads to undefined behavior. It should return EOF if EOF was encountered and no word was formed, or some success value otherwise.
}

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