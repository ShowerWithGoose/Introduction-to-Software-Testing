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
    for(i=0;i<t-1;i++) // @@ Error: Loop should go to i<t to include all segments as potential chain starts. Missing last segment index.
    {
        l=0;
        x=x2[i],y=y2[i];
        for(j=i+1;l<=t;j++,l++) // @@ Error: Using modulus and resetting l leads to infinite looping and incorrect chain building. Should correctly scan for next segment.
        {
            if(x==x1[j%t]&&y==y1[j%t]) // @@ Error: Modulo indexing may revisit segments and does not guarantee increasing x order. Chain logic is flawed.
            {
                x=x2[j%t];
                y=y2[j%t];
                n[i]++;
                l=0; // @@ Error: Resetting l prevents loop termination, can cause infinite loop if matches continue.
            }
        }
    }
    int m,max=n[0]; // @@ Error: m is not initialized; if all n[i] equal to n[0], m remains garbage.
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