#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // @@ [Including <math.h> is unnecessary and may cause issues in some environments, though not directly a compilation error; however, the real issue is missing check for NULL file pointer leading to undefined behavior on failed fopen]
#include <ctype.h>
typedef struct
{
    char w[20];
    int n;
}word;
int cmp(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b); // @@ [Incorrect cast: should cast to `word*` and then access `.w`; passing raw struct pointers to strcmp causes undefined behavior and likely crash or wrong comparison]
}
int main()
{
    FILE* in;
    in = fopen("article.txt", "r");
    word a[100] = { 0 };
    int i = 0, flag = 0;
    while (1)
    {
        int x = 0, j = 0;
        char k[20] = { 0 };
        x = fgetc(in); // @@ [No check if `in` is NULL before reading; if file doesn't exist, this leads to undefined behavior (likely crash), which may manifest as a runtime error but could also cause compilation/linking issues in restricted environments]
        while ((x>= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            k[j] = tolower(x);
            j++;
            flag = 1;
            x = fgetc(in);
        }
        if (x == -1)
            break;
        if(flag)
        {
            for (int q = 0; q < i; q++)
            {
                if (!strcmp(k, a[q].w))
                {
                    a[q].n++;
                    break;
                }
                else if (q == i - 1) // @@ [Logic flaw: when i==0 (first word), loop doesn't run, so first word is never added. Also, even when i>0, new words are only added when reaching last existing entry, but `i` is incremented regardless, causing uninitialized entries]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [a[i].n is incremented from 0 to 1, but if struct was zero-initialized, this works; however, due to earlier logic flaw, first word is missed]
                }
            }
            i++; // @@ [Incrementing `i` even when no word was added (e.g., first word case), leading to counting empty/zero entries]
        }
        flag = 0;
    }
    qsort(a, i, sizeof(a[0]), cmp);
    for (int q = 0; q < i; q++)
    {
        printf("%s %d\n", a[q].w, a[q].n);
    }
    return 0; 
}