#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0}; // @@ array size too small; for N=10, index 10 is out of bounds, should be yong[11] to accommodate indices 1..10
char shu[11]={'0'};
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ output missing spaces; should print each number separated by a space (e.g., printf("%d ", ...) or manually insert spaces in the string)
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