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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive based on ordering. This implementation returns -1 or 1 but never 0, which breaks sorting stability and correctness when strings are equal. Also, it sorts in descending order, but problem requires lexicographical (ascending) order.]
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(fp) leads to undefined behavior (likely segmentation fault). The program should check if fp is NULL and handle the error.]
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A'; // @@ [This conversion is correct in effect but relies on ASCII assumption. Better to use tolower(c). However, not a compilation error.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag==1 (continuing a word), j was already set from previous character. Incrementing j before assignment skips index 0 after a new word starts. Should be word[i].s[j++] = c; without pre-increment.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [After ending a word, j is reset to 0, but the current word string is not null-terminated. This leads to garbage in s[] when later using strcmp or printf. Each word must be null-terminated: word[i].s[j] = '\0'; before resetting j.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Using memset to overwrite word[p].s with 'z' is incorrect and unsafe. It only overwrites first 3*4=12 bytes (since sizeof(char)=1, but 3*sizeof(char)=3), and doesn't null-terminate. This corrupts data and may cause strcmp to read beyond intended. Should mark as empty or skip during output instead.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The number of valid words is not correctly computed. 'out' counts duplicates removed, but original logic doesn't account for multiple duplicates properly. Also, if file ends without non-alpha character, last word isn't null-terminated, causing undefined behavior in strcmp/qsort.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [If any word string wasn't null-terminated (e.g., last word in file), printf will print garbage until it hits a null byte, leading to incorrect output or crash.]
        
    }
}