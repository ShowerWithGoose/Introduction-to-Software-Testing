#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ [The base case should trigger when step > n or step == n+1 because the recursion starts at step=0 and fills a[step+1]. As written, it stops one step too early, causing incomplete permutations. Also, the condition should be step == n only if indexing starts at 0 for positions, but here a[step+1] is used, so when step == n-1, we fill the nth position. Thus, this condition leads to missing the last assignment or misalignment.]
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ [Missing space between numbers as required by output format. Should be "%d " instead of "%d".]
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ [Because the initial call is FullArray(0, n), step+1 starts at 1, which is okay for 1-based array a[]. However, the base case condition step == n causes the function to print before all n positions are filled. For n=2, step goes: 0 -> sets a[1]; then step=1 -> sets a[2]; then step=2 triggers base case. But in current code, when step == n (i.e., 2), it prints, which is correct in terms of count, BUT the loop runs again after returning from recursion without a return statement after the base case, leading to extra iterations and possibly duplicate or incorrect behavior. More critically, there's no 'return' after printing, so the function continues into the for-loop even after completing a permutation.]
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
    FullArray(0,n); // @@ [Starting with step=0 is acceptable only if the logic aligns, but due to the flawed base case and lack of return after printing, it causes issues. The reference program starts at step=1 and uses step>n as termination. Here, starting at 0 requires careful handling, which is not done correctly.]
    return 0;
}