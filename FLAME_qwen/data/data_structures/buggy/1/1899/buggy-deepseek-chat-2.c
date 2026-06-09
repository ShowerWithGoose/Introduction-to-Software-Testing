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
            if(a%k==2) // @@ [Error: This condition is incorrect. It should print a newline after every k elements (i.e., after each permutation), but a%k==2 only triggers when a is 2, 5, 8, etc., which is not the correct logic. The correct condition should be after the loop ends or use a separate check to print newline only once per permutation.]
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