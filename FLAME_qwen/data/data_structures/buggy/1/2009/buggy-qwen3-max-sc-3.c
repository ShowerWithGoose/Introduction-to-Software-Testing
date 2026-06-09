#include<stdio.h>
int used[11] = {0}, N;
char re[11];
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
    re[N+1] = '\0' ; // @@ [The buffer 're' is of size 11, but when N=10, re[11] is out of bounds (valid indices are 0-10). Also, the null terminator should be placed at the end of the actual string, not fixed at re[N+1].]
    if(n == 0)
    {
        puts(re); // @@ [The string 're' may not be properly null-terminated at the correct position because the null terminator is set before building the string, and overwriting may occur. Additionally, for N=10, the string requires 2*N bytes (e.g., "1 2 3 ... 10 " has more than 11 characters), causing buffer overflow.]
        return;
    }  
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                re[loc*2] = '0' + i; // @@ [This fails for i >= 10 because '0' + 10 is not a valid single character representation of "10". The code assumes all numbers are single-digit, which is invalid when N=10.]
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}