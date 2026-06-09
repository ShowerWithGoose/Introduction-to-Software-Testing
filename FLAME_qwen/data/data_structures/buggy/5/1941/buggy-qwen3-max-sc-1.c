#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    int b;
}yuansu;
yuansu k1[1000], k2[1000], jie[1000000];
char scan_k1[20000], scan_k2[20000];
int my_scanf(char* s, yuansu* k)
{
    int qt = 0;
    while ((s[0] >= '0' && s[0] <= '9') || s[0] == '-')
    {
        sscanf(s, "%d", &k[qt].a);
        while (s[0] != ' ')
            s++;
        sscanf(++s, "%d", &k[qt].b);
        while (s[0] != ' ' && s[0])
            s++;
        qt++, s++;
    }
    return qt;
}
int cmp(const void* x, const void* y)
{
    int p = *(int*)x;
    int q = *(int*)y;
    return -jie[p].b + jie[q].b;
}
int a[1000000];
int main()
{
    fgets(scan_k1, 20000, stdin);
    fgets(scan_k2, 20000, stdin);
    char* sk1 = scan_k1, * sk2 = scan_k2;
    int s1 = my_scanf(sk1, k1);
    int s2 = my_scanf(sk2, k2);
    int qt = 0;

    a[0] = 0; // @@ [This line is unnecessary and misleading; `a` is an index array for sorting, but initializing a[0]=0 here has no effect since the loop below overwrites all `a[i]` values. However, the real critical error is in `my_scanf` logic and pointer handling.]

    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt;
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) // @@ [The condition `i < qt` is always true here because loop condition is `i < qt - 1`, but more critically, incrementing `i` inside the loop can cause skipping terms or out-of-bound access when `i` reaches `qt-1` and then `i++` makes it `qt`, leading to `a[i+1]` being out of bounds. Also, merging logic is flawed—it only merges consecutive duplicates after sort, but doesn't handle cases where merged term becomes zero and should be skipped later.]
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++;
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b);
    return 0;
}