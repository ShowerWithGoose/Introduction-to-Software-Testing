#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct NODE {
    char word[32];
    int num;
    struct NODE* next;
}NODE;
struct NODE* h;
int getWord(FILE*in,char* w)
{
    memset(w, 0, sizeof w);
    int i = 0, flag = 0;
    char c;
    while ((c = fgetc(in)) != EOF)
    {
        if ((c>= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                w[i] = c + 'a' - 'A';
                i++;
            }
            else if (c >= 'a' && c <= 'z')
            {
                w[i] = c;
                i++;
            }
            while ((c = fgetc(in)) != EOF) // @@ The inner loop consumes characters including the first non-alpha character of the NEXT word or delimiter, but fails to handle the state correctly for subsequent calls. Specifically, when it breaks on a non-alpha, that character is consumed. However, the major logic error is that `getWord` returns 0 on success and -1 on failure (EOF/no word), but the main loop checks against EOF. More critically, the inner `while` loop structure is flawed for standard tokenization because it doesn't push back the non-alpha character. But the specific bug causing "languageing" etc is likely due to buffer not being cleared properly or logic flow. Actually, looking at the output "languageing", "languagetng", it seems words are concatenating or not resetting. 
            // Wait, let's look closer. `memset(w, 0, sizeof w)` is correct.
            // The issue is likely in how `getWord` handles the return value and loop termination.
            // If `getWord` returns 0 on success, `while(getWord(in,word)!= EOF)` will loop forever if it returns 0, because 0 != EOF (-1). It should check if return value indicates failure.
            // However, the garbled output suggests memory corruption or logic error in parsing.
            // Let's look at `insertWord`.
            {
                if (c >= 'A' && c <= 'Z')
                {
                    w[i] = c + 'a' - 'A';
                    i++;
                }
                else if (c >= 'a' && c<= 'z')
                {
                    w[i] = c;
                    i++;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (i == 0)
        return -1;
    else
        return 0;
}
int insertWord(NODE* p, char* w)
{
    NODE* q = (NODE*)malloc(sizeof(NODE));
    if (q == NULL) 
        return -1;
    strcpy(q->word, w);
    q->num = 1;
    q->next = NULL;
    if (h == NULL)
        h = q;
    else if (p == NULL)//?
    {
        q->next = h;
        h = q;
    }
    else
    {
        q->next = p->next;
        p->next = q;
    }
    return 0;
}
int searchWord(char* w)
{
    NODE* p = NULL, * q = NULL;
    for (p = h; p != NULL; q = p, p = p->next)
    {
        if (strcmp(w, p->word) < 0)
            break;
        else if (strcmp(w, p->word) == 0)
        {
            p->num++;
            return 0;
        }
    }
    return insertWord(q, w);
}
char word[32],c[32];
int main()
{
    FILE* in;
    NODE* p;
    in = fopen("article.txt", "r");
    while (getWord(in,word)!= EOF) // @@ The function getWord returns 0 on success and -1 on failure. EOF is typically -1. So this condition `!= EOF` means it continues when it returns 0 (success). However, if it returns -1 (failure/EOF), the loop terminates. This part is technically okay if -1 equals EOF. But the logic inside getWord is flawed because it doesn't ungetc the delimiter, causing the next call to potentially miss data or behave unexpectedly? No, the main issue with "languageing" is that `getWord` is not correctly isolating words. 
    // Actually, the primary error causing WA is often simpler. 
    // Let's re-read the garbled output: `languageing`, `languagetng`. 
    // This looks like `language` + `ing`? Or `statement` + `ng`?
    // In the input: `language book ...`.
    // If `getWord` reads `language`, stops at space. Next call reads `book`.
    // Why would they merge?
    // Ah, `memset(w, 0, sizeof w)` uses `sizeof w` where `w` is a pointer `char* w`. `sizeof w` is 4 or 8, not 32. So only the first 4-8 bytes are cleared. If a previous long word was stored, the tail remains.
    {
        searchWord(word);
    }
    for (p = h; p != NULL; p = p->next)
    {
        printf("%s %d\n", p->word, p->num);
    }
    fclose(in);
    return 0;
}