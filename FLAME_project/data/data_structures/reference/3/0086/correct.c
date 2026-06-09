#include <stdio.h>
#include <stdlib.h>

int main()
{
    char e;
    int a[100],i,p=-1;
    for(i=0;(e=getchar())!='\n';a[i]=e-'0',i++)
    if(e=='.')
    p=i;
    a[p]=0;
    int y,x;
    for(y=0;a[y]==0;y++);
    if(y<p)
    {
        printf("%d.",a[0]);
        for(x=1;x<i;x++)
            if(x!=p)printf("%d",a[x]);
        printf("e%d",p-y-1);
    }
    if(y>p)
    {
        printf("%d",a[y]);
        for(x=y+1;x<i;x++)
            {
                if(x==y+1)printf(".");
                if(x!=p)printf("%d",a[x]);

            }
        printf("e%d",p-y);
    }


    return 0;
}


