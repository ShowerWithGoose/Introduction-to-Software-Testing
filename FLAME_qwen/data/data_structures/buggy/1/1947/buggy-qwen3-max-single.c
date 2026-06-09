#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n)
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ [The array 'a' is indexed starting from 1, but the permutation should be printed with space-separated values. Also, missing space after each number except the last. However, the primary error causing incorrect output is indexing: 'a' should be filled and printed from index 0 or consistently from 1. Here, 'step' starts at 0, but 'a[step+1]' is used, so a[1..n] is filled. But in printing, it prints a[1] to a[n], which is correct in content, but the output format requires spaces between numbers. This line prints digits without spaces, violating output format.]
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ [The recursion uses 1-based indexing for array 'a', but the initial call is FullArray(0, n). This leads to a[1] being the first element. While logically workable, it causes inconsistency if not handled carefully. However, the main issue is in printing without spaces. But note: the reference program prints with space after every number including the last, which is acceptable per problem (each integer separated by space). This program prints no spaces at all, which is wrong.]
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