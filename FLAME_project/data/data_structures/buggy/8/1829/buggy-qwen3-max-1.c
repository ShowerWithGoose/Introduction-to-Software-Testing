#include <stdio.h>
#include <stdlib.h>
#define VMAX 100

struct enode {
    int adj; //连接点编号
    struct enode *next;
};

struct vnode {
    struct enode *link;
};
struct vnode g[VMAX];
int Dvisited[VMAX] = {0}; //深度
int Bvisited[VMAX] = {0}; //广度

struct enode *insert(struct enode *head, int v) {
    struct enode *e;
    e = (struct enode *)malloc(sizeof(struct enode));
    e->adj = v;
    e->next = NULL;
    if (head == NULL) {
        return e;
    }
    struct enode *p = head, *prev = NULL;
    while (p != NULL && p->adj < e->adj) {
        prev = p;
        p = p->next;
    }
    e->next = p;
    if (prev == NULL) {
        return e;
    } else {
        prev->next = e;
    }
    return head;
}

void DFS(int v) {
    if (g[v].link == NULL) return; // @@ [This condition causes DFS to skip printing isolated vertices. However, even if a vertex has no neighbors, it should still be printed when visited. In the test case after deletion, vertex 0 and 2 are connected, but if a vertex had become isolated (which isn't the case here due to connectivity constraint), this would fail. But more critically, in the current logic, the print happens before checking neighbors, so this early return prevents printing vertex v if it has no neighbors — which violates traversal requirements. However, in our test case, after deletion, both 0 and 2 have links, so this may not be the main issue. The real problem is elsewhere.]
    printf("%d ", v);
    Dvisited[v] = 1;
    for (struct enode *p = g[v].link; p != NULL; p = p->next) {
        if (!Dvisited[p->adj])
            DFS(p->adj);
    }
}

void travelDFS(int n) {
    for (int i = 0; i < n; i++)
        Dvisited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!Dvisited[i])
            DFS(i);
}

int q[VMAX];
int front = 0;
int rear = -1;

void BFS(int v) {
    printf("%d ", v);
    Bvisited[v] = 1;
    q[++rear] = v;
    while (front <= rear) {
        v = q[front++];
        for (struct enode *p = g[v].link; p != NULL; p = p->next) {
            if (!Bvisited[p->adj]) {
                printf("%d ", p->adj);
                Bvisited[p->adj] = 1;
                q[++rear] = p->adj;
            }
        }
    }
}

