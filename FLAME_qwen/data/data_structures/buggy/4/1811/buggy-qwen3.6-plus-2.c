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
    in=fopen("D:/article.txt","r"); // @@ Hardcoded absolute path "D:/article.txt" violates the requirement to read from "article.txt" in the current directory.
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ Incorrectly starts iteration from the second node (r->link), skipping the head node. Should start from head.
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter; // @@ Should be declared as 'int' because fgetc() returns an int to properly distinguish valid characters from EOF.
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ 'getin' is an array pointer and will never be NULL. Condition should be 'i > 0' to check if a word has been accumulated.
            getin[i]='\0';
            break; // @@ Exits the loop but does not return a success value (e.g., 1). The function must return a non-EOF value upon finding a word.
        }
    }
} // @@ Missing 'return EOF;' statement. The function falls off without returning a value when the file ends without a pending word.

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