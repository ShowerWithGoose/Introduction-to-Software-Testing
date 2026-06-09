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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive values consistently. This implementation returns -1 when e1 > e2 and 1 otherwise, which breaks strict weak ordering (e.g., when e1 < e2 it should return negative, but here it returns 1). It should return strcmp(e1->s, e2->s) or equivalent logic.]
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(fp) leads to undefined behavior (likely crash). The program should check if fp is NULL and handle the error.]
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A'; // @@ [This conversion is correct in effect but relies on ASCII. However, the real issue is that 'c' is of type char, which may be signed. If char is signed and c is a character with high bit set (e.g., extended ASCII), it could become negative, causing undefined behavior in isalpha and tolower. Better to cast to unsigned char before passing to ctype functions. But more critically, the variable 'c' should be declared as int to properly handle EOF.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0 (i.e., continuing a word), j is incremented before assignment, but j was reset to 0 only at word boundaries. However, after finishing a word, j is reset to 0, but the next word starts with j=0 and uses ++j, so the first character goes to index 1, leaving index 0 uninitialized. This causes words to be stored with a garbage first character or null byte, leading to incorrect string comparisons.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [After ending a word, j is reset to 0, but the current word string is not null-terminated. So when strcmp is later used, it reads beyond the intended end of the string, causing undefined behavior. Each word must be null-terminated after reading.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [This attempts to mark duplicate words by overwriting with 'z', but only 3 bytes are overwritten, which may not fully invalidate the string (especially if the word is longer). Also, using 'z' doesn't guarantee the string becomes lexicographically last or unique. Moreover, this corrupts the string so that later sorting and printing produce wrong output. A better approach is to skip duplicates during output or use a proper frequency map.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The number of valid entries is not correctly computed. 'out' counts the number of duplicates removed, but the actual number of unique words is not i - out + 1. For example, if a word appears 3 times, it will be counted twice in 'out', but only one instance should remain. Thus, the array size passed to qsort is incorrect, possibly including corrupted or duplicate entries.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count);
        
    }
}