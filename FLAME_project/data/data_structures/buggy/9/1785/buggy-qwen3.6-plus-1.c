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
        for(j=i+1;l<=t;j++,l++) // @@ The loop condition `l<=t` combined with `j++` and `l=0` reset logic can lead to an infinite loop or out-of-bounds access if a chain is not found quickly, but more critically, `j` is not bounded by `t`. If the chain breaks, `j` keeps incrementing indefinitely because `l` resets only on match, but here `l` increments every step. Wait, `l` increments every step `j++, l++`. If no match, `l` increases. If `l > t`, loop stops. However, `j` is used as index `j%t`. The real issue is that `n[i]` counts connections, but the logic for finding the *longest* continuous segment starting at `i` is flawed because it doesn't handle branching or non-linear structures correctly according to the problem's "continuous line" definition which implies a simple path. But the specific Runtime Error usually comes from array bounds. Here `j` can grow very large if `l` takes time to reach `t`, but `j%t` keeps it in bounds. The actual runtime error in many such student submissions is often an infinite loop if the logic is slightly off. Let's look closer. If `x!=x1[j%t] || y!=y1[j%t]`, `l` increments. If it never matches, `l` reaches `t+1` and loop ends. This seems safe from infinite loop. However, the problem states "No three or more segments share a single endpoint". The logic `n[i]++` counts how many segments are chained after `i`. The max search `max=n[0]` assumes `n` is populated. If `t=1`, the outer loop `i<t-1` doesn't run, `n[0]=0`. `max=0`. Output `1 x1[0] y1[0]`. Correct. For `t=2`, `i=0`. `x=x2[0], y=y2[0]`. `j=1, l=0`. Check `j%2=1`. If match, `n[0]++`, `l=0`, `j=2`. Next iter `l=1`. `j%2=0`. Check match with seg 0? Unlikely to form cycle as per x1<x2. If no match, `l=1`. Next `j=3, l=2`. `l<=t` (2<=2) true. `j%2=1`. Check again. This logic searches for a chain but allows revisiting segments via `%t`, which violates the "continuous line" simple path constraint and can cause infinite loops if a cycle exists (though problem says x1<x2 so cycles are impossible geometrically, but logically `j` grows). The primary suspect for Runtime Error in competitive programming contexts with this code structure is often an infinite loop if the termination condition isn't met due to logic errors, or accessing uninitialized memory. Here, `m` is used in `printf` but might be uninitialized if `t=0` (not possible per constraints) or if the max loop doesn't run. If `t>=1`, max loop runs. `m` is initialized only if `max<n[i]`. If `n[0]` is max, `m` remains uninitialized. @@ Variable 'm' is used uninitialized if the first element n[0] remains the maximum, leading to undefined behavior/runtime error when accessing x1[m] and y1[m].
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