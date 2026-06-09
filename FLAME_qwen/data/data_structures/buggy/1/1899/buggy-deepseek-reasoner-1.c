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
            if(a%k==2) // @@ [The condition for printing newline is incorrect. It should print a newline only after all numbers are printed, not based on a modulo condition. This results in missing newlines for many k values and incorrect line breaks for others. The correct approach is to print a newline after the loop.]
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