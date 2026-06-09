#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
struct word
{
    char w[20];
    int count;
} a[100];
int num;
int cmp(const void *a, const void *b)
{
    return strcmp(((struct word *)a)->w, ((struct word *)b)->w);
}
void del(char *p)
{
    while (*p != '\0')
    {
        if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z') || *p == ' ')
            p++;
        else
        {
            /* for (int i = 0; i <= strlen(p); i++)
            {
                *(p + i) = *(p + i + 1);
            } */
            *p = ' ';
        }
    }
}
int to_next(char **p)
{
    while (isalpha(*(*p)))
    {

        *p += 1;
    }
    if (*(*p) == '\0')
    {
        return -1;
    }
    else
        return 1;
}

int main()
{
    FILE *in;
    in = fopen("article.txt", "r");
    char input[500];

    while (fgets(input, 499, in) != NULL)
    {
        del(input);
        for (int i = 0; i < strlen(input); i++)
        {
            input[i] = tolower(input[i]);
        }
        struct word temp;
        struct word *q;
        char *p = input;
        while (*p == ' ')
        {
            p++;
        }
        while (1)
        {
            memset(&temp, 0, sizeof(temp));
            sscanf(p, "%s", temp.w);
            q = bsearch(&temp, a, num, sizeof(struct word), cmp);
            if (q != NULL)
            {
                q->count += 1;
            }
            else
            {
                a[num] = temp;
                a[num].count = 1;
                num++;
                qsort(a, num, sizeof(struct word), cmp);
            }
            int flag = to_next(&p);
            if (flag == -1)
                break;
            else
            {
                while (*p == ' ')
                {
                    p++;
                }
            }
        }
    }
    for (int i = 1; i < num; i++)
    {
        printf("%s %d\n", a[i].w, a[i].count);
    }
    return 0;
}
