#include<stdio.h>
int main()
{
    int i,j,x1[100],y1[100],x2[100],y2[100],t,n[100]={0},x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    int l; // @@ In C89/C90, declaring variables after executable statements causes a compilation error. Additionally, the subsequent chaining logic is fundamentally flawed.
    for(i=0;i<t-1;i++) // @@ The loop bound `t-1` incorrectly excludes the last segment from being considered as a potential starting point.
    {
        l=0;
        x=x2[i],y=y2[i];
        for(j=i+1;l<=t;j++,l++) // @@ The chaining logic using modulo arithmetic and a step counter is incorrect and fails to properly traverse connected segments in arbitrary input order.
        {
            if(x==x1[j%t]&&y==y1[j%t])
            {
                x=x2[j%t];
                y=y2[j%t];
                n[i]++;
                l=0;
            }
        }
    }
    int m,max=n[0]; // @@ In C89/C90, initializing a variable with a non-constant expression causes a compilation error. `m` is also uninitialized, leading to undefined behavior if `max` is never updated.
    for(i=0;i<t;i++)
    {
        if(max<n[i])
        {
            max=n[i];
            m=i;
        }
    }
    printf("%d %d %d",max+1,x1[m],y1[m]); // @@ Uses potentially uninitialized `m`, which can cause undefined behavior or incorrect output.
}