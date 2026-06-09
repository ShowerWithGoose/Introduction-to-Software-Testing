#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void turnword(char c[]);
int cmp(const void *p1, const void *p2);
struct dic
{
    char word[1000];
    int fre;
};
int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    struct dic a[1000]={};
    int n = 0;
    int find = 0;
    char s[1000];
    char c;
    int k = 0;
    while ((c = fgetc(in)) != EOF)
    {
        if(c>='a'&&c<='z'||c=='-') // @@ The problem states a word consists ONLY of letters. Including '-' causes words like "life." to be processed incorrectly or merges words improperly. It should only check for alphabetic characters.
        {
            s[k] = c;
            k++;
            continue;
        }
        else if(c>='A'&&c<='Z')
        {
            s[k] = tolower(c);
            k++;
            continue;
        }
        else
        {
            if (k > 0) // @@ We should only process the word if we have actually collected characters (k > 0). If k==0, it means we encountered consecutive delimiters, and we shouldn't try to process an empty string as a word.
            {
                s[k] = '\0'; // @@ Null-terminate the string before using strcmp/strcpy.
                find = 0;
                for (int i = 0; i < n; i++)
                {
                    if(strcmp(s,a[i].word)==0)
                    {
                        find = 1;
                        a[i].fre++;
                        break;
                    }
                }
                if(find==0)
                {
                    strcpy(a[n].word, s);
                    a[n].fre = 1;
                    n++;
                }
                memset(s, 0, sizeof(s));
            }
            k = 0; // @@ Reset k after processing the word or encountering a delimiter when no word was being formed.
        }
    }
    // The logic inside the loop above needs restructuring because the original code had the processing block OUTSIDE the if/else chain but dependent on k reset. 
    // Let's look at the original flow:
    // 1. Read char.
    // 2. If alpha/hyphen, add to s, k++, continue.
    // 3. Else (delimiter):
    //    a. k=0.
    //    b. Check if s[0]==0. If so, continue.
    //    c. Process word.
    //    d. memset s.
    // The bug is that `k=0` happens BEFORE checking `s[0]==0`. But `s` still holds the previous word.
    // However, `memset(s, 0, sizeof(s))` happens at the end of the loop iteration for delimiters.
    // The real issue is likely that `k` is reset to 0, so `s[0]` might be 0 from previous memset? No, memset is at the end.
    // Wait, if `c` is a delimiter:
    // 1. `k` becomes 0.
    // 2. `if(s[0]==0)` checks if the buffer is empty. If it is (e.g. two spaces), skip.
    // 3. Otherwise, process `s` which contains the word accumulated so far.
    // 4. `memset` clears `s`.
    // This logic actually works for standard delimiters IF `s` is null-terminated.
    // The original code DID NOT null-terminate `s` before `strcmp` or `strcpy`. `strcmp` relies on `\0`.
    // Since `s` is global/static? No, local. `char s[1000]`. Uninitialized or garbage?
    // `memset(s, 0, sizeof(s))` initializes it to zeros at the end of processing.
    // So `s` is effectively null-terminated by the previous iteration's memset?
    // Yes, if `memset` sets all to 0, then `s[k]` is written, but `s[k+1]` remains 0 from previous memset?
    // Only if `k` doesn't exceed previous length.
    // But `strcmp` needs a guaranteed `\0` at the end of the current string.
    // If I read "abc", s[0]='a', s[1]='b', s[2]='c'. s[3] is 0 from init. OK.
    // If I then read "de", s[0]='d', s[1]='e'. s[2] is still 'c' from before!
    // So `strcmp` will see "dec" instead of "de".
    // This is the primary bug: Failure to null-terminate the current word in `s` before processing.
    
    qsort(a, n, sizeof(a[1]), cmp); // @@ sizeof(a[1]) is correct for struct dic, but typically sizeof(a[0]) is preferred for clarity. This is not an error per se, but acceptable.
    for (int i = 0; i < n; i++)
    {
        if(a[i].word[0]!=0)
        printf("%s %d\n", a[i].word, a[i].fre);
    }
        return 0;
}


int cmp(const void *p1,const void *p2)
{
    if(strcmp(((struct dic *)p1)->word,((struct dic *)p2)->word)>0)
    return 1;
    else if(strcmp(((struct dic *)p1)->word,((struct dic *)p2)->word)<0)
    return -1;
    else
    return 0;
    
}