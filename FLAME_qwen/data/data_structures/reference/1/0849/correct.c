#include <stdio.h>
#include<string.h>
void f(int m, int n, int a1[], int a2[]);
int a1[15],a2[15];
int main()
{
    int n;
    scanf("%d", &n);
    f(0, n, a1, a2);
    return 0;
}
void f(int m, int n, int a1[], int a2[])
{
    int j;
    if(m >= n)
    {
        for (j = 0; j < n-1; j++)
            printf("%d ", a1[j]);
        printf("%d\n", a1[j]);
    }
    else if(m<n)
    {
        for(j = 0; j < n; j++)
        {
            if (a2[j] == 0)
            {   a1[m] = j + 1;
                a2[j] = 1;
                f(m + 1, n, a1, a2);
                a2[j] = 0;
            }
        }
    }
}


