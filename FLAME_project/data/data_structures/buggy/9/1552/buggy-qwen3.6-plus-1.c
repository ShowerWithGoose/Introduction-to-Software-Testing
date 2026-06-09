#include <stdio.h>
struct xianduan{
    int x1;int y1;
    int x2;int y2;
};
struct xianduan line[101]; 
int main()
{
    int n;
    int j;
    int max=0;////最大线段数
    int lianxu[101];
    int xbegin=0,ybegin=0;    
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        lianxu[i]=1;/////该线段及以上连续的线段 
    }
    for(i=0;i<n;i++)
    {
       scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);        
    }

    for(i=1;i<n;i++)
    {
      for(j=i-1;j>=0;j--)
      {                
        if(lianxu[i]==0) continue;
        if((line[i].x1==line[j].x1)&&(line[i].y1==line[j].y1))
        {
            line[i].x1=line[j].x2;
            line[i].y1=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x1==line[j].x2)&&line[i].y1==line[j].y2)
        {
            line[i].x1=line[j].x1;
            line[i].y1=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x2==line[j].x1)&&line[i].y2==line[j].y1)
        {
            line[i].x2=line[j].x2;
            line[i].y2=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }
        else if((line[i].x2==line[j].x2)&&line[i].y2==line[j].y2)
        {
            line[i].x2=line[j].x1;
            line[i].y2=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }                
      }    
    }
    int start=0;    
    for(i=0;i<n;i++)
    {
        if(lianxu[i]>max)
        {
            max=lianxu[i];
            start=i;
        }
    }
    if(line[start].x1<line[start].x2) // @@ The logic for determining the starting point is flawed. When segments are merged, the coordinates in line[start] might not represent the true geometric endpoints of the entire chain correctly, or the comparison assumes x1 is always the left endpoint which might have been swapped during merging logic incorrectly. Specifically, the merging logic updates x1/y1 or x2/y2 to be the "other" end of the connected segment. If we trace the chain 1->2->3, line[2] might have x1 from 1 and x2 from 3. However, if the chain is built such that the "start" of the logical chain is stored in x1, this check works. But let's look at the failure. Input 16. Expected 9 1 1. Got 9 2 2. This implies the max length is correct (9), but the start point is wrong. The start point should be (1,1). The code outputs (2,2). (2,2) is the start of segment 0 (2 2 10 111) ? No, segment 0 is 2 2 10 111. Segment 3 is 1 1 2 2. They connect. The chain likely starts at 1 1. The variable `start` holds the index of the segment that accumulated the count. In the merging process, if segment A merges into B, B's coordinates are updated. If segment 3 (1 1 2 2) merges with segment 0 (2 2 ...), depending on the order, one becomes the container. If `i` iterates 1 to n-1, and `j` goes backwards. If line[3] is processed later than line[0], it might absorb line[0]. If line[3] absorbs line[0], line[3].x1 becomes line[0].x2 (10) or line[0].x1? Let's trace: line[3] is (1,1)-(2,2). line[0] is (2,2)-(10,111). Match: line[3].x2==line[0].x1 && line[3].y2==line[0].y1. Condition 3. line[3].x2 becomes line[0].x2 (10). line[3].y2 becomes line[0].y2 (111). lianxu[3] += lianxu[0]. lianxu[0]=0. So line[3] now represents (1,1)-(10,111). Start point is (1,1). x1 < x2 holds. xbegin = x1 = 1. This seems correct for this pair. Why did it fail? Perhaps a different segment became the "root" of the chain. If the chain grows by attaching to the "end" of the current accumulator, the accumulator's start point remains the original start. However, if a segment is attached to the *start* of the accumulator (Condition 2 or 4 effectively reversing or extending backwards), the start point changes. Condition 2: line[i].x1 == line[j].x2. line[i].x1 becomes line[j].x1. This updates the start point of i to be the start point of j. This is correct propagation. Condition 4: line[i].x2 == line[j].x2. line[i].x2 becomes line[j].x1. This updates the end point. Condition 1: line[i].x1 == line[j].x1. line[i].x1 becomes line[j].x2. This updates the start point of i to be the END of j. This implies j was "before" i? No, if they share start points, one must be reversed? But problem says x1 < x2 for input. And no intersection in middle. If they share an endpoint, they form a continuous line. If line[i] and line[j] share (x1,y1), it means geometrically they meet at that point. Since x1<x2 for both, they diverge from that point? Or one comes in and one goes out? Wait, "continuous line segment... x-coordinates ... increasing". This implies a directed path. If segment A is (1,1)-(2,2) and B is (1,1)-(3,3), they share start. Do they form a continuous line with increasing x? No, they branch. But constraint says "No three or more segments share a single endpoint" and "Only one continuous line segment contains the maximum number". It implies a linear chain. If they share an endpoint, one's end is other's start. Input guarantees x1 < x2. So a segment goes Left to Right. For two segments to connect continuously with increasing x, the End of one (Right) must be the Start of the next (Left). So we only expect connections where End.x == Start.x. Connections like Start==Start or End==End would imply branching or backtracking, which violates the "increasing x" continuous line definition unless the segments are collinear and overlapping? But "No two line segments intersect in the middle". So Start==Start is impossible for a continuous increasing chain unless one segment is degenerate? No. So why does the code check all 4 cases? The problem states: "If two line segments share an endpoint, they can form a continuous line segment." AND "x-coordinates ... increasing". This implies we are looking for a path v1->v2->v3... where x increases. This strictly means End of Seg K connects to Start of Seg K+1. The other connections (Start-Start, End-End, Start-End [reverse]) would not form an increasing X sequence unless we reverse segments, but input fixes x1<x2. So only End-to-Start connections are valid for the chain direction. The code's logic allows merging in any orientation, potentially creating a "chain" that doesn't respect the global X-increasing order or misidentifies the start point because it treats bidirectional connections as valid merges for the same counter. However, the specific error here is likely that `start` index identifies the segment struct that holds the accumulated data, but the coordinates stored in `line[start]` might not correctly reflect the *true* starting point of the entire geometric chain if the merging logic didn't perfectly propagate the "farthest left" point to `x1`. Actually, looking at Condition 1: `line[i].x1` (Start of i) matches `line[j].x1` (Start of j). It sets `line[i].x1 = line[j].x2`. This means the new start of i is the End of j. This implies j is to the LEFT of i? No, if they share starts, they are at the same X. This shouldn't happen in a valid increasing chain. If such a merge happens, it corrupts the geometry. But assuming valid input forms a single line, maybe the issue is simpler. The output is 9 2 2. The expected is 9 1 1. The segment starting at 1 1 is segment 3. The segment starting at 2 2 is segment 0. They are connected. If the final accumulator ended up being segment 0 instead of 3, or if segment 0 absorbed segment 3 incorrectly? If i=0, j loop doesn't run. If i=3, j goes 2,1,0. If j=0 matches, line[3] absorbs line[0]. line[3] start remains 1,1. If later another segment absorbs line[3]? If segment K absorbs line[3] via Condition 2 (K's start matches 3's end), K's start becomes 3's start (1,1). Correct. If segment K absorbs line[3] via Condition 1 (K's start matches 3's start?? No, 3's start is 1,1. If K starts at 1,1, it's a branch). If segment K absorbs line[3] via Condition 4 (K's end matches 3's end)? Branch. If segment K absorbs line[3] via Condition 3 (K's end matches 3's start)? i.e., K ends at 1,1. Then K is to the left. Condition 3 checks `line[i].x2 == line[j].x1`. Here i=K, j=3. `line[K].x2 == line[3].x1`. Match. `line[K].x2` becomes `line[3].x2`. `lianxu[K]` adds `lianxu[3]`. The start of K (`line[K].x1`) is NOT changed. So if K was (0,0)-(1,1), and it absorbs 3 ((1,1)-...), K becomes (0,0)-(...). Start is 0,0. Correct. What if the accumulation happened in the other direction? If 3 absorbs K? i=3, j=K. Condition 2: `line[3].x1 == line[K].x2`. Match. `line[3].x1` becomes `line[K].x1`. Start becomes 0,0. Correct. So the propagation seems logically sound for a linear chain. Why 2 2? This is the start of segment 0. This implies the final `start` index points to a segment where `x1` is 2. This happens if segment 0 was the accumulator and it absorbed segment 3? If i=0, j loop doesn't run. Segment 0 can never absorb anything in this loop structure because `i` starts at 1. Segment 0 can only be absorbed BY others. So `lianxu[0]` should become 0. And `start` should not be 0. Unless `max` was initialized to 0 and `lianxu[0]` remained 1 and no other segment exceeded 1? No, max is 9. So `start` is some index S where `lianxu[S]==9`. And `line[S].x1` is 2. This means the segment at index S thinks its start is 2. This occurs if the chain was built onto a segment that originally started at 2, and the "leftward" propagation didn't update x1? Or if the chain extends to the right only? If the chain is 1->2->3..., and the "base" segment was the one at 2 2? But 1 1 is to the left. The segment at 1 1 (Seg 3) should be the base or absorb the leftward ones. If Seg 3 absorbs Seg 0, Seg 3's start is 1. If Seg 0 absorbs Seg 3? Impossible as i>j. Did Seg 3 get absorbed by someone else who failed to update their start? Suppose Seg X connects to Seg 3's End. Seg X absorbs Seg 3. Seg X's start remains Seg X's start. If Seg X is to the right, its start is > 1. So the start point would be wrong? No, if Seg X is to the right, it connects via its Start to Seg 3's End. Condition 2: `line[X].x1 == line[3].x2`. `line[X].x1` becomes `line[3].x1` (which is 1). So Start propagates left. This works. What if Seg Y connects to Seg 3's Start (1,1)? Seg Y must end at 1,1. Condition 3: `line[Y].x2 == line[3].x1`. `line[Y].x2` becomes `line[3].x2`. `line[Y].x1` is unchanged. If Seg Y is (0,0)-(1,1), start is 0. Correct. Is it possible the chain doesn't include 1 1? No, expected is 1 1. Is it possible the code identified a different chain of length 9? Unlikely. The most probable bug is that `line[start].x1` is not the true start because the merging logic for one of the cases is flawed or the `start` selection picks a segment that didn't fully propagate the start coordinate. Actually, look at Condition 1 again. `line[i].x1 == line[j].x1`. This case corresponds to two segments sharing their START points. As established, this shouldn't happen in a valid simple increasing chain. If it does, the code merges them. `line[i].x1 = line[j].x2`. This effectively jumps `i`'s start to `j`'s end. If `j` is to the right, `i`'s start moves right. This breaks the "start is the leftmost point" invariant. If the input data or intermediate states trigger this invalid merge, the coordinates get corrupted. Given the constraints, such a merge shouldn't happen for the main chain. However, there is a subtle issue: `lianxu[j]=0` marks j as used. But `line[j]` data is still there. If a subsequent segment k tries to connect to j, it might? No, `if(lianxu[i]==0) continue` checks i. It doesn't check j's validity in the inner loop condition explicitly other than j < i. But if j is "dead", should we skip it? The code does NOT skip dead j's. `if(lianxu[i]==0) continue` only skips if the CURRENT accumulator i is dead. It iterates all j < i. If j is dead (lianxu[j]==0), it still compares coordinates. This is fine logically if the coordinates haven't changed, but if j was merged INTO something else, its coordinates might be stale or irrelevant. But more importantly, if j was merged into i, `lianxu[j]` is 0. If another segment k > i merges with i, it's fine. Does a segment k > i try to merge with j? Yes, when i=k, j iterates down. If j is dead, we still check match. If it matches, we merge dead segment j into k? This would double count or corrupt chains. We should skip j if `lianxu[j]==0`.
    
    Let's add the check `if(lianxu[j]==0) continue;` inside the j loop.
    
    Also, the output format requires `xbegin` and `ybegin`. The logic for selecting them based on `x1 < x2` assumes the final segment in the chain has `x1` as the left endpoint. Due to the merging logic, `x1` and `x2` are updated. 
    Case 2 updates `x1`. Case 4 updates `x2`. Case 1 updates `x1`. Case 3 updates `x2`.
    In a valid left-to-right chain, we mostly use Case 2 (extending leftwards backwards? No, i is current, j is previous. If i connects to j's end, i is to the right. `line[i].x1 == line[j].x2`. i's start becomes j's start. Propagates left. Correct.)
    And Case 3 (i connects to j's start? `line[i].x2 == line[j].x1`. i is to the left? No, j is previous. If i is to the left of j, i's end matches j's start. `line[i].x2` becomes `line[j].x2`. Propagates right. `x1` of i remains i's original start. Correct.)
    
    So if the chain is built correctly, `line[start].x1` should be the leftmost point.
    
    The missing `if(lianxu[j]==0) continue` is a strong candidate for logical error causing incorrect merges or corruption.

    Another possibility: The initialization of `max=0`. If all `lianxu` are 1, max becomes 1. `start` becomes the last i where `lianxu[i]>max` (so the last segment). If that segment's start is printed, it might be arbitrary if there are multiple chains of length 1. But here length is 9.

    Let's annotate the missing check for j.
*/
        if(lianxu[i]==0) continue;
        if(lianxu[j]==0) continue; // @@ Missing check to skip segments that have already been merged into others, preventing incorrect re-merging or coordinate corruption.
        if((line[i].x1==line[j].x1)&&(line[i].y1==line[j].y1))
        {
            line[i].x1=line[j].x2;
            line[i].y1=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x1==line[j].x2)&&line[i].y1==line[j].y2)
        {
            line[i].x1=line[j].x1;
            line[i].y1=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x2==line[j].x1)&&line[i].y2==line[j].y1)
        {
            line[i].x2=line[j].x2;
            line[i].y2=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }
        else if((line[i].x2==line[j].x2)&&line[i].y2==line[j].y2)
        {
            line[i].x2=line[j].x1;
            line[i].y2=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }                
      }    
    }
    int start=0;    
    for(i=0;i<n;i++)
    {
        if(lianxu[i]>max)
        {
            max=lianxu[i];
            start=i;
        }
    }
    if(line[start].x1<line[start].x2)
    {
        xbegin=line[start].x1;
        ybegin=line[start].y1;
    }
    else if(line[start].x2<line[start].x1)
    {
        xbegin=line[start].x2;
        ybegin=line[start].y2;        
    }

    printf("%d %d %d",max,xbegin,ybegin);
    return 0;
}