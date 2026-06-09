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
            printf("%c ",N[a]); // @@ The output format requires space-separated integers on a single line followed by a newline. Printing a space after every character including the last one before the newline check is problematic, but the main issue is the newline logic below. Also, %c prints characters '1', '2' etc which is acceptable for digits 1-9, but standard practice might prefer %d if stored as ints. However, keeping with char array, %c is okay. The critical error is the newline placement.
            if(a%k==2) // @@ This condition `a%k==2` is incorrect for printing a newline after each permutation. For N=2, k=2, when a=0, 0%2!=2. When a=1, 1%2!=2. The loop finishes without printing a newline between permutations or at the end correctly in all cases. More importantly, for N=2, the expected output is "1 2 \n" (with trailing space often tolerated or not, but usually just values). The reference code prints "%c " then "\n". Here, we need to print a newline after the entire permutation is printed. The condition should likely be removed and a simple printf("\n") placed after the loop. Additionally, for N=2, the buggy output shows "1 2 2 1" on one line or missing newlines. The specific failure "1 2 2 1" vs "1 2 " suggests that newlines are missing between permutations.
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