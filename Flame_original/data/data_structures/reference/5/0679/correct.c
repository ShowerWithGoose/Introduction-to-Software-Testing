#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lena=0,lenb=0,n=0;
char c;

struct ans0
{
    int xs;
    int zs;
};
struct ans0 ans[105],a[105],b[105];

int main()
{
    for(int i=0;i<25&&c!='\n';i++)
    {
        scanf("%d%d",&a[i].xs,&a[i].zs);
        lena++;
        c=getchar();
    }
    while(scanf("%d",&b[lenb].xs)!=EOF)
    {
        scanf("%d",&b[lenb].zs);
        lenb++;
    }
    for(int i=0;i<lena;i++)
        for(int j=0;j<lenb;j++,n++)
        {
            ans[n].xs=a[i].xs*b[j].xs;
            ans[n].zs=a[i].zs+b[j].zs;
        }

    struct ans0 tempr;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(ans[j].zs<ans[j+1].zs)
            {
                tempr=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=tempr;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i].zs==ans[i+1].zs)
        {
            ans[i].xs+=ans[i+1].xs;
            ans[i+1].xs=0;
            if(ans[i].zs==ans[i+2].zs)
            {
                ans[i].xs+=ans[i+2].xs;
                ans[i+2].xs=0;
                i++;
            }
            i++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i].xs!=0)
            printf("%d %d ",ans[i].xs,ans[i].zs);
    }
    return 0;
}
