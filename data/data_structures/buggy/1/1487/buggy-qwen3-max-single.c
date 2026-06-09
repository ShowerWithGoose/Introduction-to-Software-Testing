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
    for(j=m;j<=n;j++) // @@ [The recursive call to generate permutations is made even when the base case condition (m == n+1) is not met, because there's no 'else' block. This causes extra unnecessary iterations after printing a permutation, leading to incorrect behavior and potentially duplicate or malformed outputs.]
    {
        swap(s, m, j);
        perm(s, m+1, n);
        swap(s, m, j);
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