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
    while ((s[0] >= '0' && s[0] <= '9') || s[0] == '-') @@ // The loop condition fails when input starts with negative number followed by space; also doesn't handle end-of-string properly leading to infinite loop or undefined behavior.
    {
        sscanf(s, "%d", &k[qt].a);
        while (s[0] != ' ')
            s++; @@ // If the string ends without trailing space, this loop runs past null terminator causing undefined behavior.
        sscanf(++s, "%d", &k[qt].b);
        while (s[0] != ' ' && s[0])
            s++;
        qt++, s++; @@ // After processing last term, s may point beyond valid memory; incrementing again causes out-of-bounds access.
    }
    return qt;
}
int cmp(const void* x, const void* y)
{
    int p = *(int*)x;
    int q = *(int*)y;
    return -jie[p].b + jie[q].b; @@ // Incorrect comparison logic: should return negative if p's exponent > q's for descending order, but current logic may cause unstable sort and wrong ordering.
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

    a[0] = 0; @@ // Unnecessary and misleading initialization; a[0] will be overwritten in the loop below.
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt; @@ // Indexing error: a[qt] is set after increment, so a[0] remains uninitialized (was set to 0 above but not consistently), and a indices don't correctly map to jie elements during sorting.
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) @@ // Loop condition checks i < qt too late; may access a[i+1] when i == qt-1, causing out-of-bounds read. Also, inner while modifies i inconsistently with outer for-loop increment.
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++; @@ // Modifying loop variable inside loop leads to skipped terms or double-processing.
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b); @@ // May print zero coefficients if merging didn't fully eliminate them due to flawed merging logic above; also doesn't guarantee descending order due to incorrect sort/merge.
    return 0;
}