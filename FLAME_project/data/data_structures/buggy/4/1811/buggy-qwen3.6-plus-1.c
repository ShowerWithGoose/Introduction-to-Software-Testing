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
    in=fopen("D:/article.txt","r"); // @@ The problem states the file is "article.txt" in the current directory, but the code uses an absolute path "D:/article.txt" which may not exist or be accessible, causing a crash if fopen returns NULL and it's used without checking. Also, if the file doesn't open, subsequent reads will crash.
    while(getWord(in,getin)!=EOF){
        searchWord(getin);
    }
    fclose(in);
    r=head;
    for(r=r->link;r!=NULL;r=r->link){ // @@ This loop skips the first node (head) by starting at r->link. It should start at r (head) to print all words. Additionally, if head is NULL, accessing r->link causes a Runtime Error (segmentation fault).
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
        else if(getin!=NULL){ // @@ This condition `getin!=NULL` is always true as getin is an array on the stack. It should check if i > 0 to determine if a word has been accumulated before breaking. If the first character is non-letter, it breaks without setting null terminator properly or returning EOF correctly in all paths. More critically, if the loop ends via EOF without hitting the else block, the function doesn't return a value explicitly, leading to undefined behavior.
            getin[i]='\0';
            break;
        }
    }
} // @@ Missing return statement. If the loop finishes because of EOF and no word was found (or even if one was found and broken out), the function must return EOF or a success indicator. The current implementation falls off the end without returning a value, which is undefined behavior and likely causes the Runtime Error or incorrect loop termination in main.

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