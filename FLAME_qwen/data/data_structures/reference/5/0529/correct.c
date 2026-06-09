#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct xiang
{
    int xi;
    int ci;
};
struct xiang a[200],b[200],c[200],temp;
int main()
{
    int i,j,k,len1,len2;
    char ch;
    for(len1=1;;len1++)
    {
        scanf("%d%d",&a[len1-1].xi,&a[len1-1].ci);
        if(getchar()=='\n')
        {
            break;
        }
    }
    for(len2=1;;len2++)
    {
        scanf("%d%d",&b[len2-1].xi,&b[len2-1].ci);
        if(getchar()=='\n')
        {
            break;
        }
    }
    for(i=0,k=0;i<len1;i++)
        for(j=0;j<len2;j++,k++)
    {
        c[k].xi=a[i].xi*b[j].xi;
        c[k].ci=a[i].ci+b[j].ci;
    }
    for(i=0;i<k;i++)
        for(j=i+1;j<k;j++)
    {
        if(c[i].ci<c[j].ci)
        {
            temp=c[j];
            c[j]=c[i];
            c[i]=temp;
        }
        else if(c[i].ci==c[j].ci)
        {
            c[i].xi=c[i].xi+c[j].xi;
            c[j].xi=0;c[j].ci=0;
        }
    }
    for(i=0;c[i].xi!=0;i++)
    {
        printf("%d %d ",c[i].xi,c[i].ci);
    }
return 0;
}

