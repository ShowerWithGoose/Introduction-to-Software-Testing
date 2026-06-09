#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct rate{
    char word[1024];
    int num;
};
typedef struct rate rate,*rateptr;
char zimu;
int cmp(const void* p,const void* q)
{
    rateptr p1=(rateptr)p;
    rateptr p2=(rateptr)q;
    return strcmp(p1->word,p2->word);
}
rate m[100005];
int main()
{
    FILE *in;
    int i=0,n=0,len;
    in=fopen("article.txt","r");
    while((zimu=fgetc(in))!=EOF)
    {
        if(!isalpha(zimu))
        {            
            n++; // @@ Increments n for every non‑alpha character, creating empty slots and moving to next word before null‑terminating the previous one.
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu); // @@ Uses m[n].word after n has already been incremented; also never adds a null terminator, leading to undefined behavior.
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp); // @@ Sorts uninitialized and unterminated strings; n may be larger than actual words.
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ Reads strlen on unterminated string; condition assigns 0/1 to len instead of actual length.
    m[i].num++; // @@ Increments uninitialized num; should initialize all num to 0 beforehand.
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ Condition is true when strings are different; should be ==0 for duplicates. Also out‑of‑bounds when i==n‑1.
    m[i+1].num=m[i+1].num+m[i].num; // @@ Adds to next entry when words are different, corrupting counts.
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}