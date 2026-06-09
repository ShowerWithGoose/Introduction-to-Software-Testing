#include<stdio.h>
int used[11] = {0}, N;
char re[11]; // @@ Array too small for N >= 6; for N=10, indices up to 19 are used.
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
    re[N+1] = '\0' ; // @@ Incorrect null termination; N+1 may be out of bounds and does not match the actual string length.
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
                re[loc*2] = '0' + i; // @@ Only works for single‑digit numbers; for i=10, it yields ':' instead of "10".
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}