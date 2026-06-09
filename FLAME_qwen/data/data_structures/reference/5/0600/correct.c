#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct number{
    int xs;
    int zs;
};
void bubbleSort(struct number ans[],int n)
{
    int i,j,flag;
    struct number hold;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(ans[j].zs<ans[j+1].zs)
            {
                hold=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=hold;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    int i=0,j,k=0,m,n;
    struct number a[1005],b[1005],ans[1005];
    while(1)
    {
        scanf("%d%d",&a[i].xs,&a[i].zs);
        i++;
        char c=getchar();
        if(c=='\n')
            break;
    }
    m=i;i=0;
    while(1)
    {
        scanf("%d%d",&b[i].xs,&b[i].zs);
        i++;
        char c=getchar();
        if(c=='\n')
            break;
    }
    n=i;i=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            ans[k].xs=a[i].xs*b[j].xs;
            ans[k].zs=a[i].zs+b[j].zs;
            k++;
        }
    }
    bubbleSort(ans,k);
    for(i=0;i<k-1;i++)
    {
        if(ans[i].zs==ans[i+1].zs)
        {
            ans[i+1].xs+=ans[i].xs;
            ans[i].xs=0;ans[i].zs=0;
        }
    }
    bubbleSort(ans,k);
    for(i=0;i<k;i++)
    {
        if(ans[i].xs!=0)
            printf("%d %d ",ans[i].xs,ans[i].zs);
    }
}

