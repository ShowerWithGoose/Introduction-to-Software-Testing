#include<stdio.h>
int a[20], b[20];

void FullArray(int step, int n)
{
    int i;
    if(step ==n)
    {
        for(i=1; i<=n; i++)
        {
            printf("%d", a[i]); // @@ [The output format requires each integer to be followed by a space, but this prints without spaces. Also, array indexing starts at 1 here, but the logic may misalign with step-based filling.]
        } 
        printf("\n");
    } 
    
    for(i=1; i<=n; i++)
    {
        if(b[i] == 0)
        {
            a[step+1] = i; // @@ [Array a is being filled starting from index 1 (since step starts at 0), but during output, it prints from index 1 to n, which is consistent. However, the main issue is missing space after each number in output. Additionally, the lexicographical order might not be guaranteed due to traversal order, but actually it is because i goes from 1 to n. The real critical error is missing space in output.]
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