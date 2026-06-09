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
            a[qt] = qt;
        }
    qsort(a, qt, sizeof(int), cmp);
    for (int i = 0; i < qt - 1; i++) // @@ The loop condition and increment logic are flawed. When merging terms with the same exponent, if multiple consecutive terms share the same exponent, the current logic might skip some or fail to merge all of them correctly because `i` is incremented inside the while loop AND by the for loop. More critically, if `jie[a[i+1]].a` becomes 0, it should be skipped in output, but the merging logic here assumes adjacent sorted elements are the only ones to merge. However, the primary issue leading to Wrong Answer here is likely that `qsort` sorts indices based on `jie` values, but `jie` is being modified during the merge loop? No, `jie` values are constant after generation. The issue is that `qsort` sorts `a` such that `jie[a[i]].b` is descending. The merge loop combines `a[i]` and `a[i+1]` if exponents match. If `jie[a[i+1]].a` is added to `jie[a[i]].a`, `jie[a[i+1]].a` becomes 0. This is correct for marking it as empty. However, the loop `while (jie[a[i]].b == jie[a[i + 1]].b && i < qt)` has a boundary check `i < qt` which accesses `a[i+1]` when `i` can be `qt-1`, causing out-of-bounds access or incorrect logic. Specifically, if `i` reaches `qt-1`, `a[i+1]` is invalid. The condition `i < qt` allows `i` to be `qt-1`, then `a[i+1]` is accessed. It should be `i < qt - 1`.
        while (jie[a[i]].b == jie[a[i + 1]].b && i < qt)
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