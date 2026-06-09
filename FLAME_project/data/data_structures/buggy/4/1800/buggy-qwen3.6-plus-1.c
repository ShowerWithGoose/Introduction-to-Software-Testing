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
    return strcmp(((word*)a)->w, ((word*)b)->w); // @@ The comparator receives pointers to 'word' structs, not char arrays. Casting to char* compares the raw memory of the struct incorrectly. It should cast to word* and compare the 'w' member.
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
            int found = 0; // @@ Variable to track if word was found
            for (int q = 0; q < i; q++)
            {
                if (!strcmp(k, a[q].w))
                {
                    a[q].n++;
                    found = 1; // @@ Mark as found
                    break;
                }
            }
            if (!found) // @@ If not found in existing list, add new word
            {
                strcpy(a[i].w, k);
                a[i].n = 1; // @@ Initialize count to 1, not increment uninitialized memory
                i++; // @@ Increment count of unique words only when adding a new one
            }
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