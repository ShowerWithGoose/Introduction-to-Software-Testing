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
        puts(S);    
        return;
    }
    for(i=1; i<=N; i++)
        if(M[i] == 0 ){
            M[i] = 1;     
            S[m] = '0'+i; // @@ Missing space: should also set S[m+1]=' ' and use m+2 in recursion.
            r(m+1,n-1); // @@ Should be r(m+2,n-1) to account for the inserted space.
            M[i] = 0;
        }    
}