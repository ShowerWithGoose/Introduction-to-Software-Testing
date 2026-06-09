#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int queue[15];
int dp[15];
void f(int M, int n)
{
    if(n == 0)
    {
        for(int i = M; i >= 1;i--)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= M; i++)
    {
        if(dp[i] == 0)
        {
            dp[i] = 1;
            queue[n] = i;
            f(M,n-1);
            dp[i] = 0;
        }
    }
}
int main()
{
    int n;
	scanf("%d",&n);
	f(n,n);
	
	return 0;
} 
