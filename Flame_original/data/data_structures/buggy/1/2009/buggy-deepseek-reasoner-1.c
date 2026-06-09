#include<stdio.h>
int used[11] = {0}, N;
char re[11]; // @@ size insufficient, should be larger (e.g., 50) to accommodate N=10 and two-digit numbers.
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
    re[N+1] = '\0' ; // @@ incorrect null termination; should be placed at the end of the string after recursion.
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
                re[loc*2] = '0' + i; // @@ fails for i=10; does not handle two-digit numbers.
                re[loc*2+1] = ' '; // @@ adds space after each number, including last; trailing space may be undesirable.
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}