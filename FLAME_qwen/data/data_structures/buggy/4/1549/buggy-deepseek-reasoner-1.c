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
int searchword(char *word);
int insertword(wordptr q,char *word);
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    char word[maxword]={'\0'},c; // @@ Potential issue: Variable 'c' is declared as 'char', but the return type of fgetc() is 'int'. On platforms where 'char' is unsigned, comparing 'c' with EOF (which is typically -1) will never be true, leading to an infinite loop. Consider declaring 'c' as 'int'.
    int i=0,j;
    while((c=fgetc(in))!=EOF){ // @@ Logical error: As above, 'c' being 'char' may not correctly handle EOF. Additionally, if the file ends without a non-letter character, the last word is not processed.
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

int searchword(char *word){
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
int insertword(wordptr q,char *word){
    wordptr p;
    p=(wordptr)malloc(sizeof(word));
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