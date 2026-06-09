#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct n {
    char s[10000];
    int num;
}a[10000];
int cmp(const void* a, const void* b)
{
    struct n* c = (struct n*)a;
    struct n* d = (struct n*)b;
    return strcmp(c->s, d->s);
}
int main()
{
    FILE* fp = fopen("article.txt", "r");
    char c;
    char b[10000]="";
    int i = 0;
    int flag = 0;
    if (fp!=NULL)
    {
        while (!feof(fp)) {
        c = fgetc(fp);
        b[i++] = c;
        }
        fclose(fp);
    }
    int len = strlen(b);
    i = 0;
    for (int t = 0; t < len; t++)
    {
        if (!isalpha(b[t]))
        {
            i++;
            flag = 0;
        }
        else if (isalpha(b[t])) {
            a[i].s[flag++] = tolower(b[t]);
        }
    }
    qsort(a, i, sizeof(a[0]), cmp);
    for (int t = 0; t < i; t++)
    {
        if (strlen(a[t].s))
        {
            a[t].num = 1;
        }
    }
    for (int t = 0; t < i; t++)
    {
        if (!strcmp(a[t].s, a[t + 1].s))
        {
            a[t + 1].num = a[t + 1].num + a[t].num;
            a[t].num = 0;
        }
    }
    for (int t = 0; t < i; t++)
    {
        if (a[t].num != 0)
        {
            printf("%s %d\n", a[t].s, a[t].num);
        }
    }
    return 0;
}

