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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive values consistent with ordering. This implementation returns -1 when e1 > e2 and 1 otherwise, which reverses the sort order and fails to return 0 for equal strings, leading to undefined behavior in qsort.]
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
                c=c+'a'-'A'; // @@ [This conversion is incorrect: 'a' - 'A' is positive, but adding it to an uppercase letter gives wrong result. Should be c = tolower(c); or c = c - 'A' + 'a';]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0, j should not be pre-incremented because j already points to the next position after the last character. This causes skipping index 0 on continuation and potential buffer misalignment.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [After finishing a word, the string in word[i].s is not null-terminated, causing undefined behavior in subsequent strcmp calls.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Overwriting only first 3 characters with 'z' does not reliably invalidate the string for sorting/output; also, if original word was shorter than 3 chars, this corrupts memory beyond the string. Should set word[p].s[0] = '\0' or mark differently.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Due to incorrect cmp function and corrupted strings from memset, sorting produces wrong or undefined results. Also, the number of valid entries (i-out+1) may be incorrect because multiple duplicates might be counted multiple times in 'out'.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [If any string was corrupted or not null-terminated, printf may print garbage or crash. Also, lexicographical order is not achieved due to flawed cmp.]
        
    }
}