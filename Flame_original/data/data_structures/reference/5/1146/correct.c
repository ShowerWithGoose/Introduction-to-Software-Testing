#include<stdio.h>
#include<string.h>
struct node{
    int a;
    int n;
    int tag;
}ans[10000],temp;
int x[10000][2],y[10000][2];
int i,j,k,lx,ly,a,n,k;
char c;

int main()
{
    i=0;
    do{
        scanf("%d %d%c",&a,&n,&c);
        x[i][0]=a;
        x[i][1]=n;
        i++;
    }while(c==' ');
    lx=i;
    j=0;
    do{
        scanf("%d %d%c",&a,&n,&c);
        y[j][0]=a;
        y[j][1]=n;
        j++;
    }while(c==' ');
    ly=j;

    k=0;
    for(i=0;i<lx;i++)
    {
        for(j=0;j<ly;j++)
        {
            ans[k].a=x[i][0]*y[j][0];
            ans[k].n=x[i][1]+y[j][1];
            ans[k].tag=0;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<k-1;j++)
        {
            if(ans[j].n<ans[j+1].n)
            {
                temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }

    for(j=0;j<k;j++)
    {
        if(ans[j].n==ans[j+1].n)
        {
            ans[j+1].a+=ans[j].a;
            ans[j].tag=1;
        }
    }
    for(i=0;i<=k-1;i++)
        if(ans[i].tag==0)
        printf("%d %d ",ans[i].a,ans[i].n);
    if(ans[k].a!=0)
    printf("%d %d",ans[k].a,ans[k].n);
    return 0;

}

