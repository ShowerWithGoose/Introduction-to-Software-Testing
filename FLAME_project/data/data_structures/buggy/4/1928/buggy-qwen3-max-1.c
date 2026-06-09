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
    return -1;
    else return 1;
} // @@ [The comparison function for qsort must return negative, zero, or positive based on e1 < e2, e1 == e2, e1 > e2. This implementation returns -1 when e1 > e2 and 1 otherwise, which reverses the sort order and fails to return 0 for equal strings, leading to undefined behavior in qsort.]

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
                c=c+'a'-'A'; // @@ [This manual case conversion is error-prone; 'c + 'a' - 'A'' works only for ASCII and may fail in other encodings. Use tolower(c) instead.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0, j is incremented before assignment, but j was reset to 0 only when a non-alpha char was encountered. However, j is never reset after finishing a word, so subsequent words overwrite previous ones or use stale j values. Also, no null terminator is added after each word.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [j is reset to 0 here, but the current word in word[i] is not null-terminated, leading to undefined behavior when strcmp is later used.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Overwriting with 'z' is arbitrary and corrupts data. It doesn't reliably mark duplicates for exclusion and may create invalid or misleading strings (e.g., "zzz..." appears in output). Also, 3*sizeof(char) = 3 bytes, which may not cover the whole string.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The number of valid words is not correctly tracked. The logic using 'out' assumes each duplicate reduces total count by 1, but multiple duplicates of the same word cause overcounting of 'out'. Also, due to missing null terminators and corrupted strings, sorting is unreliable.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    } // @@ [Due to incorrect word extraction (missing null terminators), wrong duplicate handling, reversed/invalid sort, and corrupted strings, the output is completely wrong.]
}