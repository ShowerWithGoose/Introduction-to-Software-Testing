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
    qsort(m,n,sizeof(rate),cmp);
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ [Error: Assignment in condition; should be (len = strlen(m[i].word)) != 0, but also len is unused and the logic is flawed; the intent is to increment num for non-empty words, but this increments for all words including empty ones due to operator precedence]
    m[i].num++;    
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ [Error: strcmp returns 0 when equal, so condition should be ==0 to detect duplicates; also m[i+1] may be out of bounds when i = n-1]
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;
    
}