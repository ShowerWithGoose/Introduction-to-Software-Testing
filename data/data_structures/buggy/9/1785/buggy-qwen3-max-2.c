#include<stdio.h>
int main()
{
    int i,j,x1[100],y1[100],x2[100],y2[100],t,n[100]={0},x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    int l;
    for(i=0;i<t-1;i++)
    {
        l=0;
        x=x2[i],y=y2[i];
        for(j=i+1;l<=t;j++,l++) @@ // The loop condition `l<=t` can cause infinite looping or out-of-bound access because `l` is reset to 0 inside the loop when a match is found, and `j` keeps increasing without bound modulo `t`. Also, using `j%t` assumes circular traversal which is not valid per problem constraints.
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
    int m,max=n[0];
    for(i=0;i<t;i++)
    {
        if(max<n[i])
        {
            max=n[i];
            m=i;
        }
    }
    printf("%d %d %d",max+1,x1[m],y1[m]); @@ // If all `n[i]` are zero (e.g., no connections), `m` remains uninitialized, leading to undefined behavior when accessing `x1[m]` and `y1[m]`.
}