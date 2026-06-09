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
    else return 1; // @@ The comparison function returns -1 for greater and 1 for less, which is the opposite of the expected ascending order. This causes qsort to sort in descending order, producing incorrect lexicographical output.
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
                
                word[++i].s[j++]=c; // @@ When a new word starts, j is incremented after assignment, but the next character should be placed at index 1, not 0. This causes the first character to be at index 0, but subsequent characters are placed incorrectly due to inconsistent index handling.
                
            }
            else
            {
                word[i].s[++j]=c; // @@ For subsequent characters of the same word, j is pre-incremented, starting from 1, but the first character was placed at index 0 with post-increment. This mismatch leads to incorrect word construction, e.g., skipping index 1 or overwriting.
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ When a non-alpha character is encountered, j is reset to 0, but the word's string is not null-terminated. This means the next word will start writing from index 0 again, but the previous word's string lacks a null terminator, causing undefined behavior in strcmp and output.
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ Using memset to mark duplicate words with 'z' is incorrect because it only sets the first 3 characters to 'z', leaving the rest of the string unchanged. This can cause strcmp to still match or produce unexpected results, and the word may not be properly filtered out.
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp);
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}