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
            a[qt] = qt; // @@ The index array 'a' is populated starting from index 1, but 'a[0]' was initialized to 0 and included in the sort range. This means index 0 (uninitialized or default term) is part of the sorted list, potentially causing logic errors or including a zero term if not handled. More critically, the loop below iterates `i` from 0 to `qt-1`. If `a[0]` is 0, `jie[0]` might be garbage or zero. However, the main logical error is in the merging step.
        }
    qsort(a, qt, sizeof(int), cmp); // @@ The array 'a' has size `qt`, but valid indices were stored in `a[1]` to `a[qt-1]`? No, `qt` increments after assignment. Let's trace: `qt` starts at 0. Inside loop: `jie[0]` filled, `qt` becomes 1, `a[1]=1`. Next: `jie[1]` filled, `qt` becomes 2, `a[2]=2`. So `a[1...qt-1]` are valid indices. `a[0]` is 0. The sort range is `a[0]` to `a[qt-1]`. This includes `a[0]=0`. `jie[0]` was never explicitly initialized with valid polynomial data (it's global so it's 0,0). This adds a zero term to the result if not filtered.
    for (int i = 0; i < qt - 1; i++) // @@ The loop condition and increment logic are flawed. It modifies `i` inside the loop (`i++`) and also in the `for` statement (`i++`). This skips elements. Also, it only merges adjacent equal exponents once. If three terms have the same exponent, the first two merge, then `i` increments, skipping the check between the merged result and the third term.
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