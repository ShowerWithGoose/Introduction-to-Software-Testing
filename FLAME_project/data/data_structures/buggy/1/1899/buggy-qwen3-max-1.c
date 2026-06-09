#include <stdio.h>
int M[11] = {0}; 
char N[11]; 
void rank(int m, int n);                   
int k;
int main ()
{
    scanf("%d",&k);    
    rank(0,k);    
    return 0;
}
void rank(int m,int n)
{
    int i;
    if(n==0)
    { 
        N[m]='\0';
        for(int a=0;a<k;a++)
        {
            printf("%c ",N[a]);
            if(a%k==2) // @@ [The condition `a%k==2` is incorrect. It should print a newline after each complete permutation (i.e., after printing k numbers), but this condition only triggers when remainder is 2, which never happens for k=2 (a=0→0%2=0, a=1→1%2=1). Thus, no newline is printed after the first permutation, causing both permutations to appear on the same line. Also, newline should be printed once per permutation, not inside the loop based on modulo.]
            printf("\n");
        }
        return;
    }
    for(i=1;i<=k;i++)
        if(M[i]==0 )
        {
            M[i]=1;
            N[m]='0'+i;
            rank(m+1,n-1);
            M[i]=0;
        }        
}