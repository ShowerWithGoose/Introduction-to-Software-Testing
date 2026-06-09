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
    char t;
    int q; // @@ Variable 'q' is uninitialized, leading to undefined behavior when first evaluated in the loop condition.
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ Problem defines words as sequences of letters, so 'isalpha(t)' should be used instead of 'isdigit(t)'.
            t=tolower(t);
            w[j]=t; // @@ String 'w' is not null-terminated after appending characters, causing undefined behavior in subsequent string operations.
            j++;
            q=0;
        }else if(q==0){ // @@ Logic incorrectly triggers word processing on every non-letter character instead of only at word boundaries.
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){ // @@ 'w' lacks a null-terminator, making 'strcmp' unsafe and prone to buffer overread.
                    wordlist[x].count++;
                    y=1;
                    break;
                }
            }
            if(y==0){
                strcpy(wordlist[i].word,w); // @@ 'w' lacks a null-terminator, causing 'strcpy' to copy unintended memory contents.
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