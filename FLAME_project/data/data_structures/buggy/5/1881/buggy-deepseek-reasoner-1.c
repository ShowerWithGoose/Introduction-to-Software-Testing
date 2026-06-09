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
    int n = 0;
    for (p = 0; p < i+1; p++)
    {
        for (q = 0; q < j+1; q++)
        {
            ans[n].xs = sen1[p].xs * sen2[q].xs;
            ans[n].zs = sen1[p].zs + sen2[q].zs;
            n++;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = j; i < n; i++) // @@ out-of-bounds: when i == n-1, ans[i+1] is accessed illegally; also this loop structure does not correctly sort all elements
        {
            if (ans[i].zs < ans[i + 1].zs) // @@ out-of-bounds access to ans[i+1] when i == n-1
            {
                mid = ans[i];
                ans[i] = ans[i + 1];
                ans[i + 1] = mid;
            }
            else if (ans[i].zs == ans[i + 1].zs) // @@ out-of-bounds access to ans[i+1] when i == n-1
            {
                ans[i].xs = ans[i].xs + ans[i + 1].xs; // @@ out-of-bounds access
                ans[i + 1].xs = 0; // @@ out-of-bounds access
            }
        }
    }
    for (int i = 0; i <n; i++)
    {
        if(ans[i].xs!=0)
        {
            printf("%lld %lld ", ans[i].xs, ans[i].zs);
        }
    }
}