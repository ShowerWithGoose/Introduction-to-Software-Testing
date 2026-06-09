#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
int a[11];
void reverse(int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
int main(void)
{
    int i, j, n, temp, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    while (1)
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        for (i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
                break;
        }
        if (i == 0)
            break;
        for (j = k = i + 1; j <= n; j++)
        {
            if (a[j] < a[k] && a[j] > a[i])
                k = j;
        }
        temp = a[k];
        a[k] = a[i];
        a[i] = temp;
        reverse(i + 1, n);
        puts("");
    }
}


