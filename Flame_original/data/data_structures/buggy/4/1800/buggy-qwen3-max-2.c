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
    return strcmp((char*)a, (char*)b); // @@ [The comparison function casts struct pointers to char*, but should cast to word* and compare the 'w' fields. This causes undefined behavior and incorrect sorting.]
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
        x = fgetc(in); // @@ [If fopen fails (in == NULL), this dereferences a null pointer, causing undefined behavior/crash. Missing NULL check after fopen.]
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
                else if (q == i - 1) // @@ [This logic only adds a new word when reaching the last existing entry. If the array is empty (i==0), this block never runs, so first word is never added. Also, it increments i even if word was found and counted, leading to uninitialized entries being printed later.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [Should be a[i].n = 1; because this is a new word. Using ++ on uninitialized value (though zero-initialized globally, but still logically wrong).]
                }
            }
            i++; // @@ [i is incremented regardless of whether the word was new or existing, causing i to overcount and leading to printing of zero-count or uninitialized words.]
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