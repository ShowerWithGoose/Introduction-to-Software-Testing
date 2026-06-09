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
        puts(shu); // @@ [The output uses puts() which prints the string without spaces between digits, and adds a newline. However, the problem requires each integer in a line to be separated by a space. Also, storing numbers as characters like '1', '2' leads to concatenated output like "12" instead of "1 2".]
        return;
    }
    for(int i=1; i<=N; i++)
    {
        if(yong[i] == 0 )
        {
            yong[i] = 1; 
            shu[m] = '0'+i; // @@ [Storing integers as ASCII characters (e.g., '1', '2') instead of handling them as separate integers prevents proper space-separated output. This causes permutations to be printed as continuous strings like "12" rather than "1 2".]
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