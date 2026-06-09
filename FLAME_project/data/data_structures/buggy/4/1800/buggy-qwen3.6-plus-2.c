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
    return strcmp(((word*)a)->w, ((word*)b)->w); // @@ [The comparator receives pointers to 'word' structs, not char arrays. Casting directly to char* compares the raw memory of the struct (starting with the char array but potentially including padding or incorrect offset interpretation if not careful, but primarily it fails to access the .w member explicitly for string comparison).]
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
            int found = 0; // @@ [Logic error: The original code increments 'i' unconditionally outside the loop, even if the word was found and updated. It also fails to add new words correctly if the list is empty (i=0) because the loop doesn't run. We need to track if the word was found.]
            for (int q = 0; q < i; q++)
            {
                if (!strcmp(k, a[q].w))
                {
                    a[q].n++;
                    found = 1; // @@ [Mark that the word was found and updated.]
                    break;
                }
            }
            if (!found) // @@ [Only add a new word if it wasn't found in the existing list.]
            {
                strcpy(a[i].w, k);
                a[i].n = 1; // @@ [Initialize count to 1 for new words. The original code did a[i].n++ which relies on zero-initialization but is semantically clearer as assignment here, and crucially, this block must only execute for new words.]
                i++; // @@ [Increment the word count only when a new word is added.]
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