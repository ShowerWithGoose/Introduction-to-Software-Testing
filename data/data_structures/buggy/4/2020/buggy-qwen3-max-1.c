#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 32
#define LETTER 'a'
struct node{
    char word[MAX];
    int count;
    struct node *link;
};
struct node *wordlist=NULL;
int getWord(char *s,FILE *bfp);
int searchWord(char *w);
int insertWord(struct node *r,char *w);
int type(int c);
int main(){
    char word[MAX];
    struct node *p;
    FILE*bfp;
    bfp=fopen("article.txt","r");
    while(getWord(word,bfp)!=EOF){
    searchWord(word);}
        for(p=wordlist;p!=NULL;p=p->link){
            if(p->word!='\0') // @@ [This condition is invalid: p->word is an array, not a single char; comparing it to '\0' is always true and meaningless. It should be removed.]
            printf("%s %d\n",p->word,p->count);
        }

fclose(bfp);
return 0;
}

int searchWord(char *w){ 
    struct node *p,*q=NULL;
    for(p=wordlist;p!=NULL;q=p,p=p->link){
        if(strcmp(w,p->word)<0)break; 
        else if(strcmp(w,p->word)==0){
            p->count++;
            return 0;
        }
    }
    return insertWord(q,w);
}

int insertWord(struct node *r,char *w){
    struct node *t=NULL;
    t=(struct node*)malloc(sizeof(struct node));
    strcpy(t->word,w);
    t->count=1;
    t->link=NULL;
    if(wordlist==NULL){
        wordlist=t;
    }
    else if(r==NULL){
        t->link=wordlist;
        wordlist=t;
    }
    else{
        t->link=r->link;
        r->link=t;
    }
    return 0;
}

int getWord(char *s,FILE *bfp){
    int c,i=0,n=-1;
    while((c=fgetc(bfp))!=EOF){
        n=1;
        if(type(c)!=LETTER)break; // @@ [The loop breaks on the first non-letter character without skipping leading non-letters, so it may process partial or invalid words. Also, it doesn't skip leading non-letter characters before starting to read a word.]
        if((c<='Z')&&(c>='A'))c=c+'a'-'A';
        s[i++]=c;
    }
    s[i]='\0';
    return n;
}

int type(int c){
    if(((c<='z')&&(c>='a'))||((c<='Z')&&(c>='A')))return 'a';
    else return -1;
}