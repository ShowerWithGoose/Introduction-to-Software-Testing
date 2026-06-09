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
        puts(S);     // @@ The output format is incorrect. puts prints the string without spaces between characters, but the expected output requires spaces between integers (e.g., "1 2" instead of "12"). Also, puts adds a newline, which is correct, but the spacing is wrong.
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