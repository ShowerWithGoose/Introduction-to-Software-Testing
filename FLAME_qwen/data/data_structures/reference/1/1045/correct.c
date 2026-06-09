#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
int n;
int judge[20];
int num[20];
void Print(void)
{
    for(int i = 1; num[i] != -1; i++)
        printf("%d ", num[i]);
    printf("\n");
    return;
}
void dp(int sum, int k, int h)
{
    if (sum == n)
    {
        Print();
    }
    for (int k = 1; k <= n; k++)
    {
        if (judge[k] == 0)
        {
            num[h] = k;
            judge[k] = 1;
            dp(sum + 1, 0, h + 1);
            judge[k] = 0;
            //if(flag == 0)
            //  return;
        }
    }
}
int main()
{
    memset(num, -1, sizeof(num));
    scanf("%d", &n);
    dp(0, 1, 1);
    return 0;
}


