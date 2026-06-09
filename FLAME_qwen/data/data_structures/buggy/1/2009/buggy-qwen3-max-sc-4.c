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
    re[N+1] = '\0' ; // @@ [The array 're' has size 11, but when N=10, re[11] is out of bounds (valid indices are 0-10). Also, the null terminator should be placed at the end of the actual string, not fixed at re[N+1].]
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
                re[loc*2] = '0' + i;
                re[loc*2+1] = ' '; // @@ [This always adds a trailing space at the end of each permutation, which violates the output format. Also, for N=10, loc*2+1 can be up to 19, exceeding re's size of 11.]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}