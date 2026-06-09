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
    for (p = 0; p < i+1; p++) // @@ Error: The loop condition should be p < i, not p < i+1, because i is the index of the last element, so the number of elements is i (since i starts at 0 and increments after each read). Using i+1 causes an out-of-bounds access to sen1[i] which contains uninitialized data.
    {
        for (q = 0; q < j+1; q++) // @@ Error: Same issue as above; should be q < j, not q < j+1, to avoid accessing sen2[j] which is uninitialized.
        {
            ans[n].xs = sen1[p].xs * sen2[q].xs;
            ans[n].zs = sen1[p].zs + sen2[q].zs;
            n++;
        }
    }
    for (int j = 0; j < n; j++) // @@ Error: The variable j shadows the earlier j, but the main issue is the sorting logic. The inner loop condition i < n allows i+1 to go out of bounds when i = n-1, accessing ans[n] which is uninitialized.
    {
        for (int i = j; i < n; i++) // @@ Error: When i = n-1, ans[i+1] accesses ans[n], which is out of bounds. This can cause undefined behavior and incorrect merging of like terms.
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
    for (int i = 0; i <n; i++)
    {
        if(ans[i].xs!=0)
        {
            printf("%lld %lld ", ans[i].xs, ans[i].zs);
        }
    }
}