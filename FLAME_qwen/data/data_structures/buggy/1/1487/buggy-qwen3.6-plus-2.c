#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void swap(int s[], int a, int b)
{
    int t=s[a];
    s[a]=s[b];
    s[b]=t;
 } 
void perm(int s[], int m, int n)
{
    int i, j, t;
    if(m==n+1)
    {
        for(i=0;i<=n;i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    for(j=m;j<=n;j++)
    {
        swap(s, m, j); // @@ The swap operation disrupts the relative order of the remaining elements, which prevents generating permutations in lexicographical order. A rotation-based approach or a used-array should be used.
        perm(s, m+1, n);
        swap(s, m, j); // @@ The backtracking swap fails to restore the correct order for lexicographical generation in subsequent iterations.
    }
}

int main()
{
    int N, i, s[10000];
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++)
    {
        s[i] = i+1;    
     } 
    
    perm(s, 0, N-1);
     
    return 0;
}