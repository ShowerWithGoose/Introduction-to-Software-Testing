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
            n++; // @@ The logic for handling word boundaries is flawed. Incrementing n here creates a new entry for every non-alpha character sequence, leading to many empty or invalid entries. It also fails to null-terminate the previous word properly before moving to the next index.
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp);
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ Operator precedence error. '!=' has higher precedence than '='. This evaluates as len = (strlen(m[i].word) != 0), assigning 1 or 0 to len, instead of checking if the length is non-zero. Also, the words were never null-terminated in the reading loop, so strlen may read garbage memory.
    m[i].num++;    
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ Logic error for counting frequencies. This approach attempts to merge counts by modifying adjacent elements after sorting, but it doesn't correctly accumulate counts for all duplicates and relies on uninitialized or incorrectly initialized num fields. It also accesses m[i+1] when i is n-1, causing out-of-bounds access.
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}