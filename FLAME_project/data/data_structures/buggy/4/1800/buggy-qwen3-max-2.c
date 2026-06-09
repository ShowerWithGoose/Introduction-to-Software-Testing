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
    return strcmp((char*)a, (char*)b); // @@ [The comparison function incorrectly casts the entire struct pointers to char*. It should cast to word* and then access the 'w' field.]
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
                else if (q == i - 1) // @@ [This condition adds a new word only when reaching the last existing word without a match, but fails to add the first word (when i==0). Also, it increments i unconditionally after the loop, causing uninitialized entries and duplicate additions.]
                {
                    strcpy(a[i].w, k);
                    a[i].n++; // @@ [Should be a[i].n = 1; because this is a new word.]
                }
            }
            i++; // @@ [i is incremented even when the word already exists (due to break), leading to skipped slots and uninitialized entries. Also, when i==0, the for loop doesn't run, so no word is added but i becomes 1, leaving a[0] uninitialized.]
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