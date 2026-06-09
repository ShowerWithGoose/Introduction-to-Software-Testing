#include <stdio.h>

typedef struct {
    int v1x;
    int v1y;
    int v2x;
    int v2y;
} line;

int main() {
    int n, num = 1, max = 1, m = 0;
    scanf("%d", &n);
    line s[n];
    int a[n];
    line r;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &s[i].v1x, &s[i].v1y, &s[i].v2x, &s[i].v2y);
    }
    for (int i = 0; i < n; i++) {
        r = s[i]; // @@ The logic fails to track visited segments, leading to infinite loops or incorrect counts if segments form cycles or if the greedy local search doesn't find the global longest path correctly. More critically, it resets j=0 which can cause re-counting of segments already part of the current chain if not handled with a visited array. However, the primary logical error for "Wrong Answer" on this specific case is likely that the simple greedy extension from each start node doesn't guarantee finding the longest chain if the graph isn't a simple linked list from that node, but given constraint 3 (no 3+ segments share endpoint), it's a set of disjoint paths/cycles. The real issue is usually that `a[i]` stores the length starting from `i`, but the loop structure `j=0` restarts scanning from beginning. If segment A connects to B, and B connects to C. Starting at A: finds B (num=2, r=B, j=0). Scans from 0. Finds A? No (A.v2 != B.v1). Finds B? No. Finds C? Yes (B.v2 == C.v1). Num=3. Correct. 
        // Let's look at the failure: Input 5 segments. 
        // 1: (75,78)-(80,67)
        // 2: (7,8)-(9,10)
        // 3: (7,78)-(27,50)
        // 4: (1,2)-(7,8)
        // 5: (27,50)-(75,78)
        // Sorted by v1x implicitly? No, the buggy code does NOT sort.
        // The reference program sorts. The buggy program does not sort.
        // The problem asks for the continuous line segment. The order of input is arbitrary.
        // Without sorting or building a proper graph, iterating `i` from 0 to n-1 and trying to extend greedily might work IF we assume the input forms simple chains and we just follow pointers.
        // However, the crucial missing step is that the segments are not sorted, so the "start" of the global longest chain might not be identified correctly if we just pick `s[m]` based on max length found from `s[i]`.
        // Actually, if we calculate the length of the chain starting at each segment `i`, `max` will hold the correct length. `m` will hold the index of the segment that *starts* that chain.
        // Does the greedy walk work?
        // Start i=0: (75,78)-(80,67). Next? None. Len=1.
        // Start i=1: (7,8)-(9,10). Next? None. Len=1.
        // Start i=2: (7,78)-(27,50). Next? s[4] is (27,50)-(75,78). Match. Num=2. r=s[4]. j=0.
        //   Scan j=0..4. s[0] is (75,78)-(80,67). Match s[4].v2(75,78) with s[0].v1(75,78). Num=3. r=s[0]. j=0.
        //   Scan j=0..4. No match for s[0].v2(80,67). Len=3.
        // Start i=3: (1,2)-(7,8). Next? s[1] is (7,8)-(9,10). Match. Num=2. r=s[1]. j=0.
        //   Scan j=0..4. No match for s[1].v2(9,10). Len=2.
        // Start i=4: (27,50)-(75,78). Next? s[0]. Match. Num=2. r=s[0]. Len=2.
        // Max len is 3. Index m is 2. s[2] is (7,78)-(27,50).
        // Output: 3 7 78.
        // Wait, the buggy output was "2 7 78". Why?
        // Let's re-read the buggy code carefully.
        // `line s[n]` is a VLA. `int a[n]` is a VLA.
        // The logic seems theoretically correct for disjoint chains.
        // Is there an initialization issue? `num=1` outside loop. Inside loop `num=1` reset.
        // Ah, look at `j = 0` inside the if.
        // If `s[j]` is the same as `r`'s predecessor? No, `r` updates.
        // What if `s[j]` is a segment already used in the current chain?
        // The code does not mark segments as visited.
        // In the trace above:
        // i=2. r=s[2].
        // j=4. Match. num=2. r=s[4]. j=0.
        // j=0. Match. num=3. r=s[0]. j=0.
        // j=0..4 no match.
        // a[2]=3.
        // i=4. r=s[4].
        // j=0. Match. num=2. r=s[0]. j=0.
        // a[4]=2.
        // So max should be 3.
        // Why did it output 2?
        // Maybe the input order matters for the `scanf`? No.
        // Maybe `line s[n]` declaration order?
        // Let's look at constraints. "No three or more segments share a single endpoint."
        // "Only one continuous line segment contains the maximum number of segments."
        
        // Potential Error: The variable `num` is not reset to 1 at the beginning of the outer loop in some interpretations? No, it is `num=1` at end of loop.
        // Wait, `int num = 1` is initialized once.
        // Loop i=0: num starts at 1. Ends with num=1. Reset to 1.
        // Loop i=1: num starts at 1. Ends with num=1. Reset to 1.
        // Loop i=2: num starts at 1. Becomes 3. Reset to 1.
        
        // Is it possible that `j` resetting causes it to pick up the segment itself if coordinates match?
        // Constraint: x1 < x2. So v1 != v2.
        // Can s[i] connect to s[i]? Only if v2 == v1. But v1.x < v2.x. So v1 != v2.
        
        // Let's look at the provided Buggy Output: `2 7 78`.
        // This implies `max` was 2.
        // This means `a[2]` was calculated as 2, not 3.
        // Why would `a[2]` be 2?
        // i=2. r=s[2] ((7,78)-(27,50)).
        // j iterates 0 to 4.
        // j=0: (75,78)-(80,67). No.
        // j=1: (7,8)-(9,10). No.
        // j=2: (7,78)-(27,50). r.v2(27,50) vs s[2].v1(7,78). No.
        // j=3: (1,2)-(7,8). No.
        // j=4: (27,50)-(75,78). r.v2(27,50) == s[4].v1(27,50). YES.
        // num becomes 2. r becomes s[4]. j becomes 0.
        // Inner loop continues? No, `j=0` is set, then loop increments `j` to 1?
        // FOR LOOP SYNTAX: `for (int j = 0; j < n; j++)`
        // If I set `j=0` inside the loop body, the increment step `j++` happens at the end of the iteration.
        // So if I am at j=4, set j=0. End of iteration. j becomes 1.
        // It skips checking index 0!
        // That's the bug. When `j` is reset to 0, the next iteration checks `j=1`.
        // So it missed `s[0]` which connects to `s[4]`.
        // Therefore, the chain length is counted as 2 instead of 3.
        
        for (int j = 0; j < n; j++) {
            if ((r.v2x == s[j].v1x) && (r.v2y == s[j].v1y)) {
                num++;
                r = s[j];
                j = -1; // @@ Setting j=0 here causes the loop increment to skip index 0 in the next iteration. It should be set to -1 so that the increment makes it 0.
            }
        }
        a[i] = num;
        num = 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            m = i;
        }
    }
    printf("%d %d %d", max, s[m].v1x, s[m].v1y);
    return 0;
}