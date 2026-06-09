#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<string.h>
#include <stdio.h>
struct word {
    char name[100];
    int num;
    int turn;
}a[1000];
char s[100];   char ss[100];
int main()
{
    FILE* p;
    p = fopen("article.txt", "r");
    int l1, i, j = 0, k = 0, cnt = 0, t;
    while (fgets(s,sizeof(s),p) != NULL)
    {
        l1 = strlen(s);
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        for (i = 0; i < l1; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                a[k].name[j] = s[i];
                j++;
            }
            else if (s[i] == ' '||s[i]=='.'||s[i]==';') // @@ [Only space, period, and semicolon are treated as delimiters; many punctuation marks (e.g., comma, exclamation) are not handled, causing words to be incorrectly merged or not terminated. Also, consecutive delimiters produce empty words because there is no check for j>0 before incrementing count.]
            {
                a[k].num += 1; // @@ [Missing null terminator for the word string. a[k].name[j] should be set to '\0' before incrementing count. Also, if j==0 (empty word due to consecutive delimiters), this line incorrectly counts an empty word.]
                cnt += 1;
                k += 1;
                j = 0;
            }
            else
                continue;
        }
        memset(s, 0, sizeof(s));
    } // @@ [After the while loop, the last word in the file may not have been counted if it was not followed by a delimiter. There is no code to finalize an unfinished word (i.e., one where j>0).]
    for (i = 0; i < cnt; i++)
    {
        for (j = cnt ; j > i; j--) // @@ [j starts at cnt, which is out of bounds (valid indices are 0 to cnt-1). Should be j = cnt-1. This causes access to uninitialized memory or out-of-bounds array element.]
        {
            if (strcmp(a[i].name, a[j].name) == 0)
            {
                a[i].num += a[j].num;
                a[j].num = 0;
            }
        }
    } // @@ [The duplicate merging logic is flawed. Words are not removed from the list, and later iterations may accidentally merge zeroed entries, resulting in duplicate non-zero entries for the same word.]
    for (j = 0; j < cnt; j++)
    {
        for (i = 0; i < cnt - 1; i++)
        {
            if (strcmp(a[i].name, a[i + 1].name) > 0)
            {
                strcpy(ss, a[i].name);    t = a[i].num;
                strcpy(a[i].name, a[i + 1].name);    a[i].num = a[i + 1].num;
                strcpy(a[i + 1].name, ss);    a[i + 1].num = t;
            }
        }
    } // @@ [Sorting relies on strcmp, but the word strings lack null terminators, leading to undefined behavior (comparing garbage). Additionally, entries with num=0 and leftover name strings are sorted unnecessarily.]
    for (i = 0; i < cnt; i++)
    {
        if (a[i].num != 0)
            printf("%s %d\n", a[i].name, a[i].num);
    }
    fclose(p);
}