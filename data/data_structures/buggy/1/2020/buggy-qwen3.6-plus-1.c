#include <stdio.h>
int M[10] = {0}; // @@ Array size is 10, but indices go up to N (max 10), causing out-of-bounds access when N=10. Should be size 11.
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
        puts(S);    
        return;
    }
    for(i=1; i<=N; i++)
        if(M[i] == 0 ){
            M[i] = 1;     
            S[m] = '0'+i; // @@ Missing space separator after the number. Should also assign S[m+1] = ' '; to match the required output format.
            r(m+1,n-1); // @@ Should advance index by 2 (m+2) to account for the space character, otherwise numbers will be concatenated without spaces.
            M[i] = 0;
        }    
}