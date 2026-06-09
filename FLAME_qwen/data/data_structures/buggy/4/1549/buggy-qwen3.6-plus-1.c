#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h>
#define maxword 100
typedef struct word{
    char infor[maxword];
    int count;
    struct word *link;
}word;
typedef word *wordptr;
wordptr wordlist=NULL;
int searchword(char *word); // @@ Parameter name 'word' shadows the typedef 'word', which may cause compilation errors or warnings in strict modes.
int insertword(wordptr q,char *word); // @@ Parameter name 'word' shadows the typedef 'word', which may cause compilation errors or warnings in strict modes.
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    char word[maxword]={'\0'},c; // @@ Variable 'c' should be of type 'int' to correctly store the return value of fgetc() and compare with EOF.
    int i=0,j;
    while((c=fgetc(in))!=EOF){
        if(c>='a'&&c<='z') word[i++]=c;
        else if(c>='A'&&c<='Z') word[i++]=c-'A'+'a';
        else if(i>0){
            searchword(word);
            for(j=0;j<=i;j++) word[j]='\0';
            i=0;
        }
    }
    wordptr p; 
    for(p=wordlist;p!=NULL;p=p->link){
        printf("%s %d\n",p->infor,p->count);
    }
    return 0;
}

int searchword(char *word){ // @@ Parameter name 'word' shadows the typedef 'word', which may cause compilation errors or warnings in strict modes.
    wordptr p,q=NULL;
    for(p=wordlist;p!=NULL;q=p,p=p->link){
        if(strcmp(word,p->infor)<0){
            break;
        }
        else if(strcmp(word,p->infor)==0){
            p->count++;
            return 0;
        }
    }
    return insertword(q,word);
}
int insertword(wordptr q,char *word){ // @@ Parameter name 'word' shadows the typedef 'word', which may cause compilation errors or warnings in strict modes.
    wordptr p;
    p=(wordptr)malloc(sizeof(word)); // @@ 'sizeof(word)' evaluates to the size of the parameter (pointer) instead of the struct, causing insufficient memory allocation. Should be 'sizeof(struct word)' or 'sizeof(*p)'.
    if(p==NULL) return -1;
    strcpy(p->infor,word);
    p->count=1;
    p->link=NULL;
    if(wordlist==NULL){
        wordlist=p;
    }
    else if(q==NULL){
        p->link=wordlist;
        wordlist=p;
    }
    else{
        (p->link)=(q->link);
        q->link=p;
    }
    return 0;
}