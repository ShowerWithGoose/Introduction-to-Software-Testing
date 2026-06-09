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
            S[m] = '0'+i;      
            r(m+1,n-1);     
            M[i] = 0;
        }    
} // @@ [The program does not output permutations in lexicographical order because it lacks space separation between numbers and does not format output correctly. Additionally, the character array S stores digits without spaces, so multi-digit numbers (though not possible here since N<=10) would still be misrepresented, but more critically, the output format requires space-separated integers, which this code fails to produce. Also, when N=10, '0'+10 is not a valid single character representation of "10", causing incorrect output. However, given N<=10 and the problem expects integers 1 to N, when N=10, the number 10 cannot be represented as a single char by '0'+10, leading to wrong characters. But the immediate formatting error is missing spaces between numbers, causing all digits to be concatenated.]