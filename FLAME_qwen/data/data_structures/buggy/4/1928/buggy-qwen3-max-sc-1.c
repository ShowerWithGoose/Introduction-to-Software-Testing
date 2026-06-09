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
    else return 1; // @@ [The comparison function for qsort must return negative, zero, or positive based on (e1 < e2), (e1 == e2), (e1 > e2). This implementation returns -1 when e1 > e2 and 1 otherwise, which reverses the sort order and fails to return 0 for equal strings, leading to undefined behavior in qsort.]
}
int main()
{
    FILE *fp;
    char c;
    int i=-1,flag=0,j=0,out=0;
    fp=fopen("article.txt","r"); // @@ [If "article.txt" does not exist or cannot be opened, fopen returns NULL, and subsequent fgetc(fp) leads to undefined behavior (likely crash). The program does not check if fp is NULL.]
    while((c=fgetc(fp))!=EOF) // @@ [fgetc returns an int, not char. Storing it in a char variable (c) can cause premature EOF detection on platforms where char is signed, because bytes with high bit set (like 0xFF) become negative and may equal EOF (-1). This leads to incorrect word parsing.]
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A'; // @@ [This manual case conversion is error-prone. Use tolower(c) instead. Also, since c is char, if char is signed and c is negative (from fgetc cast), passing to isupper/isalpha invokes undefined behavior per C standard (these functions require int representable as unsigned char or EOF).]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag != 0 (inside a word), j is incremented before assignment, but j was reset to 0 at word start. However, after the first character, j should be incremented after assignment. This causes the second character to go into index 1 (correct), but logic is fragile. More critically, the string is never null-terminated.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [j is reset to 0, but the current word in word[i].s is not null-terminated. Without '\0', strcmp later will read beyond the intended word, causing undefined behavior.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [Overwriting word[p].s with 'z' for 3 bytes is arbitrary and incorrect. It doesn't nullify the string, and if the original word was longer than 3 chars, strcmp may still match partially. Also, this corrupts data and doesn't properly mark duplicates for exclusion.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [The number of valid words is not correctly computed. 'out' counts duplicate pairs, not unique duplicates, so i-out+1 is not the correct count of distinct words. Also, due to missing null terminators, qsort may crash or behave unpredictably.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [Because strings are not null-terminated, printf with %s will read until it finds a '\0' somewhere in memory, leading to garbage output or crash.]
        
    }
}