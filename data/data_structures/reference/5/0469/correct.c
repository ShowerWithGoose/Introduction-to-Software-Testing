#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct first
{
    int xi;
    int mi;
}a[1000000];
struct second
{
    int xi;
    int mi;
}b[1000000];
struct sum
{
    int xi;
    int mi;
}c[1000000];
int cmp(const void *a,const void *b)
{
    struct sum n1=*(struct sum *)a;
    struct sum n2=*(struct sum *)b;
    if(n1.mi<n2.mi)
        return 1;
    if(n1.mi>n2.mi)
        return -1;
}
int main()
{
    char d;
    int i=1,j=1,k=1,m;
    int len1,len2;
    int flag=0;
    while(1)
    {
        scanf("%d%d",&a[i].xi,&a[i].mi);
        i++;
        scanf("%c",&d);
        if(d=='\n')break;
    }
    len1=i-1;
    while(1)
    {
        scanf("%d%d",&b[j].xi,&b[j].mi);
        j++;
        scanf("%c",&d);
        if(d=='\n')break;
    }
    len2=j-1;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            flag=0;
            c[k].xi=a[i].xi*b[j].xi;
            c[k].mi=a[i].mi+b[j].mi;
            for(m=1;m<k;m++)
            {
                if(c[k].mi==c[m].mi)
                {
                    c[m].xi+=c[k].xi;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                k++;
            }
        }
    }
    qsort(c+1,k-1,sizeof(c[0]),cmp);
    for(i=1;i<=k-1;i++)
    {
        printf("%d %d ",c[i].xi,c[i].mi);
    }
    return 0;
}

