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
            if(p->word!='\0') // @@ [Error 1: Comparing a char array (pointer) with a char literal '\0' is incorrect logic. It checks the address, not the content. This line should be removed or changed to check if the word is non-empty, but since empty words shouldn't be inserted, this check is likely redundant or wrong. More importantly, it doesn't fix the main issue.]
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
        if(type(c)!=LETTER)break; // @@ [Error 2: The logic here is inverted compared to the reference. The reference skips non-letters first. This loop breaks on non-letters, meaning it stops reading when it encounters a non-letter. However, it doesn't skip leading non-letters. If the file starts with a non-letter or has consecutive non-letters, this function behaves incorrectly. It reads a sequence of letters, but if the first character read is a non-letter, it breaks immediately, returning n=1 (since n was set to 1 in the previous iteration? No, n is -1 initially. If the first char is non-letter, n remains -1? No, n=1 is executed BEFORE the check. So if the first char is non-letter, n becomes 1, then it breaks. It returns 1. This means it treats an empty string or invalid start as a valid word read. This is the primary cause of the extra empty/invalid word at the beginning.]
        if((c<='Z')&&(c>='A'))c=c+'a'-'A';
        s[i++]=c;
    }
    s[i]='\0';
    return n; // @@ [Error 3: Returns n which is 1 if any character was processed, even if it was a non-letter that caused the break. It should return EOF if no word was found, or handle the "skip non-letters" logic like the reference implementation.]
}

int type(int c){
    if(((c<='z')&&(c>='a'))||((c<='Z')&&(c>='A')))return 'a';
    else return -1;
}