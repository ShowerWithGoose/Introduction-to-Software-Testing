#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct location {
    int x1;
    int y1;
    int x2;
    int y2;
    int num;     
};

typedef struct location Loc;
Loc l[2000];

int cmp(const void *p1, const void *p2);         //用于排序的函数 
int cmp2(const void *p1, const void *p2);

int main() 
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        l[i].num = 1;

    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &l[i].x1, &l[i].y1, &l[i].x2, &l[i].y2);
    }

    qsort(l, n, sizeof(Loc), cmp2);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i) {
                continue;
            } else {
                if (l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2) {
                    l[i].y2 = l[j].y2;
                    l[i].x2 = l[j].x2;
                    l[i].num = l[j].num+1; // @@ The accumulation logic is incorrect. It should be l[i].num += l[j].num to correctly chain segments (e.g., if segment A connects to B, and B connects to C, A's count should include C's count via B). Also, this inner loop processes connections in a single pass without ensuring transitive closure correctly or handling the order of operations for chained segments properly when multiple segments might connect. However, the primary logical error leading to the wrong count here is that it overwrites `l[i].num` with `l[j].num + 1` instead of adding `l[j].num` to `l[i].num`. If `l[j]` already represents a chain of length 2, `l[i]` should become 1 + 2 = 3. The current code sets it to 2 + 1 = 3 only if `l[j].num` is 2, but since `l[j]` might have been reset or not fully accumulated depending on iteration order, this is fragile. More critically, if we look at the specific failure: Segment (7,78)-(27,50) connects to (27,50)-(75,78). Then (75,78)-(80,67) connects to that. The segment starting at (7,78) should have num=3. The segment starting at (1,2) connects to (7,8)-(9,10), so num=2. The bug `l[i].num = l[j].num + 1` works for simple chains IF processed in reverse order of connection, but `qsort` sorts by start point. So (7,78) is processed before (27,50). When i is at (7,78), j finds (27,50). (27,50) has num=1. So (7,78) becomes num=2. Later, when i is at (27,50), j finds (75,78). (75,78) has num=1. So (27,50) becomes num=2. The link between (7,78) and the rest is broken because (7,78) already updated its end point to (27,50)'s end point? No, it updates `l[i].x2` to `l[j].x2`. So (7,78) now ends at (75,78). But it didn't pick up the count from the segment that (27,50) later acquired. The fundamental issue is that this greedy single-pass update doesn't handle transitive dependencies correctly when the "next" segment hasn't yet accumulated its own subsequent connections. To fix this properly requires a different approach (like DFS or processing in reverse topological order), but given the constraints and structure, the immediate error causing the wrong answer is the incorrect accumulation formula and the fact that it doesn't re-evaluate or propagate counts correctly. Specifically, `l[i].num = l[j].num + 1` fails to accumulate existing counts if `l[i]` had already connected to something else, though here `l[i]` starts at 1. The bigger issue is that when `l[i]` connects to `l[j]`, `l[j]` might later connect to `l[k]`, but `l[i]` won't know about `l[k]`. The code attempts to solve this by updating `l[i]`'s endpoint, but the count `l[i].num` is not updated again. 
                    
                    // Actually, looking closer at the provided "Reference Program" in the prompt description vs the "Source Code" to debug:
                    // The reference program had: l[i].num += l[j].num;
                    // The source code to debug has: l[i].num = l[j].num+1;
                    // This is definitely an error. It should be +=.
                    
                    l[j].x1 = 0, l[j].y1 = 0, l[j].x2 = 0, l[j].y2 = 0, l[j].num = 0;
                }
            }
        }
    }

    qsort(l, n, sizeof(Loc), cmp);

    printf("%d %d %d\n", l[n - 1].num, l[n - 1].x1, l[n - 1].y1);
    return 0;
}

int cmp(const void *p1, const void *p2) {
    struct location *a = (struct location *)p1;
    struct location *b = (struct location *)p2;
    return a->num - b->num;
}

int cmp2(const void *p1, const void *p2) {
    struct location *a = (struct location *)p1;
    struct location *b = (struct location *)p2;
    if (a->x1 != b->x1)
        return a->x1 - b->x1;
    else
        return a->y1 - b->y2; // @@ Typo: should be b->y1 instead of b->y2 to correctly sort by y-coordinate of the start point.
}