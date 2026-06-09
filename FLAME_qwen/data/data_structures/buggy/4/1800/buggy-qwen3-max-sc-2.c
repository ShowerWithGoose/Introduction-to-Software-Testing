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
        x = fgetc(in); // @@ [If fopen fails (in == NULL), this leads to undefined behavior by reading from a NULL file pointer. The program should check if 'in' is NULL after fopen.]
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
                else if (q == i - 1) // @@ [When i == 0 (first word), this condition (q == -1) never triggers, so the first word is never added to the array. Also, a[i].n is incremented without being initialized to 1.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [a[i].n starts at 0 (due to initialization), so incrementing gives 1, but logic is flawed because this block may not execute for the first word.]
                }
            }
            i++;
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