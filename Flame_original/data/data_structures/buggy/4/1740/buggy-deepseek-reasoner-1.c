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
            n++; // @@ Error: Incrementing n for every non‑alpha character leads to incorrect word count, empty entries, and an off‑by‑one for the last word. Also no null‑terminator is added after each word.
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp); // @@ Error: n may be incorrect (e.g., extra or missing a word), and many elements in m are not null‑terminated, causing undefined behavior in strcmp.
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ Error: Operator precedence makes `len` be 0 or 1, but more critically, m[i].word is not null‑terminated – using strlen here invokes undefined behavior.
    m[i].num++; // @@ Error: m[i].num is never initialized; incrementing a garbage value.
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ Error: i+1 goes out of bounds when i==n-1. Also, strcmp returns 0 for equal strings, so the condition should be `==0` to merge duplicates; currently it merges when different, which is the opposite of what is intended.
    m[i+1].num=m[i+1].num+m[i].num; // @@ Error: m[i+1].num may be uninitialized (if entry is empty or never assigned). Out‑of‑bounds access on last iteration.
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}