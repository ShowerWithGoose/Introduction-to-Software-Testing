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
            n++; // @@ n is incremented on every non-alpha, counting separators instead of words; also previous word is not null-terminated before this increment
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu); // @@ word is not null-terminated after completion; also m[n] may be uninitialized due to incorrect n
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp);
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ strlen on non-null-terminated string leads to undefined behavior; assignment within condition is confusing
    m[i].num++; // @@ m[i].num is read before initialization (garbage value)
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ out-of-bounds access when i==n-1; also condition should be '==' to combine duplicates, not '!='
    m[i+1].num=m[i+1].num+m[i].num; // @@ adds counts when words are different, should add when same; also this merge only handles adjacent pairs
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}