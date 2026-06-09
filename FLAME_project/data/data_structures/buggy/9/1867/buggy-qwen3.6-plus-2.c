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
        r = s[i]; // @@ The logic fails to track visited segments, leading to infinite loops or incorrect counts if segments form cycles or if the greedy local search doesn't find the global longest path correctly. More critically, it resets j=0 which can cause re-counting or infinite loops if not handled with a visited array. However, the primary logical error for "Wrong Answer" on this specific case is likely that the simple greedy chain building from each start node without sorting or proper graph traversal (like DFS) might miss connections if the input isn't sorted or if the chain jumps around. But looking closely at the test case: 1->2, 2->3, 3->4. The code tries to build a chain. 
        // Let's trace: 
        // i=0: s[0]=(75,78)-(80,67). No successor. num=1. a[0]=1.
        // i=1: s[1]=(7,8)-(9,10). No successor. num=1. a[1]=1.
        // i=2: s[2]=(7,78)-(27,50). Successor s[4]=(27,50)-(75,78). num=2, r=s[4]. j resets to 0.
        //   Now r=(27,50)-(75,78). Check s[0]=(75,78)-(80,67). Match! num=3, r=s[0]. j resets to 0.
        //   Now r=(75,78)-(80,67). No successor. Loop ends. a[2]=3.
        // i=3: s[3]=(1,2)-(7,8). Successor s[1]=(7,8)-(9,10). num=2, r=s[1]. j resets to 0.
        //   Now r=(7,8)-(9,10). No successor. a[3]=2.
        // i=4: s[4]=(27,50)-(75,78). Successor s[0]=(75,78)-(80,67). num=2, r=s[0]. j resets to 0.
        //   Now r=(75,78)-(80,67). No successor. a[4]=2.
        // Max is 3 at index 2. s[2] is (7,78)-(27,50). Output: 3 7 78.
        // Wait, the buggy output was "2 7 78". Why?
        // Ah, the variable `num` is not reset properly inside the outer loop if the inner loop modifies it? No, `num=1` is set at start of outer loop.
        // Let's re-read the provided buggy code carefully.
        // The provided buggy code in the prompt is:
        /*
        for (int i = 0; i < n; i++) {
            r = s[i];
            for (int j = 0; j < n; j++) {
                if ((r.v2x == s[j].v1x) && (r.v2y == s[j].v1y)) {
                    num++;
                    r = s[j];
                    j = 0;
                }
            }
            a[i] = num;
            num = 1;
        }
        */
        // If the output was 2, maybe the order of input matters and my trace assumed indices.
        // Input:
        // 0: 75 78 80 67
        // 1: 7 8 9 10
        // 2: 7 78 27 50
        // 3: 1 2 7 8
        // 4: 27 50 75 78
        
        // Trace i=2 (start 7,78 -> 27,50):
        // r = s[2]. 
        // j=0: s[0] start 75,78. No.
        // j=1: s[1] start 7,8. No.
        // j=2: s[2] start 7,78. No (v2 of r is 27,50).
        // j=3: s[3] start 1,2. No.
        // j=4: s[4] start 27,50. YES.
        // num becomes 2. r becomes s[4] (27,50 -> 75,78). j becomes 0.
        // Loop continues, j increments to 1? No, j=0 then loop increment makes j=1.
        // j=1: s[1] start 7,8. No.
        // j=2: s[2] start 7,78. No.
        // j=3: s[3] start 1,2. No.
        // j=4: s[4] start 27,50. No (r is now 27,50->75,78, so r.v2 is 75,78).
        // Wait, when j=4 matched, r became s[4]. Then j was set to 0.
        // Next iteration: j becomes 1.
        // We missed checking s[0] which starts with 75,78!
        // Because j was reset to 0, then the for loop does j++, so j becomes 1.
        // Index 0 is skipped!
        // So s[0] (75,78 -> 80,67) is never checked as a successor to s[4].
        // Thus the chain stops at length 2.
        
        // The error is `j = 0;` inside the loop combined with the `for` loop increment `j++`.
        // It should be `j = -1;` so that after `j++` it becomes 0.
        
        for (int j = 0; j < n; j++) {
            if ((r.v2x == s[j].v1x) && (r.v2y == s[j].v1y)) {
                num++;
                r = s[j];
                j = -1; // @@ Resetting j to 0 causes the next iteration to start at index 1 due to the for-loop's j++, skipping index 0. It should be reset to -1.
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