void travelBFS(int nv) {
    for (int i = 0; i < nv; i++)
        Bvisited[i] = 0;
    for (int i = 0; i < nv; i++)
        if (!Bvisited[i])
            BFS(i); // @@ [The BFS traversal starts from every unvisited vertex, but the problem requires starting only from vertex 0. Since the graph is connected, there should be only one component, but after deletion, the code still loops over all vertices. However, because the graph remains connected and we start from 0, other vertices should be visited. But the loop `for (int i=0; i<nv; i++)` may cause multiple BFS calls if 0 is skipped or not first. Actually, since i starts at 0, and 0 is always unvisited initially, BFS(0) will be called and traverse the whole graph. So this may not be the bug. The real issue is in the BFS output after deletion: expected "0 2", but got "0 2 1". That suggests vertex 1 is still being visited after deletion, meaning deletion didn't fully remove vertex 1 from the graph structure during traversal. But wait: in main, they do remove edges to vc (1), and set g[1].link = NULL. However, in BFS and DFS, they still iterate over all vertices from 0 to n-1, including the deleted vertex. The problem says: after deleting the vertex, traverse the remaining graph. But the deleted vertex should not appear in the output, and also should not be used as a starting point. However, in `travelDFS` and `travelBFS`, they loop `for (int i=0; i<n; i++)`, and if the deleted vertex is not marked as visited, they will call DFS/BFS on it. But in the deletion step, they don't mark the deleted vertex as "removed" in the visited array — they only remove its edges. So when `travelDFS` runs after deletion, it checks `if (!Dvisited[i])` for i=0,1,2. Vertex 1 has Dvisited[1]=0 (since visited arrays were reset), and g[1].link is NULL, so in DFS(1), it hits `if (g[1].link == NULL) return;` and prints nothing. But that means vertex 1 is never printed, which is correct. However, in BFS, when i=1, Bvisited[1] is 0, so BFS(1) is called. In BFS(1): it prints "1 ", marks Bvisited[1]=1, enqueues 1, then processes neighbors — but g[1].link is NULL, so nothing else. So BFS would output "1 " in addition to the component from 0. But in the test output, after deletion, BFS outputs "0 2 1", meaning both components are printed: first 0's component, then 1. But the graph after deletion should exclude vertex 1 entirely. The problem states: "after deleting the specified vertex", so vertex 1 should not be part of the graph at all. Therefore, during traversal after deletion, we must skip the deleted vertex entirely — not just remove its edges, but also prevent it from being a starting point in the traversal loop. The current code does not do that. The fix would be to mark the deleted vertex as "visited" (or skipped) in the traversal functions after deletion. But in the current code, in `travelDFS` and `travelBFS`, there's no knowledge of which vertex was deleted. The deletion is done by removing edges, but the traversal loops still consider the deleted vertex as a potential root. Hence, in the after-deletion BFS, it prints the component starting at 0 ("0 2"), then later when i=1, since Bvisited[1] is still 0, it calls BFS(1) and prints "1". That explains the extra "1" in BFS output. Similarly, in DFS after deletion: travelDFS calls DFS(0) -> prints "0 2", then when i=1, Dvisited[1] is 0, so calls DFS(1). In DFS(1): g[1].link is NULL, so it returns immediately without printing anything. So DFS output is "0 2", which matches expected. But BFS prints "0 2 1" because BFS(1) prints "1 " at the beginning. So the error is that in BFS, even if a vertex has no neighbors, it still prints itself at the start. Whereas in DFS, it returns early without printing. This inconsistency causes the bug. The root cause is two-fold: (1) the DFS function has an incorrect early return that skips printing isolated vertices, but in this test case, it accidentally hides the problem because vertex 1 isn't printed; (2) the BFS function correctly prints the vertex even if isolated, which exposes the fact that the traversal loop shouldn't be starting from the deleted vertex at all. The proper fix is to ensure that in the after-deletion traversals, the deleted vertex is excluded from being a starting point. However, looking at the code: in main, after deletion, they call travelDFS(nv) and travelBFS(nv) — these functions have no parameter indicating which vertex was deleted, so they don't know to skip it. Therefore, the design flaw is that the deletion only removes edges but doesn't prevent the deleted vertex from being considered in the traversal loop. To fix this without changing function signatures, one could mark the deleted vertex as visited before calling travelDFS/travelBFS after deletion. But in the current code, they reset the visited arrays inside travelDFS/travelBFS, so any pre-marking would be wiped out. Hence, the correct approach is to modify travelDFS and travelBFS to accept the deleted vertex and skip it. But the given code doesn't do that. However, in the reference program, they pass 'vc' to travelDFS and travelBFS, and inside those functions, they do `Dvisited[vc]=1;` before the loop, so the deleted vertex is marked as visited and skipped. In the buggy code, travelDFS and travelBFS don't take vc as parameter, and don't mark vc as visited. Therefore, the main errors are: (a) the DFS function incorrectly returns early without printing the vertex when it has no neighbors; (b) the traversal functions (travelDFS and travelBFS) do not exclude the deleted vertex from being a starting point, because they don't know about vc. But in the provided buggy code, after deletion, they do call travelDFS(nv) and travelBFS(nv) without any info about vc. So the immediate cause of the wrong BFS output is that BFS(1) is called and prints "1". The DFS doesn't print "1" only because of the erroneous early return. So both issues need fixing. However, the problem asks to annotate the given source code with @@ where errors occur. The key lines are: in DFS, the early return; and in the traversal loops in travelDFS and travelBFS, the lack of skipping the deleted vertex. But since the functions don't have vc, the real structural error is that main doesn't prevent the deleted vertex from being traversed. However, looking at main: after deletion, they reset front/rear, read vc, delete edges, then call travelDFS(nv). There's no mechanism to skip vc in traversal. So the error is that travelDFS and travelBFS should not start from vc. But since they can't know vc, the fix must be in main: before calling travelDFS after deletion, mark Dvisited[vc]=1 and Bvisited[vc]=1, but note that travelDFS resets Dvisited. So that won't work. Therefore, the design requires passing vc to the travel functions, like the reference program does. Since the buggy code doesn't do that, the error is in the design of travelDFS and travelBFS — they should take vc as argument and skip it. But the given code doesn't. However, the problem says: "identify the location of the errors in the program below". Given the code as is, the direct causes are: 1. In DFS, the early return prevents printing a vertex with no neighbors — but in a correct implementation, every visited vertex should be printed, regardless of neighbors. 2. In BFS, the function prints the vertex even if it's isolated, which is correct behavior, but since the deleted vertex is still being started from, it gets printed. So to align behaviors and meet spec, both traversals should skip the deleted vertex entirely. Since the code doesn't skip it, and the BFS prints it while DFS doesn't (due to bug), the outputs differ. The primary error locations are: - The DFS function's early return. - The fact that travelDFS and travelBFS don't exclude the deleted vertex. But since the latter is a design flaw across multiple lines, and the problem likely expects line-specific annotations, the clearest errors are: (a) in DFS, the early return line; (b) in main, after deletion, when calling travelDFS and travelBFS, there's no exclusion of vc — but that's not a single line. However, note that in the BFS function, it always prints the starting vertex, which is correct, but the issue is that it's called on vc. So the root is that the loop in travelBFS includes vc. But without vc info, it can't skip. Given the constraints, the most actionable line errors are: 1. The early return in DFS. 2. The BFS function is correct in printing the vertex, but the call to BFS(vc) is wrong — however, that call originates from travelBFS's loop. Since travelBFS can't know vc, the error is that main should have marked vc as visited before calling travelBFS, but it can't because travelBFS resets the array. Therefore, the fundamental error is that the travel functions don't accept vc. But since we can't change function signatures per instructions, we must annotate existing lines. Looking back at the test: after deletion, expected BFS is "0 2", but got "0 2 1". The "1" comes from BFS(1) being called. Why is BFS(1) called? Because in travelBFS, after resetting Bvisited, it loops i=0 to nv-1, and when i=1, Bvisited[1] is 0, so it calls BFS(1). To prevent this, we need to ensure that vc is not considered. The only way within the current structure is to modify travelBFS to skip vc, but it doesn't have vc. Hence, the error is that the program deletes the edges but doesn't exclude the vertex from traversal initiation. However, the problem states: "the graph is connected both before and after deleting the specified vertex", and "the vertex to be deleted is not vertex 0". After deletion, the graph has nv-1 vertices (excluding vc), but the code still uses nv and considers vertices 0..nv-1, including vc. The specification implies that the deleted vertex is removed from the graph, so traversals should only consider the remaining vertices. Therefore, in the after-deletion traversals, the loop should run for i in [0, nv) but skip i==vc. Since the current travel functions don't do that, and main doesn't compensate, the error manifests. But again, where to annotate? The most precise annotations are: - In DFS: the early return line causes inconsistent behavior (doesn't print isolated vertices), which accidentally hides the problem for DFS but not for BFS. - In travelBFS and travelDFS: the loop `for (int i = 0; i < nv; i++)` should skip the deleted vertex, but they don't have access to vc. However, since the problem's reference program passes vc to these functions, the error is that these functions are not designed to receive vc. But in the given code, they aren't. Given the instructions, we must annotate lines in the provided source. The direct cause of the wrong BFS output is that BFS(1) is executed and prints "1". The reason BFS(1) is executed is that in travelBFS, the loop includes i=1 and Bvisited[1] is 0. There's no line in travelBFS that skips vc, so the error is the loop itself — but it's correct for the general case. The real issue is upstream. However, note that in main, after deleting the edges, they do: free(g[vc].link); g[vc].link = NULL; But they don't do anything to prevent vc from being traversed. So perhaps the error is that in the after-deletion traversal calls, they should temporarily mark vc as visited, but since the travel functions reset the visited array, that's not possible. Therefore, the only viable fix within the current structure is to modify travelDFS and travelBFS to accept vc, but they don't. Since we can't change that, and the problem asks for error locations in the given code, the observable errors are: 1. DFS function has an incorrect early return. 2. BFS function correctly prints the vertex, but because the deleted vertex is still initiated, it appears in output. The initiation happens in travelBFS's loop. But without vc, it can't skip. Given the test case, the BFS output includes "1" because travelBFS calls BFS(1). So the error is that travelBFS (and travelDFS) should not start from vc. Since they don't know vc, the program is flawed. But for annotation purposes, the line in travelBFS that says `if (!Bvisited[i]) BFS(i);` will call BFS on vc, which is wrong. Similarly for travelDFS. However, the problem might consider the DFS early return as the main error because it causes inconsistent handling. Let's compare: - Before deletion: graph is complete, so no isolated vertices, both DFS and BFS work. - After deletion: vertex 1 is isolated (no edges), so: - DFS(1) is called, but returns early without printing -> so "1" not printed. - BFS(1) is called, prints "1", then finds no neighbors -> so "1" is printed. Hence, the outputs differ. The specification requires that after deletion, the graph excludes vertex 1, so neither traversal should include 1. The fact that DFS doesn't print it is accidental (due to bug), and BFS does print it (correctly per its logic, but wrongly per problem spec because 1 should be excluded). Therefore, both traversals are wrong in their own way, but the problem's expected output excludes 1, so the correct behavior is to never start traversal from 1. The core issue is that the traversal initiation includes 1. To fix this, the travel functions need to skip vc. Since they don't, and the code has no mechanism, the error is in the design of travelDFS and travelBFS — they should have a way to skip vc. But as per the given code, the only lines we can annotate are: - The early return in DFS (because it's logically wrong: a vertex should be printed when visited, regardless of neighbors). - The loops in travelDFS and travelBFS that initiate traversal from every unvisited vertex, including the deleted one. However, the problem states the graph is connected after deletion, so there should be only one component, and starting from 0 should suffice. The specification says: "In any traversal, the traversal should start from vertex 0." This means that the traversal should ONLY start from vertex 0, not from every unvisited vertex. The current code's loop `for (int i=0; i<n; i++) if (!visited[i]) traverse(i);` is for disconnected graphs, but the problem states the graph is connected. However, after deletion, it's still connected, so only i=0 should be the start. But the loop starts at i=0, calls traverse(0), which visits all vertices, so for i>0, visited[i] is true, so no further calls. Except for the deleted vertex: after deletion, vertex 1 is not connected to 0, but the problem states the graph remains connected after deletion. Wait! The problem says: "The graph is connected both before and after deleting the specified vertex." So after deleting vertex 1, the remaining graph (vertices 0 and 2) must be connected. In the test case: edges are (0,1), (1,2), (0,2). After deleting vertex 1, the remaining edges are (0,2), so vertices 0 and 2 are connected. Vertex 1 is removed, so the graph has vertices {0,2} and edge (0,2). So vertex 1 is not part of the graph anymore. Therefore, the traversal should only consider vertices 0 and 2. But the code still considers vertex 1 as part of the graph (since nv=3), and tries to traverse it. The problem says: vertices are labeled 0 to n-1, and after deletion, the graph has n-1 vertices, but the labels are still 0 to n-1 excluding vc. So the code should traverse only the remaining vertices. The specification of the input says: "the number of vertices n", and after deletion, we still use the same n, but ignore vc. So in traversal, we must skip vc. Given that, the loop in travelDFS and travelBFS should skip i == vc. But they don't. So the error is that these loops don't skip vc. However, they don't have vc as a parameter. In the reference program, they do pass vc and mark it as visited before the loop, so it's skipped. In the buggy code, they don't. Therefore, the error is that travelDFS and travelBFS are not passed vc, and thus can't skip it. But since we can't change function calls easily, and the problem asks for line annotations, the most accurate annotations are: - In main, after reading vc and before calling travelDFS the second time, there should be a way to exclude vc, but there isn't. However, the direct lines that cause the wrong output are: 1. In DFS: the early return line, because it causes DFS to not print a vertex with no neighbors, which is incorrect behavior (though in this case, it accidentally gives the right output for DFS). 2. In BFS: the function is correct, but it's called on vc, which is wrong. The call happens in travelBFS's loop. So the loop line in travelBFS is problematic because it doesn't skip vc. But without vc, it can't. Given the above, and since the problem's expected output for BFS after deletion is "0 2" (without "1"), the presence of "1" is because BFS(1) is called. The reason BFS(1) is called is that in travelBFS, after resetting Bvisited, Bvisited[1] is 0, so it calls BFS(1). To prevent this, we need to ensure that vc is not processed. The only way is to modify the travel functions to know about vc. Since they don't, the error is in the interface. But for the purpose of this exercise, the line in travelBFS that initiates BFS on unvisited vertices will include vc, so that line is effectively wrong in the context of vertex deletion. However, the problem likely expects the DFS early return as one error, and the lack of skipping vc in the traversal loops as another. But how to annotate? Let's look at the exact outputs: - DFS after deletion: "0 2" (correct) — but only because DFS(1) returns early. If DFS were correct, it would print "1" as well, making it wrong. So the DFS output is accidentally correct due to a bug. - BFS after deletion: "0 2 1" (wrong) — because BFS(1) prints "1". So both traversals have issues, but the BFS output is observably wrong. The root cause for BFS is that it processes vc. The root cause for DFS is that it doesn't process vc (due to early return), which is also wrong behavior, but matches expected output by accident. The problem says "identify the location of the errors", so both are errors. Therefore, annotate: - The early return in DFS as an error (because a vertex should be printed when visited, even if it has no neighbors). - The loops in travelDFS and travelBFS as errors because they don't skip the deleted vertex. But the loops are written generally. Given the instructions, and to match the test case failure, the critical error that causes the wrong answer is the BFS printing "1", which stems from travelBFS calling BFS(1). So the line in travelBFS that says `if (!Bvisited[i]) BFS(i);` is where the error manifests, because it should not call BFS on the deleted vertex. Similarly for travelDFS, though it doesn't print due to another bug. So annotate those lines. Additionally, the DFS early return is a separate error. Let's do it.
    }
}

