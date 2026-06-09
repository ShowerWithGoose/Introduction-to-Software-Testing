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
    re[N+1] = '\0' ; // @@ [The buffer 're' is declared as char re[11], which is too small. For N=10, the output requires 10 numbers + 9 spaces + null terminator = 20 characters. Writing to re[N+1] (i.e., re[11] when N=10) overflows the array, causing undefined behavior. Also, setting the null terminator here is incorrect because it's overwritten in recursive calls. The null terminator should be set only when printing.]
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
                re[loc*2+1] = ' '; // @@ [This always writes a space after every number, including the last one. The expected output format does not have a trailing space at the end of each line. Additionally, due to insufficient buffer size, this may write beyond allocated memory.]
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}