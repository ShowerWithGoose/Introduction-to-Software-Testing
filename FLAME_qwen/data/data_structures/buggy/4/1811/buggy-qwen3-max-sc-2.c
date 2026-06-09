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
    in=fopen("D:/article.txt","r"); // @@ [The problem specifies the file is "article.txt" in the current directory, but this uses an absolute Windows path "D:/article.txt", which may not exist or be accessible.]
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ [The loop starts from r->link (i.e., skips the first node). If head points to the first valid node, this skips it. Should start from r = head.]
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter;
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){ // @@ [This condition is redundant and incorrect: tolower(letter) is always lowercase, but comparing with 'a' and 'z' excludes uppercase letters before conversion. Also, isalpha() should be used instead of manual range check. More critically, non-alphabet characters break word reading, but logic fails when file ends without non-alpha after last word.]
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ [getin is an array passed by reference; it's never NULL. This condition should be "else if(i > 0)" to terminate a word that has been started. As written, it breaks on first non-alpha even if no word was being built, and fails to handle EOF properly. Also, function doesn't return EOF correctly when end of file is reached without trailing delimiter.]
            getin[i]='\0';
            break;
        }
    }
} // @@ [Missing return statement: function must return EOF when end of file is reached and no word remains, but currently falls off without returning anything, causing undefined behavior.]

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