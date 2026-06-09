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
        return -1; // @@ [comparison function should return 0 for equal words to satisfy strict weak ordering]
    }
}
int i;
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char t;
    int q; // @@ [uninitialized variable q used later in condition else if(q==0) leads to undefined behavior]
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ [should use isalpha(t) to detect letters, not digits; this causes no word characters to be captured]
            t=tolower(t);
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ // @@ [q is uninitialized at first; also no check for j>0 before processing word, causing empty word to be added]
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){
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