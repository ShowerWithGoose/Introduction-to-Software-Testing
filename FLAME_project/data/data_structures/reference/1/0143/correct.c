#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
int a[10]={1,2,3,4,5,6,7,8,9},b[10],judge[10];
int full(int count,int n);
int main(int argc, const char * argv[])
{
    int n,count=0;
    scanf("%d",&n);
    if(n==1)
    {
    	printf("%d",n);
	}
    else
    {
    	full(count,n);
	}
    return 0;
}

int full(int count,int n)
{
    int i,j;
    if(count==n)
    {
        for(i=0;i<n;i++)
        {
        	printf("%d ",b[i]);
		}
        printf("\n");
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(judge[j]==0)
            {
                b[count]=a[j];
                judge[j]=1;
                full(count+1,n);
                judge[j]=0;
            }
        }
    }
 
}


