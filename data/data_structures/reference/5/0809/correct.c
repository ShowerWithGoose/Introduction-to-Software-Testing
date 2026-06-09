#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct num {
    int coe;
    int pow;
}a[2003],b[2003],out[2003];
typedef struct num num;
typedef struct num* numptr;
int cmp(const void* p1, const void* p2)
{
    numptr a = (numptr)p1;
    numptr b = (numptr)p2;
    return b->pow - a->pow;
}
int main()
{
    int i, j, k, x1=0, x2=0;
    char x;
    do {
        scanf("%d%d%c", &a[x1].coe, &a[x1].pow, &x);
        x1++;
    } while (x != '\n');
    do {
        scanf("%d%d%c", &b[x2].coe, &b[x2].pow, &x);
        x2++;
    } while (x != '\n');
    qsort(a, x1, sizeof(num), cmp);
    qsort(b, x2, sizeof(num), cmp);
    k = 0;
    for(i=0;i<x1;i++)
    {
        for(j=0;j<x2;j++)
        {
            out[k].coe=a[i].coe*b[j].coe; 
            out[k].pow=a[i].pow+b[j].pow;
            k++;
        }
    }
    qsort(out, k, sizeof(num), cmp);
    for (i = 0; i < k; i++)
    {
        if (out[i].pow == out[i + 1].pow && out[i].pow != 0)
        {
            out[i + 1].coe += out[i].coe;
            out[i].coe = 0;
        }
    }
    qsort(out, k, sizeof(num), cmp);
    for (i = 0; i < k; i++)
    {
        if (out[i].coe != 0)
        {
            printf("%d %d ", out[i].coe, out[i].pow);
        }
        else
        {
            continue;
        }
    }
    return 0;
}

