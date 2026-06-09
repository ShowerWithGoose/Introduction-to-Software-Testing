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
    re[N+1] = '\0' ; @@ [The buffer 're' is of size 11, but when N=10, re[11] is out of bounds (valid indices are 0-10). Also, the null terminator should be placed at the end of the actual string, not fixed at re[N+1].]
    if(n == 0)
    {
        puts(re); @@ [Because the null terminator is incorrectly placed or missing for smaller N, this may print garbage or undefined behavior. The string 're' is not properly null-terminated in all cases.]
        return;
    }  
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                re[loc*2] = '0' + i; @@ [For numbers >= 10, '0' + i produces incorrect ASCII (e.g., i=10 gives ':'), but N<=10 so i=10 is possible. However, the problem states N<=10, so 10 must be handled as two characters, but the code treats all numbers as single-digit. This causes wrong output format and logic error.]
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}