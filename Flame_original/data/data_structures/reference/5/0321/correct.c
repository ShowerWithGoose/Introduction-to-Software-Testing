#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
struct expo
{
    int an;
    int n;
};
int next_num(char **p);
int cmp(const void *a, const void *b)
{
    return ((struct expo *)b)->n - ((struct expo *)a)->n;
}
struct expo a[100], b[100], c[1000], output[1000];

int main()
{
    char input[500];
    memset(input, 0, sizeof(input));
    int num_a = 0, num_b = 0;
    gets(input);
    char *p;
    p = input;
    for (num_a = 0; sscanf(p, "%d %d", &a[num_a].an, &a[num_a].n) != EOF; num_a++)
    {
        next_num(&p);
    }
    memset(input, 0, sizeof(input));
    gets(input);
    p = input;
    for (num_b = 0; sscanf(p, "%d %d", &b[num_b].an, &b[num_b].n) != EOF; num_b++)
    {
        next_num(&p);
    }
    //读取并存储
    int num_c = 0;
    for (int i = 0; i < num_a; i++)
    {
        for (int j = 0; j < num_b; j++, num_c++)
        {
            c[num_c].an = a[i].an * b[j].an;
            c[num_c].n = a[i].n + b[j].n;
        }
    }
    //相乘
    qsort(c, num_c, sizeof(struct expo), cmp);
    int num_out = 0;
    for (int i = 0; i < num_c;)
    {
        int j;
        for (j = i; c[j].n == c[i].n; j++)
        {
            output[num_out].an += c[j].an;
            output[num_out].n = c[j].n;
        }
        i = j;
        num_out++;
    }
    //去重
    for (int i = 0; i < num_out; i++)
    {
        printf("%d %d ", output[i].an, output[i].n);
    }
    return 0;
}

int next_num(char **p)
{
    int flag = 0;
    while (flag < 2)
    {
        if (*(*p) == '\0')
        {
            return -1;
        }
        if (*(*p) == ' ')
        {
            flag++;
        }
        *p += 1;
    }
    return 1;
}
