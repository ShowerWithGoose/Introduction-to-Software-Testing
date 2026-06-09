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
        scanf("%d%c%d%c", &m[i].a, &p, &m[i].b, &q); // @@ [Incorrect scanf format: should read coefficient then exponent, but format "%d%c%d%c" expects coeff, char, exponent, char. Input format is "coeff exp", so it should be "%d %d%c" or similar to capture newline correctly. This leads to misreading input.]
        if (q == '\n')
        {
            break;
        }
    }
    for (int i = 0;; i++)
    {
        len2++;
        scanf("%d%c%d%c", &n[i].a,&p, &n[i].b,&q); // @@ [Same error as above: incorrect scanf format causing misreading of second polynomial.]
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
    qsort(ans, t, sizeof(ans[0]), cmp); // @@ [Passing a void-returning function 'cmp' to qsort which expects int-returning comparator. This is undefined behavior and likely causes crash or incorrect sort.]

    for (int i = 0; i < t; i++)
    {
        if (ans[i].b == ans[i - 1].b) // @@ [Accessing ans[-1] when i=0, leading to undefined behavior (buffer underflow).]
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