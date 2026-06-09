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
        for(j=i+1;l<=t;j++,l++) // @@ [Infinite loop risk and incorrect loop condition: 'l<=t' allows more iterations than segments, and 'j%t' causes wrap-around which violates problem constraints that only adjacent segments in increasing x-order can connect. Also, j may exceed array bounds when t is small.]
        {
            if(x==x1[j%t]&&y==y1[j%t]) // @@ [Using modulo 'j%t' incorrectly assumes circular connection; problem states segments form a continuous line only if endpoints match in forward direction without wrap-around. This can access uninitialized or unrelated segments.]
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
    printf("%d %d %d",max+1,x1[m],y1[m]);
}