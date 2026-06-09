#include <stdio.h>
int M[10] = {0}; // @@ Array size is 10, but indices 1 to N (N<=10) are used, so index 10 is out-of-bounds. Should be at least 11.
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
        if(M[i] == 0 ){ // @@ When i = N = 10, accessing M[10] is out-of-bounds (array size 10, indices 0-9). Also missing space between digits; output will be concatenated digits.
            M[i] = 1; // @@ Same out-of-bounds issue.
            S[m] = '0'+i;      
            r(m+1,n-1); // @@ Recursion index should be m+2 to leave room for a space character. Also missing insertion of space after the digit.
            M[i] = 0; // @@ Same out-of-bounds issue.
        }    
}