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
            printf("%d", a[i]); // @@ Missing space between numbers in output. Expected format has spaces between integers, e.g., "1 2", but this prints "12".
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