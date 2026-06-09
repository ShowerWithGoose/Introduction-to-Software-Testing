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
    re[N+1] = '\0' ;
    if(n == 0)
    {
        puts(re);
        return;
    }  
    else
    {
        for(int i = 1; i <= N; i++) @@ Declaring a loop variable inside the 'for' initialization is not allowed in the C89/C90 standard, which causes a compilation error on strict compilers. The variable 'i' should be declared at the beginning of the function.
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                re[loc*2] = '0' + i;
                re[loc*2+1] = ' ';
                rank(n-1, loc + 1);
                used[i] = 0;
            }
            
        }
    }
}