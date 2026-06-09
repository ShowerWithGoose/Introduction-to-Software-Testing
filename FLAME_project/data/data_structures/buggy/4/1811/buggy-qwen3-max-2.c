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
    in=fopen("D:/article.txt","r"); // @@ [The file path is hardcoded to "D:/article.txt", but the problem specifies the file should be "article.txt" in the current directory. This may cause a runtime error if the file doesn't exist at that path.]
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ [The loop starts from head->link, skipping the first node (head). This causes the first word to be omitted from output. It should start from 'r = head'.]
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
        else if(getin!=NULL){ // @@ [This condition 'getin!=NULL' is always true since getin is an array passed by reference. It should check if any letters have been read (i>0) before terminating the word. Also, if the file starts with non-letter, this may not handle EOF correctly. Additionally, the function does not return EOF properly when end of file is reached without reading a word.]
            getin[i]='\0';
            break;
        }
    }
} // @@ [Missing return statement. Function should return EOF if no word is found at end of file, or 1 otherwise. Without a return value, behavior is undefined.]

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