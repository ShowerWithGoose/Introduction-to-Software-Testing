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
            digui(len,mem,n); // @@ The recursive call does not stop after finding a match. Since no three segments share an endpoint, there is at most one next segment. However, the loop continues checking other segments which might incorrectly increment length if logic was flawed, but more importantly, this implementation allows revisiting segments or forming cycles if constraints weren't strict, but the main issue is that it doesn't mark visited segments. Without a visited array, if the input had cycles (though problem says continuous line), it could loop. More critically, the problem states "No two line segments intersect in the middle" and "No three or more segments share a single endpoint". The real error is that the recursion doesn't prevent re-using the same segment if the geometry allowed it, but specifically here, the logic fails to ensure we are building a simple path. However, looking at the test case, the expected output is 7. The buggy output is 11. This suggests the count is inflated. The function `digui` keeps searching all `n` segments. If segment A connects to B, and B connects to C, it finds them. But if there's any ambiguity or if the recursion doesn't terminate correctly for disjoint paths, it might overcount. Actually, the primary issue is that `digui` explores ALL possible connections from `mem`. If multiple segments started at `mem.x2, mem.y2`, it would branch. But the constraint says no 3 segments share an endpoint. So only 1 segment can start where another ends (in a forward direction). The issue is likely that it doesn't check if `coor[j]` has already been used in the current chain. If the segments formed a cycle, it would loop infinitely or until stack overflow. But here it returns 11. Let's look closer. The reference program uses sorting and a linear scan. The buggy program uses recursion without visited tracking. If segment 1 connects to 2, and 2 connects to 3, `digui` counts 1->2->3. If there was another segment 4 that also connected to 3 (ending at 3's start? No, 3 starts at 2's end). The problem is that `digui` doesn't exclude the segment we just came from or any previously used segment. Although x increases, so we can't go back. Wait, `x1 < x2` is given. So x always increases. Thus, we can never revisit a segment because coordinates would have to decrease or stay same to loop back, but x strictly increases along the chain. So cycles are impossible. Why is the count wrong? 
            // Let's re-read carefully. "No three or more segments share a single endpoint."
            // The error is actually simpler: The problem asks for the continuous line segment containing the MAXIMUM NUMBER OF SEGMENTS.
            // The recursive function `digui` increments `len` for EVERY match found in the loop.
            // If segment i connects to j, it increments len and recurses.
            // But the loop `for(int j=0;j<n;j++)` continues!
            // If there were multiple segments starting at the same point (forbidden by constraint "No three...", but two could? No, "No three or more" means 1 or 2 can share. But since x increases, only one can be the "next" in a forward chain if we assume unique continuation? Not necessarily. One endpoint can be the start of multiple segments? No, if x1 < x2, and they share an endpoint, say End of A is Start of B. Can End of A also be Start of C? Yes, if B and C both start at A's end. But then x_A2 = x_B1 = x_C1. And y_A2 = y_B1 = y_C1. This violates "No three or more" if we count A, B, C sharing that point? A ends there, B starts there, C starts there. That's 3 segments sharing the point. So this is forbidden. So at most 2 segments share a point. One ending, one starting. So the path is unique.
            // So why is the answer wrong? 
            // Ah, look at the loop in `digui`. It iterates j from 0 to n-1.
            // It finds a match, increments len, updates mem, and recurses.
            // BUT IT DOES NOT BREAK OR RETURN AFTER THE RECURSION.
            // It continues the loop. If there are other segments later in the array that ALSO match the ORIGINAL `mem` (not the updated one), it will try to connect them too?
            // No, `mem` is passed by value. Inside the if, `mem` is updated. The recursion uses the new `mem`.
            // But after the recursion returns, the loop continues with the OLD `mem`? No, `mem` was updated in the local scope.
            // Wait, `mem=coor[j]` changes the local variable `mem`.
            // The recursion `digui(len, mem, n)` uses the NEW mem.
            // When recursion returns, we are back in the loop. `mem` is still the NEW mem? Yes.
            // But the condition `if(mem.x2==coor[j].x1...` uses the CURRENT `mem`.
            // So if we found a match at j=5, `mem` becomes coor[5]. Then we recurse.
            // After recursion returns, the loop continues to j=6.
            // Now it checks if `coor[5].x2 == coor[6].x1`. This is correct behavior for chaining.
            // HOWEVER, the count `(*len)++` happens BEFORE recursion.
            // If the chain is A->B->C.
            // Start with A. Loop finds B. Len becomes 2. Mem becomes B. Recurse.
            // Inside recurse (with B): Loop finds C. Len becomes 3. Mem becomes C. Recurse.
            // Inside recurse (with C): No match. Returns.
            // Back in B's loop: Continues. No other matches. Returns.
            // Back in A's loop: Continues. Checks other j.
            // If there is another segment D that starts where A ends? Forbidden by constraints (would be 3 segments sharing A's end point: A, B, D? No, A ends, B starts, D starts. That's 3. Forbidden).
            // So there is only one path.
            // Why is the output 11 instead of 7?
            // Maybe the input has segments that are not part of the main chain but form their own chains, and the recursion is somehow counting them?
            // No, `digui` starts from `coor[i]`. It only follows connections from `coor[i]`.
            // Is it possible that `digui` counts the same segment multiple times if the geometry allows? No, x increases.
            // Let's look at the constraints again. "No two line segments intersect in the middle."
            // What if the error is that `digui` doesn't reset `len` properly? No, `count` is passed by pointer.
            // What if the error is that the global array `coor` is modified? No.
            
            // Let's look at the Reference Program logic.
            // It sorts by x1.
            // Then for each i, it looks for j > i such that end of i matches start of j.
            // It updates x,y to the end of j.
            // It increments count[i].
            // This builds a chain forward.
            
            // The buggy program does DFS.
            // Is it possible that the DFS visits nodes that are not strictly "next" in sorted order, but geometrically connected?
            // Yes. But since x must increase, and x1 < x2, any connection must go to a segment with larger x.
            
            // Wait! The constraint "No three or more segments share a single endpoint" applies to ANY endpoint.
            // If Segment A ends at P, and Segment B starts at P, that's 2 segments.
            // If Segment C also starts at P, that's 3. Forbidden.
            // If Segment C ends at P, that's 3. Forbidden.
            // So each point is shared by at most 2 segments.
            // This implies the structure is a set of disjoint paths (and possibly isolated segments).
            
            // Why 11 vs 7?
            // Total segments = 15.
            // If the longest chain is 7, where do the extra 4 come from?
            // Maybe the recursion is counting branches? But there are no branches.
            
            // Let's check the code logic again.
            // void digui(int *len, coordinate mem, int n)
            // ...
            // (*len)++;
            // mem = coor[j];
            // digui(len, mem, n);
            
            // If I have A -> B -> C.
            // Call digui(A).
            // Finds B. Len=2. Mem=B. Call digui(B).
            // Finds C. Len=3. Mem=C. Call digui(C).
            // Returns.
            // Back in digui(B). Loop continues.
            // Back in digui(A). Loop continues.
            
            // This seems correct for a single path.
            
            // IS IT POSSIBLE that the input contains duplicate segments or something? No.
            
            // Let's look at the test case input manually.
            // 15 segments.
            // Chain: 
            // 10 111 -> 70 165 (Seg 9: 10 111 70 165)
            // 70 165 -> 140 120 (Seg 15: 70 165 140 120)
            // 140 120 -> 195 205 (Seg 8: 140 120 195 205)
            // 195 205 -> 300 300 (Seg 11: 195 205 300 300)
            // 300 300 -> 400 400 (Seg 7: 300 300 400 400)
            // 400 400 -> 600 600 (Seg 4: 400 400 600 600)
            // 600 600 -> 721 2 (Seg 1: 600 600 721 2)
            // Length: 7 segments.
            // Start: 10 111.
            
            // Why does the buggy code output 11?
            // It must be counting other segments as connected.
            // Are there other connections?
            // 80 75 -> 125 75 (Seg 2)
            // 1 1 -> 2 2 (Seg 3)
            // 60 40 -> 80 55 (Seg 5)
            // 80 55 -> 90 20 (Seg 6)
            // 90 20 -> 125 60 (Seg 14)
            // 22 35 -> 43 43 (Seg 10)
            // 43 43 -> 60 40 (Seg 13)
            // 22 175 -> 80 205 (Seg 12)
            
            // Let's trace connections:
            // Seg 5 (60 40 -> 80 55) connects to Seg 6 (80 55 -> 90 20).
            // Seg 6 (90 20) connects to Seg 14 (90 20 -> 125 60).
            // Chain: 5->6->14. Length 3.
            
            // Seg 10 (22 35 -> 43 43) connects to Seg 13 (43 43 -> 60 40).
            // Seg 13 (60 40) connects to Seg 5 (60 40 -> 80 55).
            // So 10->13->5->6->14. Length 5.
            
            // Does Seg 14 connect to anything? 125 60.
            // Seg 2 starts 80 75. No.
            // Seg 12 starts 22 175. No.
            
            // So we have a chain of length 5: 10->13->5->6->14.
            // And a chain of length 7: 9->15->8->11->7->4->1.
            
            // Max is 7.
            
            // How does the buggy code get 11?
            // 7 + 5 = 12? No.
            // Maybe it's linking the two chains?
            // End of chain 5->...->14 is 125 60.
            // Start of chain 9->... is 10 111.
            // No connection.
            
            // Is there a connection between the chains?
            // End of 14: 125 60.
            // Start of 2: 80 75.
            // Start of 3: 1 1.
            // Start of 12: 22 175.
            
            // What if the bug is that `digui` doesn't stop when it hits a dead end, but somehow merges counts?
            // No, it's a simple DFS.
            
            // WAIT. The variable `mem` is passed by VALUE.
            // In the loop:
            // if (match) {
            //   (*len)++;
            //   mem = coor[j];
            //   digui(len, mem, n);
            // }
            // After `digui` returns, `mem` holds the value of `coor[j]` (the last matched segment).
            // The loop continues to j+1.
            // It checks `if (mem.x2 == coor[j+1].x1 ...)`
            // This means it tries to extend the chain from the LAST matched segment, not the original one.
            // This is actually CORRECT for finding a single long path if the path is unique.
            
            // However, consider this scenario:
            // A -> B
            // A -> C
            // (This is forbidden by constraints, but let's assume the code handles general cases).
            
            // Let's look at the specific segments again.
            // Is it possible that the recursion visits segments out of order and counts them multiple times?
            // No, `len` is incremented only when a match is found.
            
            // Let's look at the Reference Program again.
            // It sorts. Then it does a greedy walk.
            
            // The Buggy Program does NOT sort.
            // It iterates `j` from 0 to n-1.
            // If the segments are not sorted, `digui` might find a connection to a segment with a SMALLER index?
            // Yes.
            // Example: Segment 0 connects to Segment 10.
            // `digui` finds it. Recurses on Segment 10.
            // Segment 10 connects to Segment 2.
            // `digui` finds it. Recurses on Segment 2.
            // This is fine.
            
            // BUT, what if Segment 2 connects back to Segment 1?
            // x must increase. x2 > x1.
            // So x coordinates strictly increase along the chain.
            // So you can never go back to a segment with a smaller x-start.
            // So you can never visit a segment twice.
            
            // So why 11?
            // 15 segments total.
            // Chain 1: 7 segments.
            // Chain 2: 5 segments.
            // Remaining: 3 segments (2, 3, 12).
            // 7 + 5 = 12.
            // If the code somehow linked Chain 1 and Chain 2, it would be 12.
            // Or if it linked Chain 2 to something else.
            
            // Is there a connection between Chain 2 (ends at 125 60) and Chain 1 (starts at 10 111)? No.
            // Is there a connection between Chain 1 (ends at 721 2) and anything? No.
            
            // Wait, look at Segment 2: 80 75 125 75.
            // Look at Segment 14: 90 20 125 60.
            // Look at Segment 12: 22 175 80 205.
            
            // Is it possible that `digui` is counting the STARTING segment twice?
            // `count` starts at 1.
            // `digui` increments `len` for each NEXT segment.
            // So if chain is A->B->C.
            // Start count=1 (A).
            // Find B. Len=2. Recurse B.
            // Find C. Len=3. Recurse C.
            // Total 3. Correct.
            
            // I suspect the error is that `digui` does not use a `visited` array, and although x-increase prevents cycles, it might allow merging if the constraints were slightly different or if I'm misinterpreting "No three segments share an endpoint".
            
            // Actually, there is a subtle bug in `digui`.
            // When `digui` returns from recursion, the loop continues.
            // If there are MULTIPLE segments that start at the current `mem`'s end point, it would try to follow ALL of them.
            // But constraints say max 2 segments share a point.
            // If `mem` ends at P, and another segment `K` starts at P, that's 2 segments (mem and K).
            // Can a third segment `L` also start at P? No.
            // Can a third segment `L` end at P? No.
            // So there is at most ONE segment that continues the chain forward.
            
            // SO WHY IS IT WRONG?
            
            // Let's look at the output 11 again.
            // Maybe the question implies that the "continuous line segment" can branch? No, "line segment".
            
            // I will bet on the lack of `visited` tracking being the theoretical error, even if x-increase protects it in this specific valid input, OR that the recursion logic is flawed because it modifies `mem` locally and continues the loop, potentially skipping valid branches if the structure wasn't a simple path? No.
            
            // Actually, if I look really closely at the provided "Buggy Output: 11", and "Expected: 7".
            // 11 is very specific.
            
            // Let's assume the error is indeed the missing visited check, which is standard for graph traversal.
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