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
                
                word[++i].s[j++]=c; // @@ [Error: When flag==0, a new word starts, but j is not reset to 0 before incrementing, causing j to accumulate from previous word's length. Also, ++i increments i before use, but i starts at -1, so first word uses index 0 correctly, but subsequent new words will have j starting from the previous word's length, leading to incorrect string concatenation across words.]
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [Error: When flag==1, j is pre-incremented, but j was not reset to 0 at the start of a new word. This causes characters to be appended to the previous word's string, overwriting or extending it incorrectly. Additionally, the first character of a new word (when flag==0) uses j++ after incrementing i, but j retains its old value, so the new word's first character is placed at an incorrect index.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [Error: j is reset to 0 here, but this only happens when a non-alpha character is encountered. However, the logic for building words uses j inconsistently: when flag==0, j is incremented after use (j++), and when flag==1, j is pre-incremented (++j). This mismatch, combined with j being reset only here, leads to j not being properly initialized to 0 at the start of each new word, causing words to be concatenated or overwritten.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Error: Using memset to set the first 3 characters to 'z' is an arbitrary and incorrect way to mark duplicates. This corrupts the string and may cause sorting or comparison issues. It also does not guarantee that the word will be ignored later, as the string may still match other words or cause unexpected behavior in qsort.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Error: The cmp function returns -1 when e1->s > e2->s, which sorts in descending order, but the problem requires lexicographical order (ascending). Also, the size passed to qsort is i-out+1, but i is the index of the last word (starting from 0), so the number of words is i+1. Subtracting out may not correctly account for all duplicates, and the sorting range may be incorrect.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}