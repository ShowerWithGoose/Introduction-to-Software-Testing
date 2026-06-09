#include <stdio.h>
#include <stdlib.h>
struct math
{
int a;
int x;
};
int main()
{
    int n,i=0,j=0,m,k,h=0,flag;
    struct math p[100],q[100],res[100],u;
    do{
       scanf("%d%d",&p[i].a,&p[i].x);i++;
       }while(getchar()!='\n');
    j=0;
    do{
       scanf("%d%d",&q[j].a,&q[j].x);j++;
       }while(getchar()!='\n');
    for(m=0;m<i;m++)
    {
        for(k=0;k<j;k++)
        {
            res[h].a=p[m].a*q[k].a;
            res[h].x=p[m].x+q[k].x;
            h++;
        }
    }
    m=h;k=-1;
    for(i=0;i<h;i++)
    {
        for(j=0;j<h;j++)
        {
            if(res[i].x==res[j].x&&i!=j)
            {
                res[i].a=res[i].a+res[j].a;
                res[j].x=k;
                k--;m--;
            }
        }
    }
    for(i=0;i<h;i++)
    {
        flag=0;
        for(j=0;j<h-1-i;j++)
        {
            if(res[j].x<res[j+1].x)
                {
                u=res[j];
                res[j]=res[j+1];
                res[j+1]=u;
                flag=1;
                }
        }
        if(flag==0)break;
    }
    for(i=0;i<m-1;i++)
        printf("%d %d ",res[i].a,res[i].x);
    printf("%d %d\n",res[i].a,res[i].x);

    return 0;
}

