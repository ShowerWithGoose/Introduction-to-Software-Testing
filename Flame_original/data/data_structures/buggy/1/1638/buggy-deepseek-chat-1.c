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
            printf("%d", a[i]); // @@ [Error: Missing space between numbers. The output should have a space after each integer except possibly the last, but the problem requires spaces between all integers. The reference program prints "%d " with a trailing space, so this should be "printf("%d ", a[i]);" to match the expected format.]
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