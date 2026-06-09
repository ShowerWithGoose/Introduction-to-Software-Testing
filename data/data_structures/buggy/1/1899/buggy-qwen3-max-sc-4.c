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
            if(a%k==2) @@ // This condition `a%k==2` is incorrect and causes extra newlines. It should not print newline inside the loop since each permutation must be on its own line. Also, when k<=2, `a%k==2` is never true, so newline is missing. The newline should be printed once after the loop.
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