#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int N;
int a[11]={0};
int b[11]={0};
void m(int n);
int main()
{
    scanf("%d",&N);
    m(1);
    return 0;
}
void m(int n)
{
    int i;
    if(n>N)
    {
        for(i=1;i<=N;i++)
        {
            printf("%d", a[i]); // @@ The output format is incorrect. Integers should be separated by spaces, but here they are printed consecutively without separators. Also, there is no newline character printed after each permutation.
        }
        return;
    }
    for(i=1;i<=N;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            a[n]=i;
            m(n+1);
            b[i]=0;
        }
    }
}