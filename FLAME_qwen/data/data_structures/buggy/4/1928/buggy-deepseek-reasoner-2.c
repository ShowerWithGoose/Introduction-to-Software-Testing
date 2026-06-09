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
int cmp(struct Word *e1,struct Word *e2) // @@ [Comparator function signature is incorrect for qsort. It should be int cmp(const void *a, const void *b) to match the expected type. This causes a compilation error.]
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
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [Incorrect index increment; using pre-increment on j causes characters to be placed at positions 2, 3, ... instead of 1, 2, ... skipping index 1. Should be word[i].s[j++]=c.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [This does not properly mark duplicates; overwriting with 'z' corrupts the string and may cause incorrect sorting and output. A better approach is to set the string to empty or use a separate flag.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The cmp function has an incorrect signature, causing a type mismatch in qsort call. Also, the comparator implementation reverses the sort order (descending instead of ascending).]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}