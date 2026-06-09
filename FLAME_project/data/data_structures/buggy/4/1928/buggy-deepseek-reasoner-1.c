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
    if(strcmp(e1->s,e2->s)>0) // @@ [cmp should return strcmp result directly for ascending order; returning -1 here inverts the order and never returns 0]
    return -1; // @@ [returns -1 when e1 > e2, causing descending sort and missing equality case]
    else return 1; // @@ [returns 1 even when strings are equal, preventing proper duplicate detection during comparison]
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
                
                word[++i].s[j++]=c; // @@ [first character of word stored at index j=0, but subsequent characters will skip index 1 due to pre-increment in else branch; also no null terminator added]
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [pre-increment causes j to become 2 after first character (which left j=1), so index 1 is skipped; should be j++]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0;
            continue;
        }
        
    } // @@ [missing null terminator for the last word; strings are not properly terminated]
    for(int k=0;k<=i;k++)
    word[k].count=1;
    for(int k=0;k<=i;k++)
    {
        for(int p=k+1;p<=i;p++)
        {
            if(strcmp(word[k].s,word[p].s)==0)
            {
                word[k].count++;
                memset(word[p].s,'z',3*sizeof(char)); // @@ [overwrites first 3 chars with 'z', corrupting the word and causing wrong output; should instead set count to 0 or ignore]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [incorrect element count; array contains all words including those corrupted by memset; sorting only first i-out+1 elements does not reorder the rest]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}