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
        puts(S);    @@ [The output uses puts() which prints the string without spaces between digits. The problem requires each integer in a line to be separated by a space. Also, the string S stores characters like '1', '2', etc., so "12" is printed instead of "1 2".]
        return;
    }
    for(i=1; i<=N; i++)
        if(M[i] == 0 ){
            M[i] = 1;     
            S[m] = '0'+i;      @@ [Storing digits as characters without spaces leads to concatenated output like "12" instead of "1 2". The program should store integers or format output with spaces.]
            r(m+1,n-1);     
            M[i] = 0;
        }    
}