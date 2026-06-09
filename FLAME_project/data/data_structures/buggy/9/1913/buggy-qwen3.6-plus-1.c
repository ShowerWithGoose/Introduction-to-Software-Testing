#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}coordinate;
coordinate coor[105];
void digui(int *len,coordinate mem,int n){
    for(int j=0;j<n;j++){
        if(mem.x2==coor[j].x1&&mem.y2==coor[j].y1){
            (*len)++;
            mem=coor[j];
            digui(len,mem,n); // @@ The recursive call does not stop after finding a match. Since no three segments share an endpoint, there is at most one next segment. However, the loop continues to check other segments which might incorrectly increment length if logic was flawed, but more importantly, this implementation allows revisiting segments or forming cycles if not careful, though the main issue is that it doesn't mark visited segments. In this specific problem, since it's a line, we just need to follow the chain. The real error is that `digui` explores ALL possible next segments from the current `mem`. If the structure was a tree it would branch. Here it is a line. But wait, if segment A connects to B, and B connects to C. When processing A, it finds B, increments len, updates mem to B, calls digui. Inside that call, it finds C, increments len, updates mem to C, calls digui. That seems correct for a single path. 
            // However, consider if there are multiple segments starting with the same point? Constraint 2 says "No three or more segments share a single endpoint". This implies a node degree <= 2. So it's a set of paths/cycles. 
            // The issue with the provided buggy output being 11 vs expected 7 suggests it is counting segments multiple times or traversing incorrectly.
            // Actually, look at the loop: `for(int j=0;j<n;j++)`. It checks EVERY segment. If segment 1 connects to segment 2, it recurses. But after returning from recursion, the loop in the parent call continues. If there was another segment connecting to the ORIGINAL `mem` (which is passed by value, so `mem` in the parent hasn't changed? No, `mem=coor[j]` updates local `mem`). 
            // Wait, `mem` is passed by value. So `mem=coor[j]` only affects the current stack frame's `mem`. The recursion uses the NEW `mem`. This part is okay for following a chain.
            // BUT, it does not prevent re-visiting segments. If there was a cycle, it would loop infinitely (stack overflow). The problem says "continuous line segment", implying acyclic paths usually, but even if not, without a `visited` array, it can count segments multiple times if the graph isn't a simple path or if backtracking occurs.
            // More critically, if segment A connects to B, and we start at A. We find B. Recurse on B. Inside B, we look for connections. If B connects to A (reverse), and we don't check visited, we might go back? No, because B's end is C, A's start is A. B's end != A's start usually unless cycle.
            // Let's look at the constraints again. "No two line segments intersect in the middle". "No three or more segments share a single endpoint".
            // The main logical error in many such student solutions is failing to mark segments as used. If segment 1->2->3. Start at 1. Find 2. Recurse. Find 3. Recurse. End. Count=3. Correct.
            // What if we start at 2? Find 3. Recurse. End. Count=2. Then loop continues. Does it find 1? No, because it checks `mem.x2 == coor[j].x1`. 2's end is 3's start. 2's end is NOT 1's start. So it only goes forward.
            // So why is the answer wrong?
            // Ah, look at the input. 
            // 10 111 70 165 (Seg A)
            // 70 165 140 120 (Seg B)
            // 140 120 195 205 (Seg C)
            // 195 205 300 300 (Seg D)
            // 300 300 400 400 (Seg E)
            // 400 400 600 600 (Seg F)
            // 600 600 721 2   (Seg G)
            // This is a chain of 7 segments.
            // Why did it output 11?
            // Maybe it's counting backwards too? No, the condition is strictly `mem.x2 == coor[j].x1`.
            // Is it possible that `digui` is called multiple times for the same chain from different starting points in the main loop, and `max` is updated correctly? Yes.
            // Let's re-read the code carefully.
            // `digui` iterates `j` from 0 to `n-1`.
            // If `mem` matches `coor[j]`, it increments len, updates `mem`, and recurses.
            // Crucially, after the recursive call returns, the loop `for(int j=0;j<n;j++)` CONTINUES.
            // If there is another segment `k` that ALSO starts at the original `mem`'s end? Constraint 2 says max 2 segments share an endpoint. One is the current one (`mem`), so only one other can start there? No, `mem` ends there. Another segment can start there. Can TWO segments start there? No, "No three or more segments share a single endpoint". So at most one segment starts at `mem`'s end. So the loop will find at most one match.
            // So branching isn't the issue.
            // Is it possible it visits the SAME segment twice?
            // If we have A->B. Start A. Find B. Recurse B. Loop in B finds nothing. Return. Loop in A continues. Does it find B again? Yes! `j` continues. If `B` is at index `k`, and we haven't marked it visited, and the loop continues past `k`? No, `j` increases. It won't revisit `B` if `B` was at `k` and `j` is now `k+1`.
            // Wait, if `B` is at index 5. We find it. Recurse. Return. `j` becomes 6. We don't check 5 again. So we don't double count B in the same chain traversal.
            // So where does 11 come from?
            // Maybe the chain is longer? Or maybe it connects to something else?
            // Let's check the other segments.
            // 80 75 125 75
            // 1 1 2 2
            // 60 40 80 55
            // 80 55 90 20
            // 90 20 125 60
            // 22 35 43 43
            // 43 43 60 40
            // 22 175 80 205
            // Chain 2: 
            // 22 35 43 43 (H)
            // 43 43 60 40 (I)
            // 60 40 80 55 (J)
            // 80 55 90 20 (K)
            // 90 20 125 60 (L)
            // This is a chain of 5.
            // Are they connected?
            // L ends at 125 60.
            // Seg "80 75 125 75" ends at 125 75. No.
            // Seg "1 1 2 2". No.
            // Seg "22 175 80 205". No.
            // So max chain is 7.
            // Why 11?
            // 7 + 5 = 12? No.
            // Maybe the code counts the starting segment itself? `count` starts at 1. `digui` increments.
            // Chain of 7 segments: Start count=1. Find next (1st link), count=2. Recurse. Find next (2nd link), count=3... Find 6th link, count=7. Correct.
            // Is it possible that `digui` is not resetting state properly?
            // The variable `count` is passed by pointer. `*len` is incremented.
            // In `main`, `count` is reset to 1 for each `i`.
            // There is a subtle bug: `digui` does not stop searching after finding a match. It finds a match, recurses, and then CONTINUES the loop. If there was a second match (which shouldn't happen due to constraints), it would add it. But what if the recursion modifies global state? No, `coor` is global but read-only. `len` is modified.
            // Wait! If the chain branches? No, constraints.
            // What if the segment connects to ITSELF? No, x1 < x2.
            // Let's look at `mem=coor[j]`. This updates the local `mem`.
            // If the loop finds a match at `j=5`, it sets `mem` to `coor[5]`, calls `digui`.
            // When `digui` returns, `mem` in the CURRENT frame is still `coor[5]`.
            // The loop continues to `j=6`.
            // If there is another segment at `j=6` that ALSO starts at `coor[5].x2`? Impossible by constraint.
            // HOWEVER, what if the segment at `j=5` connects to `j=6`, and `j=6` connects to `j=7`...
            // The logic seems sound for a simple path.
            // Is it possible that `digui` visits segments that were already visited in a DIFFERENT branch? No, it's a depth first search on a path.
            // Let's reconsider the "Wrong Answer".
            // Output 11. Expected 7.
            // 11 is suspiciously close to 7 + 4? Or maybe it's counting all segments in two chains?
            // No, `max` tracks the best single chain.
            // Could it be that `digui` is finding connections that go BACKWARDS?
            // Condition: `mem.x2 == coor[j].x1`. Only forward.
            // Is it possible that `coor` contains duplicate segments? No.
            // Let's look at the `digui` signature: `void digui(int *len,coordinate mem,int n)`.
            // `mem` is passed by value.
            // Inside: `mem=coor[j]`.
            // This effectively moves the "head" of the search to the next segment.
            // The error is likely that `digui` does not prevent re-using segments that are part of the current chain if the graph had cycles, but here it's lines.
            // Actually, there is a known issue with this specific recursive approach if not handled carefully: it doesn't mark visited nodes. If the input data accidentally formed a cycle (violating constraints? or maybe I missed a connection), it would crash or loop. But assuming valid input...
            // Wait, look at this segment: `22 175 80 205`.
            // And `80 75 125 75`.
            // And `1 1 2 2`.
            // None connect to the main chains.
            // Why 11?
            // Maybe the code is counting the number of ENDPOINTS? No, `len` starts at 1 (segment) and increments per segment found.
            // Let's look at the Reference Program provided in the prompt description (not the source code to fix). The reference program uses a DP-like approach `count[i]`.
            // The source code to fix uses recursion.
            // The error is almost certainly that `digui` continues to search for OTHER matches after returning from recursion, and if the data had a "Y" shape (one start, two ends), it would sum them up. But constraints say max degree 2.
            // However, if a segment connects to TWO different segments sequentially? No, a segment has one end.
            // Is it possible that `mem` is not updated correctly for the subsequent iterations of the loop?
            // If `j=5` matches. `mem` becomes `coor[5]`. Recurse.
            // Return. `mem` is STILL `coor[5]`.
            // Loop continues to `j=6`.
            // If `coor[6]` ALSO matches `mem` (which is `coor[5]`)?
            // This implies `coor[5].x2 == coor[6].x1` AND `coor[5].y2 == coor[6].y1`.
            // This means TWO segments start at the end of segment 5.
            // Constraint: "No three or more segments share a single endpoint".
            // Segment 5 ends at P. Segment 6 starts at P.
            // Segment 5 itself shares P.
            // So we have Segment 5 (end) and Segment 6 (start). That's 2 segments sharing P.
            // Is there a third? If Segment 7 also started at P, that would be 3. Forbidden.
            // So there can be AT MOST one segment starting at P (other than the one ending there? No, the one ending there is `mem`).
            // So there is at most ONE `j` that satisfies the condition.
            // So the loop will find at most one match.
            // So why is it wrong?
            // Ah! What if the chain loops back to a previously visited node?
            // Example: A->B->C->A.
            // Start A. Find B. Recurse B. Find C. Recurse C. Find A. Recurse A. Find B... Stack Overflow.
            // But the output is 11, not crash.
            // Maybe the input HAS a cycle?
            // If there is a cycle, and it doesn't crash (maybe small cycle?), it might count weirdly.
            // But the expected output is 7.
            // The only logical explanation for getting a higher count like 11 in a path-finding algorithm without visited checks is that it's traversing multiple branches or re-counting.
            // Given the constraints, the most likely bug in student code like this is simply that it doesn't stop after finding the unique next segment, OR it doesn't handle the fact that `digui` explores the entire reachable component, and if the component is not a simple path (e.g. two paths merging? No, degree <=2), it fails.
            // Actually, if the graph consists of disjoint paths, and we start at one end, we traverse the whole path.
            // If we start in the MIDDLE, we only traverse forward.
            // The code iterates `i` from 0 to n. It tries starting at EVERY segment.
            // `max` takes the maximum.
            // Starting at the beginning of the longest chain (Seg 10 111...) should yield 7.
            // Starting at Seg 22 35... should yield 5.
            // Why 11?
            // 7 + 5 = 12? Close to 11.
            // Did it connect the two chains?
            // Chain 1 End: 721 2.
            // Chain 2 Start: 22 35. No.
            // Chain 2 End: 125 60.
            // Chain 1 Start: 10 111. No.
            // Is there a segment connecting them?
            // `22 175 80 205`.
            // `80 75 125 75`.
            // `1 1 2 2`.
            // None seem to bridge.
            // Wait, look at `digui` again.
            // `void digui(int *len,coordinate mem,int n)`
            // It passes `mem` by value.
            // It modifies `*len`.
            // If I start at Segment A. It finds B. `len` becomes 2. Recurses on B.
            // Inside B, it finds C. `len` becomes 3. Recurses on C.
            // ...
            // This seems correct for counting length.
            // UNLESS... `digui` is called, finds a match, recurses, returns, and then the loop finds ANOTHER match?
            // We established this is impossible due to constraints.
            // IS IT POSSIBLE that `coor` array has garbage data?
            // `coordinate coor[105];` Global. Initialized to 0.
            // Input `n=15`.
            // Indices 0..14 filled.
            // Loop `j` goes 0..14.
            // Seems fine.
            // Let's look at the `compare` function in the REFERENCE program. The source code to fix DOES NOT SORT.
            // The reference program sorts. The buggy program does not.
            // Does sorting matter? No, `digui` searches all `j`.
            // However, if the program is slow, it might TLE? No, WA.
            // There is one subtle possibility: Integer overflow? No.
            // Pointer aliasing? No.
            // Let's assume the error is that `digui` needs to mark visited segments to avoid counting them if they appear in multiple "paths" during the recursion? No, it's a single path traversal.
            // Actually, I suspect the test case might have a property where `digui` counts incorrectly due to not stopping.
            // Add a `break` or `return` after recursion?
            // If we find the next segment, we recurse. After recursion, we should STOP looking for other segments starting at `mem`, because there can be only one.
            // Adding `break;` or `return;` would optimize it, but wouldn't change correctness unless there's a bug.
            // Wait! If I don't break, and there ISN'T another segment, it just finishes the loop.
            // What if `mem` matches `coor[j]` where `j` is the SAME segment?
            // `mem.x2 == coor[j].x1`.
            // If a segment starts where it ends? x1 < x2, so x1 != x2. So a segment cannot connect to itself.
            // I will flag the recursive call as the potential location because it lacks a mechanism to prevent re-visiting or to stop after the unique match is found, which is bad practice and potentially erroneous if constraints were slightly different or if I'm misinterpreting "share an endpoint".
            // Actually, looking at similar problems online, the common error is not using a `visited` array. Even if constraints say "no 3 segments share an endpoint", if there is a cycle A->B->A, `digui` will infinite recurse. If the stack doesn't overflow immediately, it might behave erratically. But 15 segments is small.
            // However, if the output is 11, and max chain is 7, and another is 5.
            // 11 = 7 + 4?
            // Maybe it's counting the segments in the longest path PLUS some others?
            // I'll mark the recursive call.
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&coor[i].x1,&coor[i].y1,&coor[i].x2,&coor[i].y2);
    }
    int max=1;
    coordinate result;
    for(int i=0;i<n;i++){
        int count=1;
        digui(&count,coor[i],n);
        if(count>max){
            max=count;
            result=coor[i];
        }
    }
    printf("%d %d %d\n",max,result.x1,result.y1);
    return 0;
}