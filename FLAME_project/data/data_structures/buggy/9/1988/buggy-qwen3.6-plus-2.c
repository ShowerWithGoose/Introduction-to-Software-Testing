#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct line{
    int xstart;
    int ystart;
    int xend;
    int yend;
    int n;
};

struct line lines[110];
int MaxI, MaxN, num;

int find(int x1, int y1, int x2, int y2){
    int flag = -1;
    for(int i=0; i<num; i++){
        if(x2 == lines[i].xstart && y2 == lines[i].ystart){
            if(flag == -1){
                lines[i].xstart = x1;
                lines[i].ystart = y1;
                lines[i].n++;
                if(lines[i].n > MaxN){
                    MaxN = lines[i].n;
                    MaxI = i;
                }
            }else{
                lines[i].xstart = lines[flag].xstart;
                lines[i].ystart = lines[flag].ystart;
                lines[i].n += lines[flag].n;
                if(lines[i].n > MaxN){
                    MaxN = lines[i].n;
                    MaxI = i;
                }
            }
            return 1;
        }else if(x1 == lines[i].xend && y1 == lines[i].yend){
            lines[i].xend = x2;
            lines[i].yend = y2;
            lines[i].n++;
            if(lines[i].n > MaxN){
                MaxN = lines[i].n;
                MaxI = i;
            }
            flag = i;
        }
    }
    if(flag == -1){
        return 0;
    }
    return 1;
}
int cmp(const void*p1, const void*p2){
    struct line *d1 = (struct line *)p1;
    struct line *d2 = (struct line *)p2;
    if(d1->xstart < d2->xstart){
        return -1;
    }else{
        return 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2;
    for(int i=0; i<n; i++){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(!find(x1, y1, x2, y2)){      // 没找到重合的端点
            lines[num].xstart = x1;
            lines[num].ystart = y1;
            lines[num].xend = x2;
            lines[num].yend = y2;
            lines[num].n = 1;
            if(lines[num].n > MaxN){
                MaxN = lines[num].n;
                MaxI = num;
            }
            num++;
        }
        qsort(lines, num, sizeof(struct line), cmp); // @@ The sorting inside the loop is inefficient and potentially problematic because `find` relies on iterating through existing segments. More critically, the logic in `find` is flawed. It attempts to merge segments but fails to correctly handle chain merging when a new segment connects two existing separate chains or extends a chain that was previously merged. Specifically, when `flag != -1` in the first `if` block, it merges the current segment into `lines[i]` using data from `lines[flag]`, but `lines[flag]` might not be the head of its chain if previous merges happened incorrectly or if `flag` refers to a segment that was logically part of a different chain structure not fully consolidated. However, the primary logical error causing the wrong answer for the specific test case is likely in how `find` handles the connection. Let's look closer. The problem states x1 < x2 for input. The continuous line must have increasing x. 
        // The `find` function tries to attach the new segment (x1,y1)-(x2,y2) to existing lines.
        // Case 1: New segment's end (x2,y2) matches an existing line's start. It prepends the new segment's start to that line.
        // Case 2: New segment's start (x1,y1) matches an existing line's end. It appends the new segment's end to that line.
        // The variable `flag` records if Case 2 happened. If Case 1 happens later in the loop (or vice versa? No, the loop order matters), it tries to merge.
        // Actually, the logic `if(x2 == ...)` checks if the new segment connects to the START of an existing segment.
        // The logic `else if(x1 == ...)` checks if the new segment connects to the END of an existing segment.
        // If both happen (i.e., the new segment bridges two existing segments), `flag` will be set by the `else if` branch. Then if the `if` branch is entered for another segment (or the same one? No, distinct endpoints), it merges.
        // However, the constraint "No three or more segments share a single endpoint" simplifies things.
        // The main issue is that `qsort` is called every iteration, which changes the indices. The `find` function iterates using indices `0` to `num-1`. If `qsort` reorders the array, the logical consistency of `lines[i]` representing a specific chain might be maintained structurally, but the `MaxI` index stored globally might become invalid if the element at `MaxI` moves. 
        // Wait, `MaxI` is updated inside `find` when `MaxN` is updated. So `MaxI` should point to the correct element *at that moment*. But after `qsort`, the element at `MaxI` might have moved. The final loop `for(int i=0; i<num; i++)` searches for `MaxN` again to reset `MaxI`, so that part is okay.
        // Let's trace the failure. Input: 15 segments. Expected: 7 segments starting at 10 111.
        // Chain: (10,111)-(70,165) -> (70,165)-(140,120) -> (140,120)-(195,205) -> (195,205)-(300,300) -> (300,300)-(400,400) -> (400,400)-(600,600) -> (600,600)-(721,2).
        // This chain has 7 segments.
        // The bug is likely in `find`. When a new segment connects to an existing line, it modifies that line. If it connects to the *start* of an existing line, it updates the start. If it connects to the *end*, it updates the end.
        // Consider the segment (70,165)-(140,120).
        // Suppose (10,111)-(70,165) is already in `lines` as L1.
        // Suppose (140,120)-(195,205) is already in `lines` as L2.
        // When processing (70,165)-(140,120):
        // 1. Check L1: x2(140) != L1.xstart(10). x1(70) == L1.xend(70) && y1(165) == L1.yend(165). Match!
        //    Update L1: xend=140, yend=120, n=2. Flag=idx(L1).
        // 2. Check L2: x2(140) == L2.xstart(140) && y2(120) == L2.ystart(120). Match!
        //    Since flag != -1, we enter the merge block.
        //    L2.xstart = L1.xstart (10). L2.ystart = L1.ystart (111).
        //    L2.n += L1.n (2 + 2 = 4? No, L1.n was 1 initially, then became 2. L2.n was 1. So L2.n becomes 1+2=3? Wait. L1 represents 2 segments now? No, L1 was just updated to include the current segment. So L1.n is 2. L2.n is 1. Result L2.n = 3. This is correct: (10,111)-(70,165), (70,165)-(140,120), (140,120)-(195,205).
        //    But what happens to L1? L1 is still in the array with n=2. It hasn't been marked as deleted or merged into L2 completely (its count wasn't zeroed, though its coordinates were used). The code doesn't remove L1. This leads to duplicate counting or incorrect state if L1 is processed again.
        //    Crucially, `lines[i]` in the `if` block is L2. `lines[flag]` is L1.
        //    L2 absorbs L1. But L1 remains in the `lines` array with `n=2` and modified coordinates? No, L1's coordinates were NOT modified in the `if` block, only L2's were. L1 still has `xstart=10, ystart=111, xend=140, yend=120, n=2`.
        //    Later, if another segment connects to L1's old end (now L2's middle?), it might cause issues. Or simply, L1 is a "ghost" segment with an inflated count that isn't part of the main chain anymore but still exists in the array.
        //    When `qsort` runs, L1 and L2 are both present. L1 has n=2, L2 has n=3.
        //    Eventually, the max count might be calculated incorrectly because the "true" chain is in L2, but L1 is cluttering the space.
        //    However, the bigger issue is that when L2 absorbs L1, L1 should effectively be removed or invalidated. The code does NOT invalidate L1.
        //    In the next iterations, if a segment connects to L1's endpoints, it might extend L1 separately, creating a divergent or incorrect chain.
        //    To fix this, when merging, the absorbed segment (`lines[flag]`) should be marked as invalid (e.g., n=0) or removed. The current code just leaves it there.
    }
    for(int i=0; i<num; i++){
        if(lines[i].n == MaxN){
            MaxI = i;
            break;
        }
    }
    printf("%d %d %d", MaxN, lines[MaxI].xstart, lines[MaxI].ystart);
    return 0;
}