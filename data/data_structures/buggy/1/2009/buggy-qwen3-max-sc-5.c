#include<stdio.h>
int used[11] = {0}, N;
char re[11];
void rank(int n, int loc);
int main()
{
    int n; // @@ [This local variable 'n' is unused and shadows the global 'N', but not the direct cause of the compilation error. However, the real issue is that the array 're' is too small to hold the output string including spaces and null terminator for N=10.]
    scanf("%d", &N);
    rank(N, 0);

    return 0;
}

void rank(int n, int loc)
{
    re[N+1] = '\0' ; // @@ [The buffer 're' is declared as char re[11], but for N=10, the required length is 2*N (for digits and spaces) + 1 (null terminator) = 21. Writing to re[N+1] (e.g., re[11] when N=10) overflows the buffer, causing undefined behavior. Also, setting the null terminator here is incorrect because it's overwritten in deeper recursions. The null terminator should be set only when printing.]
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
                re[loc*2+1] = ' '; // @@ [For the last number in the permutation, a trailing space is added, which violates the output format. Also, the buffer size is insufficient for N=10: 10 numbers need 19 characters (e.g., "1 2 3 4 5 6 7 8 9 10" actually needs more due to two-digit number '10'), but the code assumes single-digit numbers only. This causes both buffer overflow and incorrect output for N>=10.]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}