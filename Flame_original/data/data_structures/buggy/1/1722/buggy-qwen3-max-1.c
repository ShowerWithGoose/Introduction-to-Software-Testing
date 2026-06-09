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
        puts(shu); // @@ [Using puts() outputs the string followed by a newline, but the problem requires each integer in the permutation to be separated by a space and no extra spaces at the end. Additionally, 'puts' prints characters as-is, so digits like '1' are printed as characters, but the output format expects space-separated integers — however, since we're storing digits as characters, this would print "123" instead of "1 2 3". The reference program correctly prints each character followed by a space.]
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