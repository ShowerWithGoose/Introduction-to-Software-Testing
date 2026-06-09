#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ Error: The base case should be step > n (or step == n+1) to print when all n positions are filled. With step == n, it prints after placing only n-1 elements, missing the last element.
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ Error: Missing space between numbers. Should be printf("%d ", a[i]); to match expected output format.
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ Error: This uses step+1 as index, but step starts at 0 and the base case checks step==n. This causes off-by-one issues. Should use a[step] = i with step starting at 1.
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
    FullArray(0,n); // @@ Error: Should start with step=1, not step=0, to align with 1-indexed array usage.
    return 0;
}