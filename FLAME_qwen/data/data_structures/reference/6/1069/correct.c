#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char buf[BUFSIZ];
#define N 100
int main()
{
    int m,n,i=0,j,k;
    int a[120];
	while(scanf("%d",&m)!=EOF)
    {
        if(m==1)//»Î’ª
        {
            scanf("%d",&a[i]);
            i++;
        }
        if(m==0)//≥ˆ’ª
        {
            if(i-1<0)//’ª“—ø’
            {
                printf("error ");
            }
            else
            {
                printf("%d ",a[i-1]);
                i--;
            }
        }
        if(m==-1)
        {
            break;
        }
    }
	return 0; 
}

