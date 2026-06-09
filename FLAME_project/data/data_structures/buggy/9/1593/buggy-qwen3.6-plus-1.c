#include<stdio.h>
#define MAX 105

typedef struct line{
    int left[2];
    int right[2];
}Line;

Line l[MAX],startline,lastline;
int num[MAX];
int max,flag;
int n;

int succeed()
{
    int x = 0;
    for(int j = 0;j < n;j++)
    {
        if(lastline.right[0] == l[j].left[0]&&lastline.right[1] == l[j].left[1]){
            lastline = l[j];
            num[flag]++; // @@ The count is incremented on the current chain's root (flag), but if this extension leads to a new chain head later, the count logic gets mixed. More critically, this modifies num[flag] in place.
            x = 1;
        }
        if(startline.left[0] == l[j].right[0]&&startline.left[1] == l[j].right[1]){
            startline = l[j];
            num[j] = num[flag]+1; // @@ Error: When extending the start, the new segment j becomes part of the chain. However, simply setting num[j] doesn't account for the fact that the chain rooted at 'flag' has grown. Also, if we switch the 'root' of the chain tracking to j, we lose track of the total length properly if not handled carefully. The main issue is that num[flag] was incremented in the previous if-block for the same j? No, j is same. But wait, if a segment connects to BOTH ends (unlikely per constraints but logically), or if the order matters.
            // The bigger logical error: The problem asks for the longest continuous line. The reference approach uses a union-find or simple linking. This approach tries to grow chains from each node.
            // However, modifying global state `num` and `flag` inside `succeed` which is called in a loop over `i` causes side effects.
            // Specifically, `num[flag]++` increases the count for the original starter `i`.
            // But `num[j] = num[flag] + 1` sets the count for the new starter `j`.
            // If we later iterate to `k` where `l[k]` connects to `l[j]`, `num[j]` might be used.
            // The critical flaw is that `succeed` modifies `num` array elements that might be used as starting points for other chains or have already been processed.
            // Actually, the most direct error causing the wrong answer (4 instead of 3) is likely double counting or incorrect chain propagation.
            // Let's look at the specific failure: Input 5 segments.
            // Segments:
            // 0: (75,78)-(80,67)
            // 1: (7,8)-(9,10)
            // 2: (7,78)-(27,50)
            // 3: (1,2)-(7,8)
            // 4: (27,50)-(75,78)
            
            // Chain: 3 -> 1 (Ends at 9,10). Length 2. Start (1,2).
            // Chain: 2 -> 4 -> 0. Length 3. Start (7,78).
            
            // When i=2 (Segment 2):
            // start=(7,78), last=(27,50). flag=2. num[2]=1.
            // succeed():
            // j=4: last(27,50) == l[4].left(27,50). Match.
            // last becomes l[4]. num[2] becomes 2. x=1.
            // j=0: last(75,78) == l[0].left(75,78). Match.
            // last becomes l[0]. num[2] becomes 3. x=1.
            // Loop continues.
            // Next succeed call:
            // j=4: last(80,67) != l[4].left.
            // j=0: last(80,67) != l[0].left.
            // ... no matches. Returns 0.
            // So num[2] is 3. Correct.
            
            // When i=3 (Segment 3):
            // start=(1,2), last=(7,8). flag=3. num[3]=1.
            // succeed():
            // j=1: last(7,8) == l[1].left(7,8). Match.
            // last becomes l[1]. num[3] becomes 2. x=1.
            // Next succeed call:
            // j=1: last(9,10) != l[1].left.
            // Returns 0.
            // So num[3] is 2. Correct.
            
            // Why output 4?
            // Let's check i=1.
            // start=(7,8), last=(9,10). flag=1. num[1]=1.
            // succeed():
            // Check connections to start (7,8). l[3].right is (7,8).
            // if(startline.left... == l[j].right...)
            // startline is (7,8). l[3].right is (7,8). Match.
            // startline becomes l[3].
            // num[3] = num[1] + 1 = 2. 
            // flag becomes 3.
            // x=1.
            // Note: num[1] is NOT incremented here.
            
            // Now flag is 3. startline is l[3] ((1,2)-(7,8)). lastline is still l[1] ((7,8)-(9,10)).
            // Next succeed() call:
            // Check connections to last (9,10). None.
            // Check connections to start (1,2). None.
            // Returns 0.
            
            // So after i=1 loop:
            // num[3] was updated to 2.
            // But wait, earlier when i=3 ran, num[3] became 2.
            // Is there a case where it becomes larger?
            
            // Let's look at i=4.
            // start=(27,50), last=(75,78). flag=4. num[4]=1.
            // succeed():
            // j=0: last(75,78) == l[0].left. Match.
            // last becomes l[0]. num[4] becomes 2. x=1.
            // j=2: start(27,50) == l[2].right(27,50). Match.
            // start becomes l[2].
            // num[2] = num[4] + 1 = 3.
            // flag becomes 2.
            // x=1.
            
            // Now flag is 2. startline is l[2]. lastline is l[0].
            // Next succeed():
            // Check last (80,67). No match.
            // Check start (7,78). 
            // Does any l[j].right equal (7,78)? No.
            // Wait, l[2] is (7,78)-(27,50). 
            // In the previous step, we set startline = l[2].
            // So startline.left is (7,78).
            // We check if startline.left == l[j].right.
            // Is there a segment ending at (7,78)? No.
            
            // However, notice that num[2] was previously 3 (from i=2 run).
            // Now num[2] is set to 3 again.
            
            // Let's re-read the code logic for `succeed` carefully.
            // The variable `flag` is global.
            // When i=2 runs:
            // flag starts as 2.
            // Extensions happen. num[2] becomes 3.
            
            // When i=4 runs:
            // flag starts as 4.
            // First extension (to right, l[0]): num[4] becomes 2.
            // Second extension (to left, l[2]):
            // num[2] = num[4] + 1 = 3.
            // flag becomes 2.
            
            // So far so good. Max is 3.
            
            // Is there a scenario where it counts 4?
            // Consider if a chain is extended, and `num` accumulates incorrectly.
            
            // Look at i=0.
            // start=(75,78), last=(80,67). flag=0. num[0]=1.
            // succeed():
            // Check start (75,78). l[4].right is (75,78). Match.
            // start becomes l[4].
            // num[4] = num[0] + 1 = 2.
            // flag becomes 4.
            
            // Now flag is 4. startline is l[4]. lastline is l[0].
            // Next succeed():
            // Check last (80,67). No match.
            // Check start (27,50). l[2].right is (27,50). Match.
            // start becomes l[2].
            // num[2] = num[4] + 1 = 3.
            // flag becomes 2.
            
            // Next succeed():
            // Check start (7,78). No match.
            // Check last (80,67). No match.
            // End.
            
            // It seems the logic calculates 3 correctly for the main chain.
            // Why did the user get 4?
            
            // Let's look at the `succeed` function again.
            // It iterates j from 0 to n-1.
            // If multiple segments connect? Constraint: "No three or more segments share a single endpoint."
            // So at most one segment connects to left, one to right.
            
            // However, the loop `for(int j=0...` checks ALL segments.
            // If `lastline` matches `l[j]`, it updates `lastline` and increments `num[flag]`.
            // THEN, it checks if `startline` matches `l[k]` (same j? No, same iteration j).
            // Wait, the `if`s are separate.
            // If `j` matches `lastline`, `lastline` changes.
            // Then the second `if` checks `startline` against the SAME `j`.
            // Can `l[j]` connect to both ends? No, distinct endpoints usually, unless segment is a point (x1<x2 constraint prevents this).
            
            // But what if `j` connects to `lastline`, `lastline` updates.
            // And in a LATER iteration of `j`, say `j2`, `l[j2]` connects to the NEW `lastline`?
            // Yes, that's intended.
            
            // What if `l[j]` connects to `startline`?
            // `startline` updates. `num[j]` is set. `flag` becomes `j`.
            
            // The bug is likely here:
            // `num[j] = num[flag] + 1;`
            // `flag = j;`
            
            // If we extend the start, the "root" of the chain effectively shifts to `j` in terms of tracking variable `flag`, BUT the length of the chain is associated with the whole chain.
            // The code stores the length in `num[flag]`.
            // When we shift flag to j, we store the current total length in `num[j]`.
            
            // However, `num[flag]` (the old flag) was being incremented when we extended the `lastline`.
            // If we extend `startline`, we copy `num[flag] + 1` to `num[j]`.
            
            // Let's trace a potential double count.
            // Suppose we have A-B-C.
            // i=A. flag=A. num[A]=1.
            // Connect B to right of A. num[A]=2. last=B.
            // Connect C to right of B. num[A]=3. last=C.
            
            // Now suppose we start at C.
            // i=C. flag=C. num[C]=1.
            // Connect B to left of C.
            // start=B. num[B] = num[C]+1 = 2. flag=B.
            // Connect A to left of B.
            // start=A. num[A] = num[B]+1 = 3. flag=A.
            
            // This seems symmetric.
            
            // Where does 4 come from?
            // Maybe `num` values persist from previous `i` iterations and are reused incorrectly?
            // Yes! `num` is global and initialized to 1 only once at the beginning?
            // No:
            // `for(int i = 0;i < n;i++) { num[i] = 1; ... }`
            // This resets `num[i]` to 1 at the start of EACH outer loop iteration `i`.
            // WAIT. The initialization `num[i]=1` is inside the `for(i)` loop.
            // So for each `i`, `num[i]` is reset to 1.
            // BUT, `num[k]` for `k != i` is NOT reset.
            
            // Example:
            // i=2 runs. num[2]=1. num[4] becomes 2? No, num[2] increments.
            // If i=2 extends to 4, then 0.
            // num[2] becomes 3.
            // num[4] and num[0] remain whatever they were.
            
            // i=4 runs. num[4]=1. (Reset).
            // Extends to 0. num[4]=2.
            // Extends to 2 (via start).
            // num[2] = num[4] + 1 = 3.
            // flag becomes 2.
            
            // If num[2] was ALREADY 3 from previous iteration, it is overwritten with 3.
            
            // Is it possible that `num[flag]` used in calculation `num[flag]+1` contains stale data from a previous chain build that wasn't cleared?
            // Yes.
            // When `i=4` runs:
            // `num[4]` is reset to 1.
            // `num[0]`, `num[1]`, `num[2]`, `num[3]` retain values from previous iterations.
            
            // Step 1: Extend right to 0.
            // `num[4]` becomes 2.
            
            // Step 2: Extend left to 2.
            // `num[2] = num[4] + 1`.
            // `num[4]` is 2. So `num[2]` becomes 3.
            
            // This looks correct.
            
            // Let's check i=0.
            // num[0]=1.
            // Extend left to 4.
            // start=4. num[4] = num[0]+1 = 2. flag=4.
            // Extend left to 2.
            // start=2. num[2] = num[4]+1 = 3. flag=2.
            
            // It seems consistent.
            
            // However, consider the case where `succeed` finds a connection to `lastline`, increments `num[flag]`.
            // Then finds a connection to `startline` (in same or different j iteration?).
            // The loop is `for j`.
            
            // If `lastline` extends, `num[flag]` increases.
            // If `startline` extends, `num[new_flag]` is set based on `num[old_flag]`.
            
            // The error is likely that `num` entries for nodes that are NOT the current `i` but are part of the chain are modified, and these modifications persist.
            // When a new `i` starts, only `num[i]` is reset.
            // If `i` connects to a node `k` that has a high `num[k]` from a previous run, and we use `num[k]` to calculate something?
            // No, we only read `num[flag]`. `flag` starts as `i`.
            // So we read `num[i]`, which is 1.
            
            // Wait! Look at this block:
            // if(startline.left... == l[j].right...){
            //    startline = l[j];
            //    num[j] = num[flag]+1;
            //    flag = j;
            // }
            
            // If we extend the start, `flag` becomes `j`.
            // In the NEXT iteration of `while(succeed())`, `num[flag]` refers to `num[j]`.
            
            // If we later extend the `lastline`, `num[flag]` (which is `num[j]`) is incremented.
            
            // This implies the chain length is tracked at the current `flag` end.
            
            // Let's trace carefully for a 4-segment chain if it existed.
            // Here max is 3.
            
            // Is it possible `num[2]` becomes 4?
            // Only if `num[flag]` was 3 when we did `num[j] = num[flag]+1`.
            
            // When could `num[flag]` be 3?
            // If `flag` was 2, and `num[2]` was 3.
            
            // Scenario:
            // i=2. num[2]=1.
            // Extend right to 4. num[2]=2.
            // Extend right to 0. num[2]=3.
            // End of i=2.
            
            // i=0. num[0]=1.
            // Extend left to 4.
            // start=4. num[4] = num[0]+1 = 2. flag=4.
            // Extend left to 2.
            // start=2. num[2] = num[4]+1 = 3. flag=2.
            
            // i=4. num[4]=1.
            // Extend right to 0. num[4]=2.
            // Extend left to 2.
            // start=2. num[2] = num[4]+1 = 3. flag=2.
            
            // It seems robustly 3.
            
            // Why WA?
            // Check the output format.
            // `printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]);`
            // `flag` is the index of the segment with the max count.
            // `l[flag].left` is the start of that segment.
            // BUT, if the chain was extended to the LEFT, the true start of the continuous line is `startline.left`, NOT `l[flag].left`.
            // The variable `startline` is global. After the loops, `startline` holds the value from the LAST processed `i`.
            // It does NOT hold the startline for the `flag` segment.
            
            // Ah! The code prints `l[flag].left[0]`.
            // If `flag` is 2, `l[2]` is (7,78)-(27,50). Left is (7,78). Correct.
            // If `flag` was 4 (hypothetically), `l[4]` is (27,50)-(75,78). Left is (27,50).
            // But if the chain starting at 4 extends to 2 and 0, the true start is (7,78).
            // The code does NOT store the start coordinates of the maximal chain globally.
            // It only stores `startline` and `lastline` which are overwritten every `i`.
            
            // So, if the max chain is found at `i=2`, `flag` becomes 2 (or stays 2).
            // But if the max chain is found at `i=4`, `flag` becomes 2 (because we shifted flag to the left extension).
            // And `l[2].left` is (7,78).
            
            // Wait, if `flag` shifts to the left-most segment, then `l[flag].left` IS the start of the chain.
            // Because `startline` becomes `l[j]` when extending left. And `flag` becomes `j`.
            // So `flag` always points to the current left-most segment of the growing chain.
            // Therefore `l[flag].left` should be the correct start coordinate.
            
            // So why 4?
            
            // Let's look at `num` initialization again.
            // `num[i] = 1` is inside the loop.
            
            // Is it possible that `succeed` returns 1 even when no progress is made?
            // `x` is initialized to 0. Set to 1 if match found.
            
            // One subtle bug:
            // In `succeed`, `num[flag]++` happens.
            // If `flag` changes in the same `succeed` call (due to the second `if`), does it affect the first `if`?
            // No, `flag` change is in the second `if`.
            
            // However, if BOTH ifs execute in the same `succeed` call?
            // They iterate `j`.
            // If `j` matches `lastline`, `num[flag]` increments.
            // If `j` ALSO matches `startline`? Impossible for same `j` unless segment is degenerate.
            
            // But what if `j1` matches `lastline`, `num[flag]` increments.
            // Then `j2` matches `startline`, `flag` changes.
            
            // This seems okay.
            
            // The error is likely that `num` values are not reset for ALL nodes, leading to contamination.
            // Although `num[i]` is reset, `num[k]` used in `num[j] = num[flag]+1` is `num[i]` (initially).
            
            // I suspect the error is simpler:
            // The problem states "output the number of segments in this continuous line".
            // The code outputs `max`.
            
            // Let's check the test case again.
            // Expected: 3 7 78.
            // Output: 4 7 78.
            
            // The coordinates are correct. The count is wrong.
            // It counts 4 instead of 3.
            
            // This implies `num[some_index]` reached 4.
            
            // How?
            // If a segment is counted twice?
            
            // In `succeed`:
            // `if(lastline... == l[j]...)`
            // `if(startline... == l[j]...)`
            
            // If `l[j]` is already part of the chain, it shouldn't be added again.
            // The code does NOT check if `l[j]` is already visited.
            // Since "No two line segments intersect in the middle" and "No three... share endpoint", cycles are impossible?
            // Lines are segments. A continuous line is a path.
            // With unique endpoints (degree <= 2), it's a simple path or cycle.
            // But x-coordinates must increase. So it's a DAG/Path.
            // So no cycles.
            
            // However, without a visited check, if the geometry allowed a cycle, it would loop infinitely?
            // `while(succeed() != 0)`
            // If it cycles, `succeed` keeps finding matches.
            // But constraints say x increases. So x1 < x2.
            // Chain: x1 < x2 < x3...
            // Cannot cycle back to smaller x.
            
            // So infinite loop is not the issue.
            
            // Double counting?
            // If `l[j]` connects to `lastline`, it is added.
            // Can `l[j]` be added again in a later `succeed` call?
            // `lastline` has moved past `l[j]`.
            // So `lastline` will not match `l[j]` again.
            
            // So where does 4 come from?
            
            // Maybe `num` array initialization is flawed?
            // `num[i] = 1` inside loop.
            
            // If `i=2` runs. `num[2]=1`.
            // Adds 4. `num[2]=2`.
            // Adds 0. `num[2]=3`.
            
            // If `i=0` runs. `num[0]=1`.
            // Adds 4 (left). `num[4]=2`. `flag=4`.
            // Adds 2 (left). `num[2]=3`. `flag=2`.
            
            // If `i=4` runs. `num[4]=1`.
            // Adds 0 (right). `num[4]=2`.
            // Adds 2 (left). `num[2]=3`. `flag=2`.
            
            // It seems 3 is the max.
            
            // Unless... `num[flag]++` increments the WRONG counter?
            
            // I will mark the line `num[flag]++` and the logic around `num` persistence as suspicious, but the most likely candidate for "Wrong Answer" with correct coords is an off-by-one or double count.
            
            // Actually, look at `num[j] = num[flag] + 1`.
            // If `flag` is `i`, `num[i]` is 1. `num[j]` becomes 2.
            // If we then extend from `j` (new flag), `num[j]` increments.
            
            // There is a known issue in this specific problem solution pattern if `num` is not reset globally or if visited nodes are not tracked.
            // Given the constraints, I'll flag the `num` update logic.
            
            flag = j;
            x = 1;
        }
    }
    return x;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        num[i] = 1;
        scanf("%d%d%d%d",&l[i].left[0],&l[i].left[1],&l[i].right[0],&l[i].right[1]);
    }
    for(int i = 0;i < n;i++)
    {
        startline = l[i];
        lastline = l[i];
        flag = i;
        while(succeed() != 0){
        
        }
    }
    max = num[0];
    for(int i = 0;i < n;i++)
    {
        if(max < num[i]){
            max = num[i];
            flag = i;
        }
    }
    printf("%d %d %d",max,l[flag].left[0],l[flag].left[1]);
    
    return 0;
}