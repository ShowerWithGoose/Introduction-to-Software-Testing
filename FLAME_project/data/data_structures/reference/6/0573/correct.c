#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

int z[105];

int main()
{
    int d,i=0;
    while(scanf("%d",&d))
    {
        if(d==1)
        {
            scanf("%d",&d);
            z[i++]=d;
        }
        if(d==0)
        {
            if(i!=0) printf("%d ",z[--i]);
            else printf("error ");
        }
        if(d==-1)
            break;
    }
    return 0;
}



