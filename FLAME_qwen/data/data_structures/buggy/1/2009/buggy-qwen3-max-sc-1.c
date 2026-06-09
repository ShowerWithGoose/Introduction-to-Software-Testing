#include<stdio.h>
int used[11] = {0}, N;
char re[11];
void rank(int n, int loc);
int main()
{
    int n; // @@ [This local variable 'n' is unused and shadows the global 'N', but not the direct cause of the output error. However, the real issue is buffer overflow in 're'.]
    scanf("%d", &N);
    rank(N, 0);

    return 0;
}

void rank(int n, int loc)
{
    re[N+1] = '\0' ; // @@ [Buffer overflow: 're' is of size 11, but for N=10, this writes to re[11], which is out of bounds (valid indices: 0-10). Also, null terminator placement is incorrect—it should be at the end of the actual string, not fixed at N+1.]
    if(n == 0)
    {
        puts(re); // @@ [Because 're' is not properly null-terminated at the correct position (due to overwriting or missing termination after last number), this may print garbage or crash. Also, extra trailing space causes format mismatch.]
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
                re[loc*2+1] = ' '; // @@ [This always adds a trailing space at the end of each permutation, violating the required output format which expects space-separated numbers without trailing space.]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}