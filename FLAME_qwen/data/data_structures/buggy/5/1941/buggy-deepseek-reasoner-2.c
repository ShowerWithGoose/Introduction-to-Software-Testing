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
    for (int i = 0; i < s1; i++) // @@ Compilation error: C99-style declaration inside for loop not allowed in C90; also logical issue: variable 'i' declared here not at start of block.
        for (int j = 0; j < s2; j++) // @@ Same reason as above.
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt;
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++) // @@ Logical error: the outer loop together with the inner while causes incorrect merging of consecutive equal exponents. The algorithm skips indices and does not accumulate into the first element of each group.
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) // @@ Logical error: order of conditions is wrong; should check `i < qt - 1` first to avoid out-of-bounds access. Also the while loop increments `i` which interferes with the outer `for` increment.
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