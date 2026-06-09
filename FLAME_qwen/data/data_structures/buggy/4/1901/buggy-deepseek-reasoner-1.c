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
    int q; // @@ q is uninitialized; its initial value is indeterminate, leading to undefined behavior in the control flow.
    int j=0;
    char w[30];
    while((t=fgetc(in))!=EOF){
        if(isdigit(t)){ // @@ should be isalpha(t) to correctly identify letters; digits are not part of words according to the problem.
            t=tolower(t);
            w[j]=t;
            j++;
            q=0;
        }else if(q==0){ // @@ condition relies on q being properly initialized; due to uninitialized q, this may not behave as intended. Additionally, the word buffer w is not null-terminated before being used in strcmp.
            q=1;
            j=0;
            int y=0;
            for(int x=0;x!=i;x++){
                if(strcmp(wordlist[x].word,w)==0){ // @@ w may lack a terminating null character, causing strcmp to access memory beyond its allocated contents and leading to undefined behavior.
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