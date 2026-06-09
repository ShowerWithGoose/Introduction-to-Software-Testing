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
        while (s[0] != ' ')
            s++; @@ // If the input ends without trailing space, this loop may run past the null terminator, causing undefined behavior.
        sscanf(++s, "%d", &k[qt].b);
        while (s[0] != ' ' && s[0])
            s++;
        qt++, s++; @@ // After processing the last term, s might already be at '\0'; incrementing again skips valid end and may cause out-of-bound access in next iteration.
    }
    return qt;
}
int cmp(const void* x, const void* y)
{
    int p = *(int*)x;
    int q = *(int*)y;
    return -jie[p].b + jie[q].b; @@ // This comparison function may cause integer overflow if exponents are large; also, it returns positive when p should come before q, but standard qsort expects negative for that. However, main issue is logic in merging terms later.
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
            a[qt] = qt; @@ // a[qt] is set after incrementing qt, so a[0] remains 0, and indices in a[] become off-by-one: a[1]=1,...,a[qt]=qt, but jie indices are 0..qt-1.
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) @@ // Loop condition checks i < qt after accessing a[i+1]; also, modifying i inside while can skip terms or go out of bounds.
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++; @@ // Incrementing i here and in for-loop causes skipping of next term; also, after i++, i may become >= qt-1 and break loop prematurely.
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b); @@ // Due to incorrect indexing in a[], and incomplete merging, output may include zero coefficients or miss merged terms.
    return 0;
}