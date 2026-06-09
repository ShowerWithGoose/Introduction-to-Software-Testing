#include<stdio.h>
int main()
{
    int i,j,x1[100],y1[100],x2[100],y2[100],t,n[100]={0},x,y;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    int l; // @@ Variable declaration after executable statements violates C89/C90 standard, causing a compilation error.
    for(i=0;i<t-1;i++) // @@ The loop condition i<t-1 incorrectly skips the last segment as a potential starting point, leading to logical errors if the longest chain starts there.
    {
        l=0;
        x=x2[i],y=y2[i];
        for(j=i+1;l<=t;j++,l++)
        {
            if(x==x1[j%t]&&y==y1[j%t]) // @@ Using j%t allows wrapping around and may incorrectly match segments or cause inefficient searches without a visited array.
            {
                x=x2[j%t];
                y=y2[j%t];
                n[i]++;
                l=0;
            }
        }
    }
    int m,max=n[0]; // @@ Variable declaration after executable statements violates C89/C90 standard (compilation error). Also, m is uninitialized if max is never updated.
    for(i=0;i<t;i++)
    {
        if(max<n[i])
        {
            max=n[i];
            m=i;
        }
    }
    printf("%d %d %d",max+1,x1[m],y1[m]); // @@ If m remains uninitialized, accessing x1[m] and y1[m] leads to undefined behavior.
}