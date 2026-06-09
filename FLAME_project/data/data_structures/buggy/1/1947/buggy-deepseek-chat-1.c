#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n) // @@ Error: The base case should be step > n, not step == n, because when step equals n, only n-1 elements have been placed, and the nth element is not yet printed. Also, the condition should be step > n to print after all n elements are placed.
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ Error: Missing space between numbers. Should be printf("%d ", a[i]) to match expected output format with spaces.
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ Error: The array index should be a[step] (since step starts at 0, but the reference uses 1-indexed arrays). Using step+1 causes off-by-one and incorrect placement.
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
    FullArray(0,n); // @@ Error: The initial call should be FullArray(1, n) to match the 1-indexed array usage in the reference program. Starting at 0 leads to incorrect indexing.
    return 0;
}