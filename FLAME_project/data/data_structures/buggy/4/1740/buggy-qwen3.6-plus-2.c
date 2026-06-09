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
            n++; // @@ The logic for handling words is flawed. Incrementing n on every non-alpha character creates empty entries and doesn't properly terminate the previous word string with '\0'. Also, consecutive non-alpha characters will create multiple empty "words".
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp);
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ Operator precedence error. '!=' has higher precedence than '='. This evaluates as len = (strlen(m[i].word) != 0), so len becomes 1 or 0, not the length. Also, the strings in m[i].word are not null-terminated correctly in the reading loop, so strlen may read garbage or crash.
    m[i].num++;    
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ Accessing m[i+1] when i is n-1 leads to out-of-bounds access. Also, the logic for merging counts is incorrect because it assumes sorted adjacent duplicates but doesn't handle the accumulation correctly for all cases, especially given the previous errors in word parsing.
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}