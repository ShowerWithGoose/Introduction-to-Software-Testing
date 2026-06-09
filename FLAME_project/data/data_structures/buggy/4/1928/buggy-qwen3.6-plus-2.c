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
int cmp(struct Word *e1,struct Word *e2) // @@ The comparison function for qsort is incorrect. It returns -1 if e1 > e2 and 1 otherwise, which sorts in descending order. It should return the result of strcmp directly to sort in ascending (lexicographical) order. Also, qsort expects a function returning int where negative means less, positive means greater, zero means equal.
{
    if(strcmp(e1->s,e2->s)>0)
    return -1;
    else return 1;
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
                
                word[++i].s[j++]=c; // @@ Logic error: When starting a new word (flag==0), j is reset to 0 in the else block previously, but here we increment i and use j. However, j is not reset to 0 when a new word starts properly in all paths. More critically, when flag becomes 0, j is set to 0. But when flag is 1, we do word[i].s[++j]=c. This logic is flawed because j tracks the index within the current word. If flag==0, we start a new word at index i, and put char at j (which is 0). Then j becomes 1. Next char, flag==1, so we do word[i].s[++j] which makes j=2 and puts char at index 2. Index 1 is skipped/uninitialized. It should be word[i].s[j++] = c in both cases or handle indexing correctly.
                
            }
            else
            {
                word[i].s[++j]=c; // @@ Logic error: As described above, this skips index j. It should be word[i].s[j++] = c.
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ When a non-alpha character is encountered, we terminate the current word. However, we do not null-terminate the string word[i].s. This will cause printf to print garbage characters after the word until it finds a null byte. We need to add word[i].s[j] = '\0'; here.
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ Error: This attempts to mark duplicate words by filling the first 3 bytes with 'z'. This is unreliable. If the word is shorter than 3 chars, it might overwrite memory or not null-terminate properly. If longer, it just changes the prefix. This leads to incorrect sorting and output (like "zzzout"). A better approach is to mark them with an empty string or a specific flag, but since we are sorting, we should ensure duplicates are handled such that they don't appear in the final sorted list or are merged correctly before sorting. The current approach corrupts the data.
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ The number of elements to sort is calculated as i-out+1. This assumes that the 'out' duplicates are removed from the count. However, the array still contains i+1 elements. The duplicates are just marked with 'zzz'. Sorting only a subset might leave unsorted elements or include corrupted elements depending on how qsort handles the range. More importantly, the cmp function is wrong (descending order).
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}