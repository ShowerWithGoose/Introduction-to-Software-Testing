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
    return strcmp((char*)a, (char*)b); // @@ [Error] qsort passes pointers to 'word' structs. Casting to 'char*' compares raw struct memory instead of the string field 'w'. Should cast to 'word*' and compare '->w'.
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
        if (x == -1) // @@ [Error] If EOF is reached immediately after a word, the loop breaks before processing the last word stored in 'k'. The break should occur after processing the word.
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
                else if (q == i - 1) // @@ [Error] When i==0, the loop doesn't execute, so the first word is never stored. Also, checking only the last element is logically flawed for adding new words.
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [Error] Should be 'a[i].n = 1;' to correctly initialize the count for a newly added word.
                }
            }
            i++; // @@ [Error] 'i' is incremented for every word processed, not just unique words. This causes 'qsort' and the output loop to process uninitialized array elements. It should only increment when a new word is added.
            flag = 0;
        }
    }
    qsort(a, i, sizeof(a[0]), cmp);
    for (int q = 0; q < i; q++)
    {
        printf("%s %d\n", a[q].w, a[q].n);
    }
    return 0; 
}