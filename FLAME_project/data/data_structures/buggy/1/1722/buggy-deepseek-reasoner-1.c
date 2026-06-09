#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0};
char shu[11]={'0'}; // @@ [Array too small for permutations with spaces; cannot handle two-digit numbers; initialization unnecessary. Using char array without spaces leads to wrong format.]
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ [Prints digits concatenated without spaces, violating output format requirement of space separation.]
        return;
    }
    for(int i=1; i<=N; i++)
    {
        if(yong[i] == 0 )
        {
            yong[i] = 1; 
            shu[m] = '0'+i; // @@ [Only works for single-digit numbers; for i>=10 yields incorrect character. Also does not insert space between numbers.]
            pailie(m+1,n-1);     
            yong[i] = 0;    
        }
    }
}


int main()
{
    scanf("%d",&N);
    pailie(0,N);

}