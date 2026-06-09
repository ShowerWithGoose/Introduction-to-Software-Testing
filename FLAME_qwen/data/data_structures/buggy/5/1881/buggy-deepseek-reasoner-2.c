#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct part
{
    long long int xs;//系数
    long long int zs;//指数
};
struct part sen1[100], sen2[100], ans[100000],mid;
int main()
{
    int i = 0,j=0,k=0,p,q;

    for (i = 0;; i++)
    {
        scanf("%lld %lld", &sen1[i].xs, &sen1[i].zs);
        if (getchar() == '\n')
            break;
    }
    for (j = 0;; j++)
    {
        scanf("%lld %lld", &sen2[j].xs, &sen2[j].zs);
        if (getchar() == '\n')
            break;
    }
    int n = 0; // @@ [C89 requires all declarations at the beginning of a block; declaration after statements is not allowed]
    for (p = 0; p < i+1; p++)
    {
        for (q = 0; q < j+1; q++)
        {
            ans[n].xs = sen1[p].xs * sen2[q].xs;
            ans[n].zs = sen1[p].zs + sen2[q].zs;
            n++;
        }
    }
    for (int j = 0; j < n; j++) // @@ [C89: variable declaration inside for initializer is not allowed]
    {
        for (int i = j; i < n; i++) // @@ [C89: variable declaration inside for initializer not allowed; also out-of-bounds access when i = n-1 because ans[i+1] is beyond array]
        {
            if (ans[i].zs < ans[i + 1].zs)
            {
                mid = ans[i];
                ans[i] = ans[i + 1];
                ans[i + 1] = mid;
            }
            else if (ans[i].zs == ans[i + 1].zs)
            {
                ans[i].xs = ans[i].xs + ans[i + 1].xs;
                ans[i + 1].xs = 0;
            }
        }
    }
    for (int i = 0; i <n; i++) // @@ [C89: variable declaration inside for initializer is not allowed]
    {
        if(ans[i].xs!=0)
        {
            printf("%lld %lld ", ans[i].xs, ans[i].zs);
        }
    }
}