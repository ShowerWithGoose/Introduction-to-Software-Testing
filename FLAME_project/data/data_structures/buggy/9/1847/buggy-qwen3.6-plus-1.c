#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Lines{
    int a1;
    int b1;
    int a2;
    int b2;
}line[100];

int main(int argc, char *argv[]) 
{
    int n,i,j;
    int flag=1;
    int cnt[100];
    
    int minx,miny;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&(line[i].a1),&(line[i].b1),&(line[i].a2),&(line[i].b2));
        cnt[i]=1;
    }
    
    for(i=0;i<n;i++) // @@ The logic for merging segments is flawed. It iterates through all pairs repeatedly without ensuring a consistent direction or preventing double counting/incorrect merges in a single pass. Specifically, modifying line[i] and line[j] simultaneously while iterating can lead to inconsistent states. More importantly, the condition `if((line[i].a1==line[j].a2)&&(line[i].b1==line[j].b2))` checks if i starts where j ends, but then it merges j into i's start and i into j's end. This bidirectional update `line[j].a2=line[i].a2; line[j].b2=line[i].b2;` and `line[i].a1=line[j].a1; line[i].b1=line[j].b1;` is problematic because `line[i]` and `line[j]` are being modified based on each other's current values which might have just changed or will change, leading to incorrect coordinates. Also, `cnt[i]++` and `cnt[j]++` increments both, effectively double counting the merge event for the chain length if not handled carefully (though here it seems to try to count segments per endpoint, but the propagation is wrong). The primary issue is that this simple pairwise check doesn't correctly build the longest chain because it doesn't propagate the "head" and "tail" of the entire connected component correctly across multiple segments in one go, or it does so in an order-dependent way that fails for complex chains. For example, if A->B->C, processing A and B merges them. Then processing B and C might fail if B's coordinates were overwritten incorrectly or if the link isn't found due to previous modifications. The reference solution uses a sorted approach and merges backwards, which is more stable. This brute force pairwise update is unreliable.
    {
        for(j=0;j<n;j++)
        {
            if(j==i) continue;
            if((line[i].a1==line[j].a2)&&(line[i].b1==line[j].b2))
            {
                line[i].a1=line[j].a1;
                line[i].b1=line[j].b1;
                line[j].a2=line[i].a2; // @@ Updating line[j]'s end to line[i]'s end uses the OLD line[i].a2/line[i].b2 if line[i] hasn't been updated yet in this specific merge step, BUT line[i].a1/b1 were just updated. This creates a mismatch. More critically, if line[j] was already part of a longer chain, its 'a1' might be the true start, but we are overwriting line[i]'s start with it. However, line[j]'s end is being set to line[i]'s end. If line[i] was also part of a chain, its 'a2' might not be its original end. This logic assumes single segment links only or fails to propagate chain ends correctly.
                line[j].b2=line[i].b2;
                cnt[i]++;
                cnt[j]++;
            }
            if((line[i].a2==line[j].a1)&&(line[i].b2==line[j].b1))
            {
                line[i].a2=line[j].a2;
                line[i].b2=line[j].b2;
                line[j].a1=line[i].a1;
                line[j].b1=line[i].b1;
                cnt[i]++;
                cnt[j]++;
            }
             
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(cnt[i]>flag)
        {
            flag=cnt[i];
            minx=line[i].a1;
            miny=line[i].b1;
        }
    }
    printf("%d %d %d\n",flag,minx,miny);
    return 0;
}