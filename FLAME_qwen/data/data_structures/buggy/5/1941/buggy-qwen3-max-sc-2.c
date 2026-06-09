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
    while ((s[0] >= '0' && s[0] <= '9') || s[0] == '-') @@ // The loop condition does not handle cases where the string starts with space or ends; also, after reading the last term, s may point to '\0', and incrementing s beyond that leads to undefined behavior.
    {
        sscanf(s, "%d", &k[qt].a);
        while (s[0] != ' ') @@ // If the input ends without trailing space, this loop may run past the end of the string, causing undefined behavior.
            s++;
        sscanf(++s, "%d", &k[qt].b);
        while (s[0] != ' ' && s[0]) @@ // This loop stops at space or null terminator, but after it, s++ is executed unconditionally, which may go beyond the string boundary.
            s++;
        qt++, s++; @@ // Unconditional increment of s after possibly already being at '\0' causes out-of-bounds access.
    }
    return qt;
}
int cmp(const void* x, const void* y)
{
    int p = *(int*)x;
    int q = *(int*)y;
    return -jie[p].b + jie[q].b; @@ // The comparator returns positive when p's exponent is less than q's, which sorts in ascending order, but problem requires descending order. Also, using global array `jie` inside comparator makes it non-reentrant and fragile.
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

    a[0] = 0; @@ // This initialization is unnecessary and misleading; the array `a` is supposed to hold indices for sorting, but a[0]=0 is immediately overwritten in the loop below if qt>0.
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt; @@ // Off-by-one: a[qt] is set after qt is incremented, so a[0] remains uninitialized (was set to 0 above, but that's coincidental). Should be a[qt-1] = qt-1 before increment, or set before increment.
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) @@ // Condition `i < qt` is always true here because loop condition is `i < qt - 1`; also, inner while may increment `i` beyond `qt - 2`, leading to out-of-bounds access in `a[i+1]`.
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++; @@ // Modifying loop variable inside body causes skipping of terms and potential missed merges.
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b); @@ // Output format may include trailing space, which is acceptable per problem, but more critically, merged terms with zero coefficient are skipped correctly. However, due to earlier logic errors in merging, some terms may not be merged properly.
    return 0;
}