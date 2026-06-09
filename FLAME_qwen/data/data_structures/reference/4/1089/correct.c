#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char s[1000];
    int num;
} p[2000];
int cmp(const void *a, const void *b)
{
    struct node *c = (struct node *)a;
    struct node *d = (struct node *)b;
    return strcmp(c->s, d->s);
}
int main()
{
    FILE *fp = fopen("article.txt", "r");
    char str[10000];
    int i = 0, j = 0, k = 0;
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        str[i] = c;
        i++;
    }
    for (i = 0; i < strlen(str); i++)
    {
        if ((isalpha(str[i])) == 0)
        {
            j++;
            k = 0;
        }
        else
        {
            p[j].s[k] = tolower(str[i]);
            k++;
        }
    }
    qsort(p, j, sizeof(p[0]), cmp);
    for (k = 0; k < j; k++)
    {
        if (strlen(p[k].s) != 0)
            p[k].num = 1;
    }
    for (k = 0; k < j; k++)
    {
        if (!strcmp(p[k].s, p[k + 1].s))
        {
            p[k + 1].num += p[k].num;
            p[k].num = 0;
        }
    }
    for (k = 0; k < j; k++)
    {
        if (p[k].num != 0)
            printf("%s %d\n", p[k].s, p[k].num);
    }
    return 0;
}


