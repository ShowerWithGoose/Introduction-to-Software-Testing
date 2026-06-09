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
    for (p = 0; p < i+1; p++) // @@ The loop condition should be p < i, not p < i+1, because i is the index of the last element, so the number of elements is i+1, but the loop already starts from 0, so p < i+1 will iterate one extra time accessing out-of-bounds memory.
    {
        for (q = 0; q < j+1; q++) // @@ Same issue: the loop condition should be q < j, not q < j+1, because j is the index of the last element, so the number of elements is j+1, but the loop already starts from 0, so q < j+1 will iterate one extra time accessing out-of-bounds memory.
        {
            ans[n].xs = sen1[p].xs * sen2[q].xs;
            ans[n].zs = sen1[p].zs + sen2[q].zs;
            n++;
        }
    }
    for (int j = 0; j < n; j++) // @@ The variable j shadows the earlier j, but the main issue is the sorting logic: the inner loop condition i < n is incorrect because when i = n-1, ans[i+1] accesses out-of-bounds memory. Also, the bubble sort should have j < n-1 and i < n-1-j.
    {
        for (int i = j; i < n; i++) // @@ The inner loop should be i < n-1, not i < n, to avoid accessing ans[i+1] out of bounds. Additionally, the sorting algorithm is flawed because it does not properly bubble the largest element to the end.
        {
            if (ans[i].zs < ans[i + 1].zs)
            {
                mid = ans[i];
                ans[i] = ans[i + 1];
                ans[i + 1] = mid;
            }
            else if (ans[i].zs == ans[i + 1].zs) // @@ This merging logic is incorrect because it only merges adjacent equal exponents during sorting, but after swapping, the same exponent may not be adjacent. Also, merging should be done after sorting, not during sorting.
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