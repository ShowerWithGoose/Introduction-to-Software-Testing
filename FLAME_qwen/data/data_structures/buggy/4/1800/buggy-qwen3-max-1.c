#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct
{
    char w[20];
    int n;
}word;
int cmp(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b); // @@ [The comparison function incorrectly casts the struct pointers to char*. It should cast to 'word*' and then access the 'w' field.]
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
        x = fgetc(in); // @@ [If the file is empty or cannot be read, fgetc returns EOF immediately, but the loop logic doesn't handle this before entering the inner while loop. Also, if in == NULL (file not opened), this causes undefined behavior.]
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
                else if (q == i - 1) // @@ [This condition only adds a new word when reaching the last existing entry. If the array is empty (i == 0), this block never runs, so the first word is never added.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [a[i].n is uninitialized; it should be set to 1, not incremented.]
                }
            }
            i++; // @@ [i is incremented even if no new word was added (e.g., when a duplicate is found and break occurs), causing gaps and incorrect indexing.]
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