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

    a[0] = 0;
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt; // @@ Array out-of-bounds access: when qt reaches 1000000, a[qt] accesses index 1000000, which exceeds the valid range [0, 999999] for an array of size 1000000.
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) // @@ Logical error: modifying the loop variable i inside the while loop while the for loop also increments it causes incorrect iteration and skipped comparisons. Additionally, zeroing jie[a[i+1]].a before it can be accumulated to previous terms leads to incorrect coefficient sums when more than two terms share the same exponent.
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