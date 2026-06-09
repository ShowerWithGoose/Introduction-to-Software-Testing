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
        return -1; // @@ The comparison function never returns 0 for equal strings; it should return 0 when strcmp returns 0.
    }
}
int i;
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    char t;
    int q;
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ Should be isalpha(t) to detect letters; digits are not part of words as per problem definition.
            t=tolower(t);
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ // @@ q is uninitialized before first use, leading to undefined behavior; also the logic for detecting word boundaries is flawed.
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
    // @@ Missing handling of the last word if the file ends while a word is being built (e.g., no newline at end).
    qsort(wordlist,i,sizeof(struct node),cmp);
    for(int p=0;p!=i;p++){
        printf("%s %d\n",wordlist[p].word,wordlist[p].count);
    }
    return 0;
 }