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

    a[0] = 0; // @@ [This line incorrectly initializes only the first element of array 'a'; the rest remain uninitialized, but more critically, the logic of using an index array 'a' is flawed and unnecessary. Also, the loop below overwrites a[qt] starting from qt=0, making this assignment redundant and misleading.]

    for (int i = 0; i < s1; i++)
        for (int j = 0; j < s2; j++)
        {
            jie[qt].a = k1[i].a * k2[j].a;
            jie[qt].b = k1[i].b + k2[j].b;
            qt++;
            a[qt] = qt; // @@ [This assigns a[qt] = qt after incrementing qt, so a[1]=1, a[2]=2, etc., but a[0] was set to 0 earlier. However, the real issue is that the sorting and merging logic assumes 'a' holds indices into 'jie', but the initialization and usage are inconsistent and lead to incorrect grouping during merging.]
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++)
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt) // @@ [The condition 'i < qt' is checked too late; if i == qt-1, then a[i+1] accesses out-of-bounds. Also, the inner while loop increments 'i', which interferes with the outer for-loop's increment, causing skipped elements or infinite loops. Moreover, setting jie[a[i+1]].a = 0 doesn't mark it for skipping reliably if multiple terms have same exponent.]
        {
            jie[a[i]].a += jie[a[i + 1]].a;
            jie[a[i + 1]].a = 0;
            i++;
        }
    for (int i = 0; i < qt; i++)
        if (jie[a[i]].a)
            printf("%d %d ", jie[a[i]].a, jie[a[i]].b); // @@ [Due to flawed merging logic above, some terms with zero coefficients may still be printed, or non-zero terms may be omitted. Also, the output order may not be strictly descending because the sort uses an indirect index array that isn't properly maintained during merging.]
    return 0;
}