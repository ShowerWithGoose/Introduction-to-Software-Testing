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
    char word[maxword]={'\0'},c;
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
    if(i > 0) { // @@ [Missing handling for the last word if the file does not end with a non-alpha character. The loop exits on EOF, but if the last characters form a word, it hasn't been processed yet.]
        searchword(word);
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
    p=(wordptr)malloc(sizeof(word)); // @@ [Error: sizeof(word) returns the size of the typedef type 'word' (the struct), but 'word' is also the name of the char array parameter in main. While this might compile due to scope, it is semantically confusing and potentially incorrect if 'word' referred to the pointer type. More critically, in C, `sizeof(word)` where `word` is a typedef for a struct is valid. However, looking closely at the typedef: `typedef word *wordptr;`. The argument `char *word` shadows the typedef `word`? No, typedefs are types. But wait, `typedef struct word { ... } word;`. So `word` is a type alias for the struct. Inside `insertword`, the parameter is `char *word`. This shadows the type name `word`? In C, tag names and typedef names share the same namespace? No, typedef names are in the ordinary identifier namespace. Struct tags are in the tag namespace. So `sizeof(word)` inside `insertword` refers to the parameter `char *word` if it shadows the typedef? Actually, standard C allows typedef names and variable names to coexist in different scopes or shadow. Here, `word` is a parameter. `sizeof(word)` will evaluate to `sizeof(char*)`, which is 4 or 8 bytes, NOT the size of the struct. This causes a heap buffer overflow when `strcpy` is called later because insufficient memory is allocated for the struct.]
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