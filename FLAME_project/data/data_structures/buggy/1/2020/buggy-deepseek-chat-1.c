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
        puts(S); // @@ [Error: puts() outputs the string without spaces between digits. The expected output requires spaces between each integer (e.g., "1 2" not "12"). Should print each character followed by a space, except possibly the last one.]
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