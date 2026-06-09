#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ The base case condition is incorrect. It should be `step == n` but the logic inside assumes 1-based indexing for `a` while starting from 0, or it misses printing the last element. More critically, the recursion structure and printing logic are flawed compared to the reference. The reference prints when `step > n`. Here, if `step == n`, it prints `a[1]` to `a[n]`. However, `a` is filled at `a[step+1]`. So when `step` reaches `n-1`, `a[n]` is filled. Then `FullArray(n, n)` is called. Inside, `step==n` is true. It prints `a[1]...a[n]`. This part might seem okay logically for filling, BUT:
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ Missing space between numbers. The expected output requires spaces separating integers (e.g., "1 2").
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; 
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
    FullArray(0,n);
    return 0;
}