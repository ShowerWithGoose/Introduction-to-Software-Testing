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
    re[N+1] = '\0' ; // @@ [The null terminator is placed at index N+1, but the string length for N numbers with spaces is 2*N - 1, so this may cause buffer overflow or incorrect termination. Also, for N=2, re[3]='\0', but valid indices are only 0..2 (for "1 2\0"), so it writes out of bounds.]
    if(n == 0)
    {
        puts(re); // @@ [The string 're' includes a trailing space after the last number because each recursive call appends a digit and then a space. This causes output like "1 2 " instead of "1 2", which fails lexicographical comparison and format requirements.]
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
                re[loc*2+1] = ' '; // @@ [This always adds a space after every number, including the last one, leading to an extra trailing space in the output line, which violates the required output format.]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}