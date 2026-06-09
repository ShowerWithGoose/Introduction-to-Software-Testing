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
        int len=strlen(shu);
        for(int j=0;j<len;j++)
        {
            printf("%c",shu[j]);
            printf("%c",' ');
        }
        printf("\n");
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

