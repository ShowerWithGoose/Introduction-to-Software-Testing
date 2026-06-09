#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b);
void perm(int k, int n);
int group[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int main()
{
    int n;
    scanf("%d", &n);
    perm(0, n - 1);
    return 0;
}
void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return;
}
void perm(int k, int n)
{
    if (k == n)
    {
        for (int i = 0; i <= n; i++)
        {
            printf("%d ", group[i]);
        }
        printf("\n");
    }
    else
    {
        for (int j = k; j <= n; j++)
        {
            for (int i = j - 1; i >= k; i--)
                swap(&group[i], &group[i + 1]);
            perm(k + 1, n);
            for (int i = k; i <= j - 1; i++)
                swap(&group[i], &group[i + 1]);
        }
    }
} //循环向前即可保证升序，不须升序就直接交换
