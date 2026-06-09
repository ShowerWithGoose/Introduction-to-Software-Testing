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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive values consistently. This implementation returns -1 when e1 > e2 and 1 otherwise, which breaks strict weak ordering (e.g., when e1 == e2, it returns 1 instead of 0), leading to undefined behavior in qsort.]
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(fp) causes undefined behavior. The program should check if fp is NULL and handle the error.]
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A'; // @@ [This conversion is incorrect: 'a' - 'A' is positive, but adding it to an uppercase letter gives wrong result. Should be c = c - 'A' + 'a'; or simply use tolower(c).]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0, j is not reset, but ++j increments before assignment, potentially skipping index 0 and causing out-of-bounds if j exceeds 499. Also, no null-termination of word[i].s after reading a word.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [After encountering a non-alpha character, j is reset to 0, but the current word string is not null-terminated, so strcmp later may read garbage.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Overwriting only first 3 characters with 'z' doesn't reliably invalidate the string; also, if original word is longer than 3 chars, strcmp may still match partially. Should set word[p].s[0] = '\0' or mark differently.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Due to incorrect cmp function and possible unterminated strings, qsort behavior is undefined. Also, i-out+1 may be incorrect because out counts duplicates but doesn't account for multiple duplicates properly.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [If any word string was not null-terminated during input, printf may print garbage beyond intended word.]
        
    }
}