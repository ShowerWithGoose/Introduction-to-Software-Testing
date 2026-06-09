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
    int m,max=n[0]; // @@ [max is used uninitialized if t == 0, but more critically, if all n[i] are 0 and t > 0, max starts at n[0]=0 which is okay, but the real issue is that m is uninitialized if no n[i] exceeds max (e.g., when all counts are equal). However, the main logical error is in the chaining logic.]
    for(i=0;i<t;i++)
    {
        if(max<n[i])
        {
            max=n[i];
            m=i;
        }
    }
    printf("%d %d %d",max+1,x1[m],y1[m]); // @@ [If t == 0, this accesses x1[m] with uninitialized m. Also, the chaining algorithm is flawed: it uses modulo indexing (j%t) which causes circular traversal, violating the problem's requirement of strictly increasing x-coordinates and non-circular chains. Additionally, the inner loop condition "l<=t" may cause infinite or incorrect iterations because l is reset to 0 inside the loop, potentially leading to more than t iterations without termination guarantee. The algorithm fails to correctly model the chain as a DAG and doesn't handle arbitrary connection orders.]
}