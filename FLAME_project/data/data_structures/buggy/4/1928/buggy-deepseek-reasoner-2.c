#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Word
{
    char s[500];
    int count;
}word[500];
int cmp(struct Word *e1,struct Word *e2)
{
    if(strcmp(e1->s,e2->s)>0)
    return -1; // @@ [Returns negative when first > second, causing descending instead of ascending order. Should return 1 for ascending.]
    else return 1; // @@ [Returns positive when first < second, causing ascending. Should return -1 for ascending. Also missing return 0 for equal strings.]
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A';
            if(flag==0)
            {
                
                word[++i].s[j++]=c; // @@ [Does not reset j for new word; previous j value is reused, causing wrong indices. Also no null terminator set after word ends.]
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [Uses ++j instead of j++, skipping index 1. Also no null terminator set.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0;
            continue;
        }
        
    }
    for(int k=0;k<=i;k++)
    word[k].count=1;
    for(int k=0;k<=i;k++)
    {
        for(int p=k+1;p<=i;p++)
        {
            if(strcmp(word[k].s,word[p].s)==0)
            {
                word[k].count++;
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Overwrites duplicate words with 'z's, causing fake entries like "zzzout". Also null terminator is not preserved.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Sorts only a subset of words; uses cmp with reversed order. Also relies on marked duplicates being after the sorted range, which is not guaranteed.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [May print fake words due to memset. Also no fclose call.]
        
    }
}