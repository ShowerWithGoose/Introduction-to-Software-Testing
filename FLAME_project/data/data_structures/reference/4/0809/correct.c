#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
    char chars[51];
    int times;
}word;
typedef word* wordptr;
char content[12301];
word a[1005];
int cmp(const void* p1, const void* p2)
{
    wordptr a = (wordptr)p1;
    wordptr b = (wordptr)p2;
    return strcmp(a->chars, b->chars);
}
int main()
{
    FILE* input = fopen("article.txt", "r");
    char x;
    x = fgetc(input);
    int i = 0;
    while (x != EOF)
    {
        if (isalpha(x))
        {
            x = tolower(x);
        }
        content[i++] = x;
        x = fgetc(input);
    }
    int no = 0, j, k,len = strlen(content);
    for (i = 0; i < len; i++)
    {
        if (isalpha(content[i]))
        {
            for (j = i; j < len; j++)
            {
                if (!isalpha(content[j]))
                {
                    break;
                }
            }
            for (k = 0; k < j - i; k++)
            {
                a[no].chars[k] = content[i+k];
            }
            no++;
            i = j;
        }
    }
    qsort(a, no, sizeof(word), cmp);
    for (i = 0; i < no; i++)
    {
        a[i].times = 1;
    }
    for (i = 0; i < no; i++)
    {
        if (0 == strcmp(a[i].chars, a[i + 1].chars))
        {
            a[i + 1].times += a[i].times;
            a[i].times = 0;
        }
    }
    qsort(a, no, sizeof(word), cmp);
    for (i = 0; i < no; i++)
    {
        if (a[i].times != 0)
        {
            printf("%s %d\n", a[i].chars, a[i].times);
        }
    }
    return 0;
}

