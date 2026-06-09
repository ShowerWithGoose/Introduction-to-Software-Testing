#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int a[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void str_rev(int s[], int high, int low)
{
    int temp;
    for (; high > low; low++, high--)
    {
        temp = s[low];
        s[low] = s[high];
        s[high] = temp;
    }
}

int main()
{

    int i, j, n, temp, flag = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]); // @@ The output format requires integers to be separated by a space, but the original code prints them without spaces.
    printf("\n");
    while (flag)
    {
        flag = 0;

        for (i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            break;

        for (j = n; j > 1; j--) // @@ The loop condition should be j >= 1 or j > i to ensure all elements are checked, although logically j>i is sufficient here. However, the standard next_permutation algorithm searches from the end. The current logic `j > 1` might skip index 1 if needed, but since `i >= 1`, `a[i]` is at least `a[1]`. If `i=1`, we need to check `a[1]` against `a[j]`. The loop `j > 1` stops at `j=2`. It should be `j >= 1` or more precisely `j > i` to find the smallest element greater than `a[i]` from the right. Actually, standard algorithm finds the *rightmost* element greater than `a[i]`. Since the suffix is decreasing, the first one found from right is the smallest one greater than `a[i]`? No, it's just the one to swap. The condition `j > 1` is risky if `i=0` (but indices are 1-based here). If `i=1`, `j` goes down to 2. If `a[1] < a[2]`, we swap. If `a[1] < a[1]` is false. So `j` must go down to `i+1`. The loop `j > 1` fails to check `a[1]` against `a[1]` which is trivial, but it fails to check `a[i]` against `a[i+1...n]`. Wait, if `i=1`, we need to find `j` such that `a[j] > a[1]`. The loop runs for `j=n` down to `2`. It misses `j=1`? No, `a[j] > a[i]` with `j=i` is false. So `j` only needs to go down to `i+1`. The loop `j > 1` is incorrect because if `i=1`, it checks `n` down to `2`. This is correct for `i=1`. But what if `i=2`? Loop `j > 1` checks `n` down to `2`. It includes `j=2`. But we need `j > i`, so `j >= 3`. If `j=2` is checked and `a[2] > a[2]` is false. So it's logically okay-ish but inefficient. However, the critical error is usually the output format. Let's look closer. `j > 1` means `j` stops at 2. If `i=1`, we check `j=2..n`. Correct. If `i=2`, we check `j=2..n`. We only need `j=3..n`. Checking `j=2` is harmless as `a[2] > a[2]` is false. So this line is not the primary cause of WA, but `j > i` is better. However, there is a subtle bug: if `i` is found, we swap. Then reverse `i+1` to `n`.
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                break;
            }
        }

        str_rev(a, n, i + 1);
        for (i = 1; i <= n; i++)
            printf("%d ", a[i]); // @@ The output format requires integers to be separated by a space, but the original code prints them without spaces.
        printf("\n");
    }

    return 0;
}