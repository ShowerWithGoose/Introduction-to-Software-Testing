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
    return strcmp((char*)a, (char*)b); // @@ [The comparison function casts the struct pointers to char*, but it should cast to word* and then access the 'w' field. This causes incorrect sorting and undefined behavior.]
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
        x = fgetc(in); // @@ [If the file is empty or cannot be read, fgetc returns EOF immediately, but the program doesn't check if 'in' is NULL after fopen, leading to potential crash. Also, x should be declared as int to properly handle EOF.]
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
                else if (q == i - 1) // @@ [This logic fails when i == 0 (first word), because q == i-1 becomes q == -1, which never executes. Thus, the first word is never added to the array.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [a[i].n is incremented from 0 to 1, but it should be set to 1 directly since it's a new word. However, since the array is zero-initialized, this works by accident. The real issue is the missing addition for the first word.]
                }
            }
            i++; // @@ [i is incremented even if no word was added (e.g., when i==0 and the loop doesn't add the word), causing gaps and uninitialized entries.]
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