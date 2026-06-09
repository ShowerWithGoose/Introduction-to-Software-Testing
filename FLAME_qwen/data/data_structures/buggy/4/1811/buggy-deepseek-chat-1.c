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
    for(r=r->link;r!=NULL;r=r->link){ // @@ The loop skips the first node (head) because it starts from r->link, which may cause the first word to be omitted from output.
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
        else if(getin!=NULL){ // @@ The condition `getin!=NULL` is always true because getin is an array, so this branch always executes when a non-letter is encountered, even if no letters were read. This causes the function to return an empty string when the first character is non-letter, and the function does not return a value properly.
            getin[i]='\0';
            break;
        }
    }
} // @@ Missing return statement; the function should return 1 when a word is found and EOF when end-of-file is reached, but it returns nothing, leading to undefined behavior.