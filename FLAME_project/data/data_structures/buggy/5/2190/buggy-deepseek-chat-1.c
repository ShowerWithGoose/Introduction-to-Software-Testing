#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct name {
    int a;
    int b;
}duo;
duo m[1000];
duo n[1000];
duo ans[100000];

void cmp(const void* p, const void* q)
{
    duo* x = (duo*)p;
    duo* y = (duo*)q;
    if (x->b > y->b) return -1;
    else if (x->b < y->b) return 1;
    else return 0;
}


int main()
{
    char p;
    char q;
    int len1 = 0, len2 = 0;
    for (int i = 0;; i++)
    {
        len1++;
        scanf("%d%c%d%c", &m[i].a, &p, &m[i].b, &q);
        if (q == '\n')
        {
            break;
        }
    }
    for (int i = 0;; i++)
    {
        len2++;
        scanf("%d%c%d%c", &n[i].a,&p, &n[i].b,&q);
        if (q=='\n')
        {
            break;
        }
    }
    int t = 0;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            ans[t].a = m[j].a * n[i].a;
            ans[t].b = m[j].b + n[i].b;
            t++;
        }
    }
    qsort(ans, t, sizeof(ans[0]), cmp);

    for (int i = 0; i < t; i++)
    {
        if (ans[i].b == ans[i - 1].b) // @@ [Error: When i=0, ans[i-1] accesses ans[-1], which is out-of-bounds and causes undefined behavior. This leads to incorrect merging of like terms.]
        {
            ans[i].a += ans[i - 1].a;
            ans[i - 1].a = 0;
        }
    }

    for (int i = 0; i < t; i++)
    {
        if (ans[i].a != 0)
            printf("%d %d ", ans[i].a, ans[i].b);
    }
}