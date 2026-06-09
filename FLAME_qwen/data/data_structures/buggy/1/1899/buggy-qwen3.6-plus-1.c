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
        for(int a=0;a<k;a++) // @@ Compilation error: C89/C90 standard does not allow declaring loop variables inside the for statement. Declare 'int a;' before the loop.
        {
            printf("%c ",N[a]); // @@ Logical/Semantic error: Using char array and %c cannot correctly store/print the number 10, which requires two characters.
            if(a%k==2) // @@ Logical error: Incorrect condition for newline insertion. A newline should be printed once after all k numbers are output, not based on modulo 2.
            printf("\n");
        }
        return;
    }
    for(i=1;i<=k;i++)
        if(M[i]==0 )
        {
            M[i]=1;
            N[m]='0'+i; // @@ Semantic error: When i=10, '0'+10 results in ':', not "10". A char array cannot correctly represent two-digit numbers.
            rank(m+1,n-1);
            M[i]=0;
        }        
}