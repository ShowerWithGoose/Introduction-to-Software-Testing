#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0};
char shu[11]={'0'};
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ [The output uses puts() which prints characters without spaces between digits, but the problem requires space-separated integers. Also, storing numbers as characters like '1', '2' leads to concatenated output like "12" instead of "1 2".]
        return;
    }
    for(int i=1; i<=N; i++)
    {
        if(yong[i] == 0 )
        {
            yong[i] = 1; 
            shu[m] = '0'+i; // @@ [Storing integer i as a character (e.g., '1') instead of handling it as an integer for space-separated output causes incorrect formatting. The problem expects integers separated by spaces, not a string of digits.]
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