#include <stdio.h>
#include <string.h>
int N;
int yong[10]={0}; // @@ Array size should be 11 to accommodate indices 1..N for N up to 10. yong[10] is out of bounds.
char shu[11]={'0'};
void pailie(int m,int n)
{
    if(n==0)
    {
        shu[m]='\0';
        puts(shu); // @@ Should print numbers separated by spaces. Use a loop to print each character followed by a space, like in the reference.
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