#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
void permutation(int a[], int p, int max) // max是最大下标
{
    if (p == max)
    {
        print(a, max + 1);
    }
    for (int i = p; i <= max; i++)
    {
        if (i != p)
        {
            swap1(a, i, p);
        }
        permutation(a, p + 1, max);
        if (i != p)
        {
            swap2(a, i, p);
        }
    }
}
void print(int a[], int n) // n是输入的正整数
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap1(int a[], int i, int p)
{
    int temp;
    for (int j = i; j > p; j--)
    {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
    }
}
void swap2(int a[], int i, int p)
{
    int temp;
    for (int j = p; j < i; j++)
    {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
    }
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    a[n] = '\0';
    permutation(a, 0, n - 1);
    return 0;
}
