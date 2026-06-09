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
    in=fopen("D:/article.txt","r"); // @@ [The problem requires reading from "article.txt" in the current directory, not an absolute path like "D:/article.txt". This will cause file not found on systems without this exact path.]
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ [The loop starts from r->link (i.e., skips the first node). If head is not NULL, the first word is never printed. Also, if head is NULL, r->link causes undefined behavior (dereferencing NULL).]
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter;
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){ // @@ [This condition is redundant and slightly incorrect: tolower(letter) is called twice; also, it excludes uppercase letters before tolower, but the condition should just use isalpha() as in reference. More critically, it fails to handle EOF correctly when no word has been read yet.]
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ [getin is always non-NULL (it's a stack array), so this condition is always true. It should check if i > 0 to indicate a word was being read. As written, it breaks even when no letters were read (e.g., at start of file with non-letter), returning an empty string.]
            getin[i]='\0';
            break;
        }
    }
} // @@ [Missing return statement: function should return EOF when end of file is reached without reading any word, but currently returns nothing (undefined behavior).]

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