void travelDFS(int n) {
    for (int i = 0; i < n; i++)
        Dvisited[i] = 0;
    for (int i = 0; i < n; i++) // @@ [This loop initiates DFS from every unvisited vertex, including the deleted vertex 'vc'. Since the graph is connected after deletion, traversal should start only from vertex 0, and the deleted vertex should be excluded entirely. However, this loop will attempt to start DFS from 'vc' if it hasn't been visited, leading to incorrect behavior (though masked in DFS by another bug).]
        if (!Dvisited[i])
            DFS(i);
}

int q[VMAX];
int front = 0;
int rear = -1;

void BFS(int v) {
    printf("%d ", v);
    Bvisited[v] = 1;
    q[++rear] = v;
    while (front <= rear) {
        v = q[front++];
        for (struct enode *p = g[v].link; p != NULL; p = p->next) {
            if (!Bvisited[p->adj]) {
                printf("%d ", p->adj);
                Bvisited[p->adj] = 1;
                q[++rear] = p->adj;
            }
        }
    }
}

void travelBFS(int nv) {
    for (int i = 0; i < nv; i++)
        Bvisited[i] = 0;
    for (int i = 0; i < nv; i++) // @@ [This loop initiates BFS from every unvisited vertex, including the deleted vertex 'vc'. After deletion, 'vc' is no longer part of the graph, so BFS should not start from it. This causes the deleted vertex to be printed in BFS output (as seen in the test case: extra '1'), because BFS(v) always prints 'v' at the start.]
        if (!Bvisited[i])
            BFS(i);
}

int main() {
    int nv, ne; //顶点个数，边的个数
    scanf("%d%d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        g[v1].link = insert(g[v1].link, v2);
        g[v2].link = insert(g[v2].link, v1);
    }
    travelDFS(nv);
    printf("\n");
    travelBFS(nv);
    printf("\n");

    // 处理一下
    front = 0;
    rear = -1;
    int vc; // v_canceled
    scanf("%d", &vc);
    // 移除所有与vc连接的边
    for (int i = 0; i < nv; i++) {
        struct enode *p = g[i].link, *prev = NULL;
        while (p != NULL) {
            if (p->adj == vc) {
                if (prev == NULL) {
                    g[i].link = p->next;
                } else {
                    prev->next = p->next;
                }
                free(p);
                p = (prev == NULL) ? g[i].link : prev->next;
                continue;
            }
            prev = p;
            p = p->next;
        }
    }
    free(g[vc].link);
    g[vc].link = NULL;
    travelDFS(nv);
    printf("\n");
    travelBFS(nv);
    printf("\n");
    return 0;
}