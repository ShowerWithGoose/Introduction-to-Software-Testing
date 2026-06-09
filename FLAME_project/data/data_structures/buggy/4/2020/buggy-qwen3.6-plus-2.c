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
            if(p->word!='\0') // @@ [Error: Comparing a char array (pointer) with a char literal '\0' is incorrect logic. It checks the address, not the content. Furthermore, the primary issue causing the "Wrong Answer" is that the first line of output is " 4", which implies an empty or invalid word is being printed. The getWord function returns 1 even if no letters are found (if it breaks immediately on non-letter after setting n=1? No, wait. Let's look at getWord. If the file starts with a non-letter, c=fgetc reads it. type(c) != LETTER. Break. s[0]='\0'. Returns n which was initialized to -1 but set to 1 inside loop? No.
            // Let's trace getWord carefully.
            // int c,i=0,n=-1;
            // while((c=fgetc(bfp))!=EOF){
            //    n=1;  <-- n becomes 1 immediately upon entering loop
            //    if(type(c)!=LETTER) break; <-- If first char is not letter, break.
            //    ...
            // }
            // s[i]='\0';
            // return n;
            // If the file starts with "I", c='I'. type('I')=='a' (LETTER). So it doesn't break.
            // It converts to lowercase. s[0]='i'. i=1.
            // Next char ' '. type(' ') != LETTER. Break.
            // s[1]='\0'. Returns 1. Correct.
            //
            // What if there are leading non-letters? e.g. "   I".
            // c=' '. type(' ') != LETTER. Break.
            // s[0]='\0'. Returns 1.
            // So getWord returns 1 (success) even if the word is empty string "".
            // Then searchWord("") is called.
            // insertWord is called. An empty string node is inserted.
            // When printing, p->word is "".
            // printf("%s %d\n", "", count) -> " 4" (if count is 4? No, count is 1).
            // Wait, the buggy output first line is " 4". This suggests the word is empty and count is 4? Or maybe the word is something else?
            // Actually, looking at the buggy output: " 4". There is a space before 4. This matches printf("%s %d\n", "", 4) if the empty word appeared 4 times?
            // Or perhaps the first word extracted is empty, and it gets counted multiple times?
            // Every time getWord encounters a separator without having read any letters since the last word, it returns an empty string.
            // The logic in getWord is flawed. It should skip non-letters first, THEN read letters.
            // Currently, it reads one char. If it's not a letter, it breaks and returns an empty word (but return value 1).
            // This causes empty words to be inserted into the list.
            // The condition `if(p->word!='\0')` attempts to filter these out but fails because `p->word` is an array, so it decays to a pointer. The pointer address is never equal to the integer value of '\0' (0) unless the array is at address 0, which is impossible. So this check is effectively always true (or compiler warning, but runtime it passes).
            // Thus, empty words are printed.
            // To fix the specific error location requested: The check `if(p->word!='\0')` is logically wrong for checking empty string. It should be `if(p->word[0] != '\0')`.
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
        if(type(c)!=LETTER)break; // @@ [Error: The function processes characters sequentially. If it encounters a non-letter character immediately (e.g., spaces, punctuation, or newlines between words), it breaks the loop. However, 'n' has already been set to 1 inside the loop before the check. This causes the function to return 1 (indicating success) even though no valid word characters were stored in 's' (s remains an empty string ""). This leads to empty words being added to the word list. The logic should skip non-letter characters first before starting to build a word.]
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