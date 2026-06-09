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
    in=fopen("D:/article.txt","r"); // @@ [The problem specifies the file is named "article.txt" in the current directory, but this uses an absolute Windows path "D:/article.txt", which may not exist or be accessible.]
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ [The loop starts from r->link (i.e., skips the first node). If head is not NULL, the first word is never printed. It should start from r = head.]
        printf("%s %d\n",r->word,r->n);
    }
    return 0;
}

int getWord(FILE *in,char getin[]){
    char letter;
    int i=0;
    while((letter=fgetc(in))!=EOF){
        if('a'<=tolower(letter)&&tolower(letter)<='z'){ // @@ [This condition is redundant and slightly incorrect: tolower(letter) is always lowercase, but the check 'a' <= x <= 'z' excludes non-English letters, which is acceptable per problem, but the real issue is that it doesn't handle the end-of-file case properly when a word ends at EOF. Also, the condition should just use isalpha() as in reference.]
            getin[i]=tolower(letter);
            i++;
        }
        else if(getin!=NULL){ // @@ [This condition is always true because getin is an array (non-NULL pointer). It should check if i > 0 to ensure a word was being built. Also, after breaking, it doesn't return EOF when the loop ends due to EOF without a trailing non-alpha character.]
            getin[i]='\0';
            break;
        }
    }
} // @@ [Missing return statement: function should return EOF when end of file is reached without reading any characters, or 1/0 otherwise. As written, it returns undefined value.]

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