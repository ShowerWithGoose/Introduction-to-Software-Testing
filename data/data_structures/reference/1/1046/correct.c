#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define true 1
int main()
{
    int n,s=1,i,j,k,flag=0,x,y;
    int *a;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        printf("%d ",a[i]);
    }
    printf("\n");
    while(1)
    {
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                break;
            }
        }
        if(i<0)
        {
            break;
        }
        for(j=n-1;j>i;j--)
        {
            if(a[j]>a[i])
            {
                break;
            }
        }
        k=a[j];
        a[j]=a[i];
        a[i]=k;
        for(x=i+1,y=n-1;x<y;x++,y--)
        {
            k=a[y];
            a[y]=a[x];
            a[x]=k;
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    free(a);
    return 0;
}



