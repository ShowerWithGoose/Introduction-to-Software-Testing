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
char zimu; // @@ should be int to hold EOF (fgetc returns int)
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
    while((zimu=fgetc(in))!=EOF) // @@ if char is unsigned, EOF never matches; also zimu should be int
    {
        if(!isalpha(zimu))
        {            
            n++; // @@ word count increments on non-alpha, but previous word not null-terminated; last word not counted
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++; // @@ no null terminator added for the word; also no bounds check on i
        }
    }
    qsort(m,n,sizeof(rate),cmp); // @@ n may be off by one (last word uncounted), and strings lack null terminators -> undefined behavior
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ operator precedence: (len = (strlen(...)!=0)) -> sets len to 0 or 1, not used; logical bug
    m[i].num++;    // @@ m[i].num was never initialized; relies on global zero-init (ok), but logic flawed
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ condition should be ==0 for equal words; also i+1 out of bounds when i=n-1
    m[i+1].num=m[i+1].num+m[i].num; // @@ adds counts of different words due to wrong condition
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}