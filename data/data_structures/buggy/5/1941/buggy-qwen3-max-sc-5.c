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
    while ((s[0] >= '0' && s[0] <= '9') || s[0] == '-') @@ // The loop condition fails when input starts with negative number followed by space; also, after last term, s may point to '\0', causing infinite loop or undefined behavior due to unchecked pointer increment.
    {
        sscanf(s, "%d", &k[qt].a);
        while (s[0] != ' ')
            s++; @@ // If the string ends without trailing space (as per problem: "no space after the last exponent"), this loop runs past null terminator, leading to undefined behavior.
        sscanf(++s, "%d", &k[qt].b);
        while (s[0] != ' ' && s[0])
            s++; @@ // After reading last term's exponent, s may become invalid or point beyond string; subsequent s++ in loop causes out-of-bound access.
        qt++, s++;
    }
    return qt;
}
int cmp(const void* x, const void* y)
{
    int p = *(int*)x;
    int q = *(int*)y;
    return -jie[p].b + jie[q].b; @@ // Incorrect comparison logic: should return negative if p > q for descending order, but this returns positive when jie[p].b < jie[q].b, causing ascending sort. Also, using global array `jie` inside comparator is fragile but not strictly wrong.
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

    a[0] = 0; @@ // Unnecessary and misleading initialization; `a` is used as an index array for sorting, but a[0]=0 is overwritten in the loop below.
    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt; @@ // Off-by-one: a[qt] is set after increment, so a[0] remains uninitialized (was set to 0 earlier, but that doesn't correspond to jie[0]). Should be a[qt-1] = qt-1 or initialize before increment.
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) @@ // Loop condition checks i < qt too late; if i == qt-1, a[i+1] is out of bounds. Also, inner while modifies i, which can skip terms or cause missed merges.
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++; @@ // Modifying loop variable inside while leads to skipping next pair; e.g., after merging i and i+1, next comparison should be i and i+2, but outer for-loop increments i again, causing i+3 to be compared.
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b); @@ // May print zero coefficients if merging didn't fully eliminate them (e.g., due to incorrect merging logic above). Also, output format requires descending exponents, but sort may be ascending due to cmp error.
    return 0;
}