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
        for(j=i+1;l<=t;j++,l++)
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
    int m,max=n[0]; // @@ [max is used uninitialized if t == 0; also, if all n[i] are negative (though unlikely), logic fails. But more critically, when t==1, the loop for(i=0;i<t-1;i++) doesn't run, so n[0] remains 0, which is correct, but max=n[0] is okay only if t>=1. However, the real issue is in the chaining logic: it uses modulo indexing (j%t) which causes incorrect segment matching by wrapping around the array, violating the problem's assumption that segments form a linear chain without cycles. Also, the inner loop condition 'l<=t' may cause infinite or excessive iterations because l is reset to 0 inside, potentially leading to more than t iterations and accessing out-of-bound indices indirectly via modulo. This breaks the requirement of forming continuous line segments only by shared endpoints without arbitrary wrapping.]
    for(i=0;i<t;i++)
    {
        if(max<n[i])
        {
            max=n[i];
            m=i;
        }
    }
    printf("%d %d %d",max+1,x1[m],y1[m]); // @@ [If t == 0, this accesses x1[m] and y1[m] with uninitialized m, causing undefined behavior. Also, if no segments are connected (all n[i]==0), it still works, but the core error is the incorrect chaining due to circular modulo indexing which doesn't model the actual segment adjacency correctly.]
}