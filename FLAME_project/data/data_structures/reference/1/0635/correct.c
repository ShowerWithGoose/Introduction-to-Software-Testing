#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int a[11],b[121],n;
void define(int s)
{
    int i;
    if (s==n+1)
    	{
        	for(i=1;i<=n;i++)
        		{
           			printf("%d ", a[i]);
        		}
        	printf("\n");
        	return;
    	}
    for(i=1;i<=n;i++)
    	{
        	if (b[i]==0)
       			{
            		b[i]=1;
					a[s]=i;  
            		define(s+1);  
           			b[i]=0; 
        		}
    	}
    return;
}

int main()
{
    scanf("%d",&n);
    define(1);
    return 0;
}

