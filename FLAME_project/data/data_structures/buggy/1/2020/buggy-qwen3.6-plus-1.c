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
        S[m] = '\0'; // @@ The output format requires spaces between numbers, but puts(S) prints the string without spaces. Also, using a char array to store multi-digit numbers (if N > 9, though constraint is 10) or simply formatting as "1 2" is harder with this approach. The main issue is the missing spaces between digits in the output.
        puts(S);     // @@ This prints the permutation without spaces between numbers (e.g., "12" instead of "1 2"). The expected output requires space-separated integers.
        return;
    }
    for(i=1; i<=N; i++)
        if(M[i] == 0 ){
            M[i] = 1;     
            S[m] = '0'+i;      
            r(m+1,n-1);     
            M[i] = 0;
        }    
}