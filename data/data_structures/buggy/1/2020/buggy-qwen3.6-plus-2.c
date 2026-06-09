#include <stdio.h>
int M[10] = {0}; // @@ Array size should be at least 11 to safely access index 10 when N=10.
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
            S[m] = '0'+i;      // @@ Missing space separator after the number; should assign ' ' to S[m+1].
            r(m+1,n-1);      // @@ Index should increment by 2 (m+2) to account for the space character.
            M[i] = 0;
        }    
}