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
int cmp(struct Word *e1,struct Word *e2) // @@ The comparison function for qsort is incorrect. It returns -1 if e1 > e2 and 1 otherwise, which sorts in descending order. It should return negative if e1 < e2, positive if e1 > e2, and 0 if equal to sort in ascending (lexicographical) order. Also, it lacks a case for equality (returning 0).
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
                word[i].s[++j]=c;
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ This logic for marking duplicates is flawed. It only replaces the first 3 characters with 'z', leaving the rest of the string intact, which can lead to incorrect sorting or matching. Furthermore, modifying the string content instead of using a separate flag or removing the element properly is error-prone. The subsequent qsort relies on these modified strings, which may not sort correctly or uniquely identify removed items. A better approach would be to mark them with a special flag or move them to the end.
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ The number of elements to sort is calculated as i-out+1. However, because the duplicate marking strategy is flawed (see above), this count might be incorrect or the data being sorted is corrupted. Additionally, the cmp function sorts in reverse order.
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}