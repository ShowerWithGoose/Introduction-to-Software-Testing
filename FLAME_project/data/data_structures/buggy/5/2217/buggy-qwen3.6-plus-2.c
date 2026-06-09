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
            while(s1[i] != ' ') // @@ [The loop condition does not check for end of string (i < l1), causing out-of-bounds access or infinite loop if the last number is not followed by a space. Also fails to handle negative numbers as required by the problem description.]
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
            while(s2[i] != ' ' && i < l2) // @@ [Logic error: uses s2 and l2 instead of s1 and l1. This parses the second polynomial's string while trying to parse the first polynomial's exponents.]
            {
                sum = sum * 10 + s2[i] - '0'; // @@ [Logic error: accesses s2 instead of s1.]
                if(sum == 0 && i == l2 - 1) // @@ [Logic error: checks l2 instead of l1.]
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
            while(s2[i] !=  ' ') // @@ [The loop condition does not check for end of string (i < l2), causing out-of-bounds access if the last number is not followed by a space. Also fails to handle negative numbers.]
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
                if(sum == 0 && i == l2 - 1)
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
                int temp;
                temp = ans[j + 1].y;
                ans[j + 1].y = ans[j].y;
                ans[j].y = temp;
                int k;
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
            for(int j = i; j <= cnt; j++)
            {
                ans[j].x = ans[j + 1].x;
                ans[j].y = ans[j + 1].y;
            }
            cnt--;
            i--; // @@ [Missing decrement of i. After shifting elements left and decreasing cnt, the current index i now points to the next element that shifted into position i. Without i--, this new element is skipped in the comparison with the previous term, leading to incorrect merging of terms with the same exponent.]
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        if(ans[i].x != 0)
            printf("%lld %lld ", ans[i].x, ans[i].y);
    }
    return 0;
}