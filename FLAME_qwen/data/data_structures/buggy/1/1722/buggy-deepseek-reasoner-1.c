#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0}; // @@ The array size should be 11 to accommodate indices up to 10 (since N ≤ 10). Using yong[10] leads to out-of-bounds access when i = N = 10.
char shu[11]={'0'};
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ Output format error: This prints the permutation as a continuous string without spaces, but the problem requires each integer separated by a space. The correct approach is to loop and print each character followed by a space, then a newline.
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