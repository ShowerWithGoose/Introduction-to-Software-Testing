#include "stdio.h"
void swap(int a[], int p, int q);
void back(int a[], int p, int q);
void print(int a[], int l, int r);
int main()
{
    int N;
    int a[20];
    scanf("%d", &N);
    int i;
    for (i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }
    print(a, 0, N - 1);
}
void print(int a[], int l, int r)
{
    int i;
    if (l == r)
    {

        for (i = 0; i < r + 1; i++)
        {
            printf("%d ", a[i]); // @@ [The output format requires integers to be separated by a space. The original code printed "%d" without a space, causing numbers to concatenate (e.g., "12" instead of "1 2").]
        }
        printf("\n");
    }
    else
    {
        for (i = l; i < r + 1; i++)
        {
            swap(a, i, l);
            print(a, l + 1, r);
            back(a, i, l);
        }
    }
}
void swap(int a[], int p, int q)
{
    int temp;
    temp = a[p];
    int i;
    for (i = p; i > q; i--)
    {
        a[i] = a[i - 1];
    }
    a[q] = temp;
}
void back(int a[], int p, int q)
{
    int temp;
    int i;
    temp = a[q];
    for (i = q; i < p; i++)
    {
        a[i] = a[i + 1];
    }
    a[p] = temp;
}