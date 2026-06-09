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
        puts(shu); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and then a newline. The current code stores digits as characters (e.g., '1', '2') and prints them directly with spaces missing between digits because puts() just prints the raw character array without inserting spaces. Additionally, the initial value of shu is {'0'}, which may cause leftover characters from previous calls if the array isn't fully overwritten.]
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