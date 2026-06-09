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
} // @@ [The comparison function for qsort must return negative, zero, or positive based on e1 < e2, e1 == e2, e1 > e2. This implementation returns -1 when e1 > e2 and 1 otherwise, which reverses the sort order and fails to return 0 for equal strings, leading to undefined behavior in qsort.]

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
                c=c+'a'-'A'; // @@ [This manual case conversion is error-prone; should use tolower(c). Also, 'c' is of type char, which may be signed, leading to undefined behavior with tolower if not cast to unsigned char—but here it's done manually, which works only for ASCII. However, the bigger issue is word boundary handling.]
            if(flag==0)
            {
                
                word[++i].s[j++]=c; // @@ [When starting a new word (flag==0), j should be reset to 0 before assigning. Currently, j retains its value from previous non-alpha sequences, but it's set to 0 in else clause—however, logic is flawed because j is not reset properly at word start.]
                
            }
            else
            {
                word[i].s[++j]=c; // @@ [Should be word[i].s[j++] = c; because j is the next index to write. Using ++j writes to j+1, skipping index 0 after the first character. This causes incorrect word storage (e.g., first char at index 0, second at index 2, etc.).]
            }
            
            flag=1;
        }
        else 
        {
            flag=0;j=0; // @@ [j is reset to 0 here, but when a new word starts, j is used without being reset in the flag==0 block. Actually, in flag==0 block, j is used as-is (from previous reset), but the real bug is in the else branch using ++j instead of j++.]
            continue;
        }
        
    }
    // @@ [Missing handling for the last word if file doesn't end with non-alpha character. The loop ends without null-terminating the last word or incrementing i appropriately.]
    for(int k=0;k<=i;k++)
    word[k].count=1;
    for(int k=0;k<=i;k++)
    {
        for(int p=k+1;p<=i;p++)
        {
            if(strcmp(word[k].s,word[p].s)==0)
            {
                word[k].count++;
                memset(word[p].s,'z',3*sizeof(char)); // @@ [This corrupts duplicate words by overwriting first 3 chars with 'z', but doesn't null-terminate or fully erase. Later, strcmp may still match partially or produce garbage. Also, 'zzz...' may appear in output as seen in buggy output. Should mark as empty or skip during output instead.]
                out++;
            }
            
        }
        
        
    }
    qsort(word,i-out+1,sizeof(struct Word),cmp); // @@ [Due to incorrect cmp function, sorting is in reverse order and unstable. Also, the number of valid words is not i-out+1 because 'out' counts duplicates removed, but original array has i+1 words, and after marking duplicates, we should filter them, not assume contiguous valid entries.]
    for(int k=0;k<i-out+1;k++)
    {
        printf("%s %d\n",word[k].s,word[k].count); // @@ [Prints corrupted 'zzz...' words because memset didn't null-terminate, and due to wrong sorting and counting logic, output is completely incorrect. Also, words are not null-terminated during reading, so strcmp and printf may read beyond intended bounds.]
        
    }
}