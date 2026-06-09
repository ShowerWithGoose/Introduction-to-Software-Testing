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

void cmp(const void* p, const void* q) // @@ [The comparison function for qsort must return int, not void. This causes undefined behavior during sorting.]
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
        scanf("%d%c%d%c", &m[i].a, &p, &m[i].b, &q); // @@ [Incorrect scanf format: expects coefficient then exponent, but format string reads coeff, char, exponent, char. Should be "%d %d%c" or similar to match input "a_n n ...". This misreads input and causes wrong parsing.]
        if (q == '\n')
        {
            break;
        }
    }
    for (int i = 0;; i++)
    {
        len2++;
        scanf("%d%c%d%c", &n[i].a,&p, &n[i].b,&q); // @@ [Same error as above: incorrect scanf format leads to misreading polynomial terms.]
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
    qsort(ans, t, sizeof(ans[0]), cmp); // @@ [Passing a function returning void as comparison function to qsort is invalid. This is undefined behavior and likely causes crash or incorrect sort.]

    for (int i = 0; i < t; i++)
    {
        if (ans[i].b == ans[i - 1].b) // @@ [When i=0, accesses ans[-1], which is out-of-bounds memory access → undefined behavior.]
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