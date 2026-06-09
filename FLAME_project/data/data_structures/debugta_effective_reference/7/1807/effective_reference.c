#include<stdio.h>
#include<string.h>
int n;
int head=1;
struct cao
{
    int l,r,v;
}cu[1000];
void find(int a,int vv,int n)
{
    if(vv>=cu[a].v)
    {
        if(cu[a].r==0)
        {
            cu[a].r=n;
            return;
        }
        else find(cu[a].r,vv,n);
    }
    else
    {
        if(cu[a].l==0)
        {
            cu[a].l=n;
            return;
        }
        else find(cu[a].l,vv,n);
    }
}

void An(int a,int c)
{
    int bj=0;
    if(cu[a].l!=0){bj=1;An(cu[a].l,c+1);}
    if(cu[a].r!=0){bj=1;An(cu[a].r,c+1);}
    if(bj==0)
    {
        printf("%d %d\n",cu[a].v,c);
    }
}

int main()
{
    memset(cu,0,sizeof(cu[0]));
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        cu[head].v=a;
        if(head!=1)
        {
            find(1,a,head);
        }
        head++;
    }
    An(1,1);
    return 0;
}
