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
                
                word[++i].s[j++]=c; // @@ [Error: When flag==0, a new word starts, but j is not reset to 0 before incrementing, causing j to continue from previous value. Also, word[++i] increments i first, but i starts at -1, so first word uses index 0 correctly, but j is not reset.]
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [Error: When flag==1, j is pre-incremented, but j was not reset to 0 at the start of a new word, so characters are appended at wrong positions. Also, the first character of a word is stored with j=0 (post-increment in flag==0 case), but subsequent characters use pre-increment, causing the first character to be at index 0 and the second at index 2, skipping index 1.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [Error: j is reset to 0 here, but when a new word starts (flag==0), the code uses word[++i].s[j++] which increments j from 0 to 1, so the first character is stored at index 0, but then j becomes 1. For the next character, flag==1, so word[i].s[++j] increments j to 2, skipping index 1. This causes words to have gaps in their character arrays.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Error: Using memset to mark duplicate words with 'z' is incorrect; it corrupts the string and may cause issues with qsort and strcmp. Also, the size 3*sizeof(char) is arbitrary and may not cover the entire string.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Error: The cmp function returns -1 for greater and 1 for less, which is opposite to the standard qsort comparator that should return negative if first < second, positive if first > second. This will sort in reverse order. Also, the number of elements i-out+1 may be incorrect if out counts duplicates incorrectly.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}