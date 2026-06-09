#include<stdio.h>
int used[11] = {0}, N;
char re[11]; // @@ Array size is too small to hold the permutation string for N up to 10, which requires at least 20 characters plus a null terminator, causing buffer overflow.
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
    re[N+1] = '\0' ;
    if(n == 0)
    {
        puts(re);
        return;
    }  
    else
    {
        for(int i = 1; i <= N; i++) // @@ Declaring a variable inside the for-loop initialization is not allowed in C89/C90 standards, causing a compilation error in strict environments.
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                re[loc*2] = '0' + i; // @@ When i equals 10, '0' + 10 results in ':' instead of "10", leading to incorrect output for N=10.
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}