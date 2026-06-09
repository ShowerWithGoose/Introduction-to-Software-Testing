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
    while((c=fgetc(fp))!=EOF)
    {
        if(isalpha(c)>0)
        {
            if(isupper(c)>0)
                c=c+'a'-'A'; // @@ [This conversion is correct in effect but relies on ASCII. However, the real issue is that 'c' is of type char, which may be signed. If char is signed and c is a character with high bit set (e.g., extended ASCII), it could become negative, causing undefined behavior in isalpha and tolower. But more critically, the variable 'c' should be declared as int to properly handle EOF. Using char for c causes EOF comparison to fail on systems where char is signed because EOF (-1) gets truncated.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c;
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [When flag==1 (inside a word), j is incremented before assignment, but j was reset to 0 at word start. However, after the first character (added when flag==0 with j=0), the next character uses ++j making it index 1, which is correct. BUT: j is never null-terminated, so later strcmp will read beyond valid data. Also, j is reset to 0 on non-alpha, but if a word ends, the string isn't null-terminated.]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [After finishing a word, the string in word[i].s is not null-terminated. This leads to undefined behavior in subsequent strcmp calls because they will read uninitialized memory until a null byte is found.]
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
                memset(word[p].s,'z',3*sizeof(char)); // @@ [This attempts to mark duplicates by overwriting with 'z', but only 3 bytes are overwritten, which may not fully invalidate the string (especially if original word is longer). Also, using 'z' doesn't guarantee the string becomes lexicographically last or unique; better to mark as empty or use a separate flag. Moreover, this corrupts the string, making later sorting and printing incorrect.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Due to incorrect cmp function (see earlier), the sort order is reversed and unstable. Also, the number of valid elements is i+1 minus out, but the logic for 'out' is flawed because multiple duplicates may be counted incorrectly. Additionally, if the file ends without a non-alpha character, the last word is not null-terminated, causing undefined behavior in strcmp during sort.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [If any word string was corrupted by memset (e.g., only first 3 chars changed to 'z'), the output will show incorrect words like "zzz..." followed by garbage until a null byte is encountered. Also, if strings aren't null-terminated, printf may print garbage.]
        
    }
}