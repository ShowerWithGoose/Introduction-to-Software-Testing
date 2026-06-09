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
    return strcmp((char*)a, (char*)b); // @@ [Error: cmp function expects pointer to word struct, but casts to char* and compares raw struct memory. Although the first member is a char array, this is not portable and can cause incorrect sorting or undefined behavior if there is padding. Should cast to word* and compare w fields.]
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
        if (x == -1) // @@ [Error: If the last character in the file is a letter, the word is built but this break occurs before processing it, so the last word is missing. Should process the word first or restructure logic.]
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
                else if (q == i - 1)
                {
                    strcpy(a[i].w, k);
                    a[i].n++;
                }
            }
            i++; // @@ [Error: i is incremented unconditionally after the for loop. If a word is found and break occurs, i still increases, causing i to be larger than the actual number of unique words, leading to uninitialized entries in later processing. Also, when i==0, the for loop doesn't execute, and i++ makes i=1 without adding the first word.]
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