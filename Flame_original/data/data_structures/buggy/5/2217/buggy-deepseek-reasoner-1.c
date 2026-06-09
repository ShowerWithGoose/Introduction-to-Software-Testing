#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct 
{
    long long x;
    long long y;
}ans[10000];

long long a[10000], b[10000], c[10000], d[10000];
char s1[10000], s2[10000];

int main()
{
    int x, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, p = 0, q = 0;
    gets(s1);
    int l1 = strlen(s1);
    for(int i = 0; i < l1; i++)
    {
        if(p == 0)
        {
            int sum = 0;
            while(s1[i] != ' ') // @@ Missing bounds check: should also check i < l1 to avoid reading past end of string
            {
                sum = sum * 10 + s1[i] - '0';
                i++;
            }
            p = 1;
            a[++cnt1] = sum;
        }
        else if(p == 1)
        {
            int sum = 0;
            while(s1[i] != ' ' && i < l1)
            {
                sum = sum * 10 + s1[i] - '0';
                if(sum == 0 && i == l1 - 1) // @@ Premature break causes skipping exponent indexing
                    break;
                i++;
            }
            p = 0;
            b[++cnt2] = sum;
        }
    }
    gets(s2);
    int l2 = strlen(s2);
    for(int i = 0; i < l2; i++)
    {
        if(q == 0)
        {
            int sum = 0;
            while(s2[i] !=  ' ') // @@ Missing bounds check: should also check i < l2
            {
                sum = sum * 10 + s2[i] - '0';
                i++;
            }
            q = 1;
            c[++cnt3] = sum;
        }
        else if(q == 1)
        {
            int sum = 0;
            while(s2[i] != ' ' && i < l2)
            {
                sum = sum * 10 + s2[i] - '0';
                if(sum == 0 && i == l2 - 1) // @@ Premature break causes similar issue
                    break;
                i++;
            }
            q = 0;
            d[++cnt4] = sum;
        }
    }
//    for(int i = 1; i <= cnt2; i++)
//        printf("%d ", b[i]);
//    printf("\n");
    int cnt = 0;
    for(int i = 1; i <= cnt1; i++)
    {
        for(int j = 1; j <= cnt3; j++)
        {
            ans[++cnt].x = a[i] * c[j];
            ans[cnt].y = b[i] + d[j];
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = 1; j <= cnt - i; j++)
        {
            if(ans[j].y < ans[j + 1].y)
            {
                int temp; // @@ Using int for long long values may cause truncation; should be long long
                temp = ans[j + 1].y;
                ans[j + 1].y = ans[j].y;
                ans[j].y = temp;
                int k; // @@ Same issue: should be long long
                k = ans[j + 1].x;
                ans[j + 1].x = ans[j].x;
                ans[j].x = k;
            }
        }
    }
    for(int i = 2; i <= cnt; i++)
    {
        if(ans[i].y == ans[i - 1].y)
        {
            ans[i - 1].x += ans[i].x;
            for(int j = i; j <= cnt; j++) // @@ Out-of-bounds access when j == cnt (ans[j+1])
            {
                ans[j].x = ans[j + 1].x;
                ans[j].y = ans[j + 1].y;
            }
            cnt--; // @@ Should also decrement i to recheck the same index after shifting
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        if(ans[i].x != 0)
            printf("%lld %lld ", ans[i].x, ans[i].y);
    }
    return 0;
}