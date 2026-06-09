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
    return strcmp((char*)a, (char*)b); // @@ [The comparison function should cast to 'word*' and compare the 'w' field, not treat the struct as a char array. This causes incorrect sorting or undefined behavior.]
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
        x = fgetc(in);
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
                else if (q == i - 1) // @@ [This condition adds a new word only when reaching the last existing entry, but if the word is new and i==0 (first word), this block never runs, causing missing words. Also, it increments i even if the word was found, leading to uninitialized entries being printed.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [Should be a[i].n = 1; because it's a new word, not incrementing from 0 which may be uninitialized (though zero-initialized here, logic is wrong).]
                }
            }
            i++; // @@ [i is incremented regardless of whether the word was found or not. If the word already exists, i still increases, creating empty/zero-count entries that get printed later.]
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