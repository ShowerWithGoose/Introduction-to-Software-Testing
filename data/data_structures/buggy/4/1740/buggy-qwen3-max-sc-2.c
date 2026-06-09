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
    qsort(m,n,sizeof(rate),cmp); // @@ [The array 'm' contains uninitialized entries; words are not null-terminated, leading to undefined behavior in strcmp and strlen. Also, the last word may not be finalized if file doesn't end with non-alpha.]
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ [Operator precedence error: assignment 'len = strlen(...)' is compared to 0, but due to precedence, it's parsed as 'len = (strlen(...) != 0)', which assigns 0 or 1 to 'len', not the actual length. Also, words aren't null-terminated, so strlen may read garbage.]
    m[i].num++;    
    }
    for(i=0;i<n;i++){ // @@ [Loop runs up to i = n-1, but accesses m[i+1], causing out-of-bounds access when i = n-1.]
    if(strcmp(m[i].word,m[i+1].word)){ // @@ [Same out-of-bounds access; also logic is inverted—should merge when words are equal, not different.]
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}