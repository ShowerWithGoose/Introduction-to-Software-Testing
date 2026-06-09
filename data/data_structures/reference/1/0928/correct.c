#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long
void fuc(int a[], int flag[], int n, int i, int ans[])
{
    int j, k;
    if(i == n+1)
    {
        for(j = 1; j <= n; j++)
            printf("%d ", ans[j]);
        printf("\n");
    }
    else
    {
        for(k = 1; k <= n; k++)
        {
            if(flag[k]==0)
            {
                ans[i]=a[k];
                flag[k]=1;
                fuc(a, flag, n, i+1, ans);
                flag[k]=0;
            }
        }
    }
}
int main()
{
    int n, a[100], ans[100] = {0}, flag[100] = {0}, i;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
        a[i] = i;
    fuc(a, flag, n, 1, ans);
    return 0;
}



