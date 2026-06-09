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
        for(j=i+1;l<=t;j++,l++) // @@ The loop condition `l<=t` combined with `j++` and `l++` creates a logic error. `l` is reset to 0 inside the if block, but `j` keeps incrementing. If segments are not contiguous in the array index, `j` can exceed bounds or wrap around incorrectly using `%t`. More critically, if no match is found, `l` increments until it exceeds `t`, but `j` also increments. If `t` is small, `j%t` might access valid indices but the logic for chaining is flawed because it assumes sorted order or specific adjacency which isn't guaranteed by input order. However, the primary Runtime Error cause here is likely accessing out-of-bounds memory if `j` grows large while `l` resets, or infinite loop potential if logic doesn't terminate correctly for disjoint sets. Actually, looking closely: `j` increases indefinitely. `j%t` prevents out-of-bounds access on arrays, BUT `l` counts consecutive failures? No, `l` resets on success. If we have a chain, `l` resets. If we don't, `l` increments. The loop stops when `l > t`. This implies it looks ahead up to `t` steps. However, `j` is not bounded by `t`, only `j%t` is used for indexing. This means it scans the array multiple times. The issue is that `n[i]` counts the number of *additional* segments connected. 
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
    printf("%d %d %d",max+1,x1[m],y1[m]);
}