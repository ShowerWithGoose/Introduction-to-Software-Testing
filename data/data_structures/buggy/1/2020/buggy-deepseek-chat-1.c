#include <stdio.h>
int M[10] = {0}; 
char S[20]; 
void r(int m, int n);                   
int N;
int main ()
{
    scanf("%d", &N);    
    r(0,N);    
    return 0;
}
void r(int m, int n)
{
    int i;
    if(n==0){ 
        S[m] = '\0';
        puts(S); // @@ The output does not include spaces between numbers, so the permutations are printed as concatenated digits (e.g., "123") instead of "1 2 3". The reference program adds a space after each number.
        return;
    }
    for(i=1; i<=N; i++)
        if(M[i] == 0 ){
            M[i] = 1;     
            S[m] = '0'+i; // @@ No space is added after the digit, so numbers are concatenated without separators. The reference program uses two positions: one for the digit and one for the space.
            r(m+1,n-1); // @@ The index m is incremented by 1, but the reference program increments by 2 to account for the space character. This causes the output to lack spaces.
            M[i] = 0;
        }    
}