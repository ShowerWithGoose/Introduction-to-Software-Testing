#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    char word[30];
    int count;
};
struct node wordlist[1000];
int cmp(const void*a,const void*b){
    struct node *pa=(struct node *)a;
    struct node *pb=(struct node *)b;
    if(strcmp(pa->word,pb->word)>0){
        return 1;
    }else{
        return -1;
    }
}
int i;
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char t; // @@ [Error] fgetc returns int. Storing it in char may cause EOF comparison to fail due to sign extension/truncation. Should be int t;
    int q; // @@ [Error] Variable q is uninitialized. Using it in else if(q==0) leads to undefined behavior. Should be initialized to 0.
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ [Error] Problem defines words as sequences of letters only. isdigit checks for digits. Should be isalpha(t).
            t=tolower(t);
            w[j]=t;
            j++;
            q=0; // @@ [Error] Logic flaw: q is used as a state flag. Setting to 0 here while checking q==0 later to process the word is inverted. Should be q=1 to indicate reading a word.
        }else if(q==0){ // @@ [Error] Condition triggers incorrectly due to inverted flag logic and uninitialized q. Should check if a word just ended (e.g., q==1) and reset q=0.
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){ // @@ [Error] Character array w is never null-terminated after accumulation. strcmp will read past bounds causing undefined behavior. w[j] = '\0'; is missing before this comparison.
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w);
                wordlist[i].count=1;
                i++;
            }
            strcpy(w,"");
        }    
    }
    qsort(wordlist,i,sizeof(struct node),cmp);
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }