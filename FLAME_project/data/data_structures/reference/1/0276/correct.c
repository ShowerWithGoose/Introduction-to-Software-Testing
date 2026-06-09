#include <stdio.h>
#define swap(a, b) a = (a) ^ (b), b = (a) ^ (b), a = (a) ^ (b);
int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

void re(int *a, int x, int y)
{
    for (int i = x, j = y; i < j; i++, j--)
        swap(*(a + i), *(a + j));
}
int a[10], b[10], flag[10], n, tag;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1, flag[i] = fact(n - 1 - i);
    for (int i = 0; i < n * flag[0]; i++)
    {
        tag = -1;
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[j]);
            putchar(' ');
            b[j]++;
            if (b[j] == flag[j])
            {
                if (tag == -1)
                    tag = j;
                b[j] = 0;
            }
        }
        putchar('\n');
        int t = n - 1;
        for (; a[t] < a[tag]; t--)
            ;
        swap(a[tag], a[t]);
        re(a, tag + 1, n - 1);
    }
    return 0;
}



