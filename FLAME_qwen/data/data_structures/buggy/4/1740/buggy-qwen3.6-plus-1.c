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
            n++; // @@ Logic error: increments word index for every non-letter character, creating empty entries for consecutive delimiters, and fails to null-terminate the current word.
            i=0;
        }
        else if(isalpha(zimu)){
        m[n].word[i]=tolower(zimu);
            i++;}
    }
    qsort(m,n,sizeof(rate),cmp);
    for(i=0;i<n;i++)
    {
    if(len=strlen(m[i].word)!=0) // @@ Operator precedence error: '!=' binds tighter than '=', so len is assigned 0 or 1 instead of the string length. Also, words lack null-terminators, causing undefined behavior.
    m[i].num++;
    }
    for(i=0;i<n;i++){
    if(strcmp(m[i].word,m[i+1].word)){ // @@ Logic error: strcmp returns 0 for equal strings, so this condition triggers on different words. Also causes out-of-bounds access when i=n-1.
    m[i+1].num=m[i+1].num+m[i].num;
    m[i].num=0;
    }}
    for(i=0;i<n;i++)
    {if(m[i].num!=0)
        printf("%s %d\n",m[i].word,m[i].num);
    }
    return 0;

}