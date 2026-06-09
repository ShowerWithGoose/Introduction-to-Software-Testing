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
            printf("%c ",N[a]); // @@ The output format requires integers separated by spaces, but here characters are printed. Also, the newline logic is incorrect.
            if(a%k==2) // @@ This condition is logically incorrect for printing newlines after each permutation. It should print a newline after the loop finishes, not based on this modulo condition which doesn't make sense for k=2.
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