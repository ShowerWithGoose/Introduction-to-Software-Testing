#include<stdio.h>
int used[11] = {0}, N;
char re[11]; // @@ Buffer too small for N>=5; for N=10, need at least 21 characters.
void rank(int n, int loc);
int main()
{
    int n;
    scanf("%d", &N);
    rank(N, 0);

    return 0;
}

void rank(int n, int loc)
{
    re[N+1] = '\0' ; // @@ Writes beyond array bounds when N=10 (index 11, array size 11).
    if(n == 0)
    {
        puts(re);
        return;
    }  
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                re[loc*2] = '0' + i; // @@ For i>=10, produces wrong character; should handle two-digit numbers.
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}