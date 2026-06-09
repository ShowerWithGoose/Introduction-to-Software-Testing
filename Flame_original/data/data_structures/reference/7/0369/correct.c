#include<stdio.h>
#include<string.h>
int n;
int bh=1;
struct cao
{
    int l,r,v;
}a[1000];
void find(int x,int vv,int y)
{
    if(vv>=a[x].v)
    {
        if(a[x].r==0)
        {
            a[x].r=y;
            return;
        }
        else find(a[x].r,vv,y);
    }
    else
    {
        if(a[x].l==0)
        {
            a[x].l=y;
            return;
        }
        else find(a[x].l,vv,y);
    }
}

void An(int x,int c)
{
    int bj=0;
    if(a[x].l!=0){bj=1;An(a[x].l,c+1);}
    if(a[x].r!=0){bj=1;An(a[x].r,c+1);}
    if(bj==0)
    {
        printf("%d %d\n",a[x].v,c);
    }
}

int main()
{
    memset(a,0,sizeof(a[0]));
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        a[bh].v=x;
        if(bh!=1)
        {
            find(1,x,bh);
        }
        bh++;
    }
    An(1,1);
    return 0;
}
