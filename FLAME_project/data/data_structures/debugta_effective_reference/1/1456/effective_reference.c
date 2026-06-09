#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int permutation(int a[], int n);
void exchange(int* a, int* b);
int main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    while (permutation(a, n))
    {
        for (int i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n - 1]);
    }
    return 0;
}

void exchange(int* a, int* b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int permutation(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i - 1] < a[i])
        {
            int min = i;
            for (int j = i; j < n; j++)
            {
                if (a[j] > a[i - 1])
                    min = j;
                else
                    break;
            }
            int temp = a[min];
            a[min] = a[i - 1];
            a[i - 1] = temp;
            for (int j = i, k = n - 1; j < k; j++, k--)
                exchange(&a[j], &a[k]);
            return 1;
        }
    }
    return 0;
}

