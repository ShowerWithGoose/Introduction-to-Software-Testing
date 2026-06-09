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
            n++;
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp); // @@ [n is not the correct count of words; it counts non-alphabetic separators as word boundaries but doesn't finalize the last word, and words are not null-terminated]
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ [operator precedence error: assignment happens after comparison; should be (len = strlen(...)) != 0. Also, words are not null-terminated so strlen may read garbage]
    m[i].num++;    
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ [logic error: this condition is true when words are different, but the code then adds current count to next, which is wrong. Should merge when equal, not when different. Also accesses m[i+1] beyond array bounds when i == n-1]
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}