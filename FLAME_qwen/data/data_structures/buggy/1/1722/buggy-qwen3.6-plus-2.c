#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0}; // @@ Array size should be at least 11 to safely access index 10 when N=10, otherwise it causes out-of-bounds access.
char shu[11]={'0'};
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ The output format requires spaces between integers, but puts prints the string without any separators.
        return;
    }
    for(int i=1; i<=N; i++)
    {
        if(yong[i] == 0 )
        {
            yong[i] = 1; 
            shu[m] = '0'+i;      
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