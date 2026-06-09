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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive based on ordering. This implementation returns -1 or 1 but never 0, which breaks stability and correctness when strings are equal. It should return strcmp(e1->s, e2->s).]
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
                c=c+'a'-'A'; // @@ [This conversion is incorrect: 'a' - 'A' is positive, so adding it to an uppercase letter gives a lowercase one, but the standard way is c = tolower(c); Also, this expression relies on ASCII and is less portable.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0 (i.e., continuing a word), j should be incremented before assignment, but j was reset only on non-alpha. However, j is not reset properly after finishing a word, leading to buffer overflow or incorrect indexing. Also, no null terminator is added to each word.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [j is reset to 0, but the current word in word[i] is not null-terminated, so subsequent string operations (like strcmp) will read garbage beyond the intended word.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Using memset to overwrite word[p].s with 'z' is incorrect and unsafe. It only overwrites 3 bytes, which may not fully invalidate the string, and 'z' is still a valid letter. This can cause false matches or output corrupted words. Should mark as empty or skip during output instead.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The number of valid words is not correctly computed. The variable 'out' counts duplicates removed, but the actual unique count is not i - out + 1 due to flawed duplicate handling. Also, if the file ends without a non-alpha character, the last word may not be properly terminated or counted.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}