#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ The base case condition is incorrect. It should be `step == n` only if we are filling `a[1]` to `a[n]` starting from step 0, but the logic inside uses `step+1`. More importantly, it misses the print for the last permutation or prints prematurely. In the reference, it checks `step > n`. Here, if `step == n`, it prints, but the recursion continues. Also, the printing format is wrong (missing spaces).
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ Missing space between numbers. Should be `printf("%d ", a[i]);` to match expected output format.
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i;  // @@ Indexing issue. If `step` starts at 0, `a[1]` is filled first. This part is consistent with `i` starting at 1 in the loop below, but the base case and initial call need to align.
            b[i] = 1; 
            FullArray(step + 1, n); 
            b[i] = 0; 
        }
    }
} 
int main()
{
    int n;
    scanf("%d", &n);
    FullArray(0,n); // @@ Starting step at 0 is fine if `a[step+1]` is used, but the base case `step == n` means when `step` is `n`, we have filled `a[1]...a[n]`. However, the function doesn't return after printing, leading to duplicate outputs or incorrect behavior. It should return after printing. Also, the reference uses `step > n` as base case and starts with `step=1`.
    return 0;
}