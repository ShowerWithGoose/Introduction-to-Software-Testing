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
    re[N+1] = '\0' ; // @@ [The null terminator is placed at index N+1, but the string length should be 2*N (each number followed by space), and for N=2, valid indices are 0..3; also, extra trailing space causes wrong output format]
    if(n == 0)
    {
        puts(re); // @@ [This prints a trailing space at the end of each line, which violates the required output format (space-separated numbers without trailing space)]
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
                re[loc*2+1] = ' '; // @@ [Always adds a space after every number, including the last one, leading to trailing space in output]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}