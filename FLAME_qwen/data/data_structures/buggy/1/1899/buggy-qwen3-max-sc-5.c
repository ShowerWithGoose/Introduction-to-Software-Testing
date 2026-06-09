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
            if(a%k==2) @@ [This condition is incorrect and unnecessary. It attempts to print a newline when a%k==2, but since a ranges from 0 to k-1, a%k is just a. This will print extra newlines at wrong positions (e.g., when a=2), breaking the required output format which expects exactly one permutation per line. Also, the newline should be printed after the loop, not inside based on this flawed condition.]
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