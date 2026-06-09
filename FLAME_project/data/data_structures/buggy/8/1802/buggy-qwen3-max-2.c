#include <stdio.h>
int graph[100][100],graph_del[100][100],visit[100];
int vet,line,i=0,type,temp,temp1,start,del=0;
void dfs(int a,int type)
{
    int i=0,flag=0;
    if(visit[a]!=0)
    return;
    printf("%d ",a);
    visit[a]=1;
    while(i<vet)
    {
        
        if(graph[a][i]==1&&type==1)
        dfs(i,type);
        else if(graph_del[a][i]==1&&type==2)
        dfs(i,type);
        i++;
    }
}
void wfs(int a,int type)
{
    int i=0,i1=0,stack[100],point=1,finger=0,tep;
    stack[0]=a;
    if(type==2)
    tep=del;
    while(finger<vet-tep)
    {
    while(i<vet)
    {
        if(graph[stack[finger]][i]==1&&visit[i]==0&&type==1)
        {
        stack[point]=i;
        point++;
        }
        else if(graph_del[stack[finger]][i]==1&&visit[i]==0&&type==2)
        {
        stack[point]=i;
        point++;
        }
        i++;
    }
    visit[stack[finger]]=1;
    finger++;i=0;
    }
    while(i<vet-tep)
    {
    printf("%d ",stack[i]);
    i++;
    }
}

int main()
{
scanf("%d %d",&vet,&line);
while(i<line)
{
    scanf("%d %d",&temp,&temp1);
    graph[temp][temp1]=1;
    graph_del[temp][temp1]=1;
    graph[temp1][temp]=1;
    graph_del[temp1][temp]=1;
    i++;
}
while(~scanf("%d",&type))
{
    i=0;del++;
    while(i<vet)
    {
        graph_del[i][type]=0;
        graph_del[type][i]=0;
        i++;
    }
}@@ // The loop `while(~scanf(...))` reads until EOF, but the problem specifies only one vertex to delete. This causes `del` to increment once per input, but if multiple inputs exist (or due to EOF behavior), it may corrupt logic. More critically, it runs deletion repeatedly and sets `del = number of inputs`, which is wrong. For the given test case, it runs once so `del=1`, which accidentally works, but the real issue is elsewhere.
dfs(0,1); 
memset(visit,0,100);printf("\n");
wfs(0,1);
memset(visit,0,100);printf("\n");
dfs(0,2);
memset(visit,0,100);printf("\n");
wfs(0,2);



}@@ // Missing newline at end of output? Not the main issue. The core errors are in traversal implementations.

// Additional annotations on specific lines:

// In dfs: the traversal order is not enforced to be ascending because recursion happens immediately upon finding an unvisited neighbor, but since `i` increments from 0, it actually does visit in ascending order. So DFS may be okay.

// In wfs: BFS implementation is flawed. It uses a single array `stack` but doesn't manage the queue properly. Specifically:
// - It processes `stack[finger]` and scans all neighbors, adding them to `stack` at `point`.
// - However, it marks `visit[stack[finger]]=1` AFTER scanning neighbors, which is okay.
// - BUT: when `type==1` (before deletion), `tep` is uninitialized! Because `tep` is only set if `type==2`. So in first BFS call, `tep` is garbage, and `vet-tep` is wrong.
// This causes the BFS loop condition `finger < vet - tep` to be incorrect for the first BFS.

// Also, `del` is incremented in the input loop, but `del` should be 1 (since one vertex deleted), but only if exactly one deletion input. However, the bigger issue is `tep` uninitialized in wfs for type=1.

// Another issue: in main, after reading edges, the deletion input is read in a `while(~scanf(...))` loop, which is incorrect—it should read only once. But in the test case, it reads one value and then waits for EOF, so `del` becomes 1, which is correct. However, the real bug is in `wfs`.

// Let's annotate the critical lines in wfs:

// Line inside wfs: `if(type==2) tep=del;` — if type==1, tep is uninitialized. So:
void wfs(int a,int type)
{
    int i=0,i1=0,stack[100],point=1,finger=0,tep;@@ // tep is uninitialized when type==1
    stack[0]=a;
    if(type==2)
    tep=del;
    while(finger<vet-tep)@@ // when type==1, tep is garbage → undefined behavior
    {
    while(i<vet)
    {
        if(graph[stack[finger]][i]==1&&visit[i]==0&&type==1)
        {
        stack[point]=i;
        point++;
        }
        else if(graph_del[stack[finger]][i]==1&&visit[i]==0&&type==2)
        {
        stack[point]=i;
        point++;
        }
        i++;
    }
    visit[stack[finger]]=1;
    finger++;i=0;
    }
    while(i<vet-tep)@@ // again, tep uninitialized for type==1
    {
    printf("%d ",stack[i]);
    i++;
    }
}

// Also, in main: the memset uses `100` instead of `100*sizeof(int)` or `sizeof(visit)`. Since `visit` is int[100], `memset(visit,0,100)` only clears 100 bytes, but 100 ints = 400 bytes (assuming 4-byte int). So it leaves garbage in upper bytes. However, since we only use indices 0..vet-1 and set via assignment, maybe not fatal—but could cause issues if leftover non-zero values.

// But in the test case: n=3, so only indices 0,1,2 matter. If `memset(visit,0,100)` clears first 100 bytes = 25 ints (if int=4), which covers 0..24, so safe. So not the cause.

// The primary error is uninitialized `tep` in `wfs` when `type==1`.

// Also, note: in the first BFS call, `del` is 1 (because input loop ran once), but `tep` is not set, so `vet - tep` is `3 - (garbage)`, which likely causes the loop to run too few or too many times.

// In the test case, expected first BFS is "0 1 2", but buggy output shows only "0" on second line? Actually, buggy output is:
// 0 1 2 
// 
// 0 2 
// 0 2

// Wait, the buggy output has a blank line? Actually, the provided buggy output is:
// "0 1 2 \n\n0 2 \n0 2"

// But expected is four lines.

// Looking at the code: after first DFS: prints "0 1 2 " then "\n"
// Then calls wfs(0,1): which may print nothing or partial, then "\n"
// In test case, it printed nothing? Or just "0"?

// Actually, in the buggy output shown: 
// Line1: "0 1 2 "
// Line2: (empty)
// Line3: "0 2 "
// Line4: "0 2"

// But expected:
// Line1: "0 1 2"
// Line2: "0 1 2"
// Line3: "0 2"
// Line4: "0 2"

// So the second line (first BFS) is missing.

// Why? Because in wfs(0,1):
// - tep is uninitialized → suppose tep is large, then vet-tep <=0, so while(finger < vet-tep) doesn't run → prints nothing in the final while loop either.

// Therefore, the key error is uninitialized `tep`.

// Also, in main: the deletion loop is wrong—it should read the vertex once, not in a while loop.

// But the immediate fixable error in the code as given is the uninitialized `tep`.

// Additionally, in the DFS after deletion: it uses `graph_del`, which is correctly modified.

// Another issue: in wfs, the BFS algorithm is not standard. It uses a single pass that may not enqueue level by level correctly because it uses `finger` to index the current node, but adds all unvisited neighbors of `stack[finger]` to the end. However, because it resets `i=0` each time and scans all vertices, and `point` keeps growing, it might work if the loop condition were correct. But the main flaw is `tep`.

// So annotate:

// In wfs declaration: tep uninitialized for type=1
// In main: the while(~scanf(...)) is incorrect—it should be a single scanf.

// But per instructions: add @@ after the line where error occurs.

// So:

// In main: the while(~scanf(...)) line is problematic because it reads until EOF, but only one vertex is to be read. This causes potential multiple deletions and incorrect `del` value. However, in the test case with one input, `del` becomes 1, which is correct. But the loop itself is logically wrong.

// But the more direct error causing WA is in `wfs` due to uninitialized `tep`.

// We must annotate lines in the given source.

// Let's go line by line in the provided source:

// Line: `while(~scanf("%d",&type))` — this is wrong; should be `scanf("%d", &type);` without loop.
// Line: inside wfs: `int ... tep;` — uninitialized when type=1.
// Line: `while(finger<vet-tep)` — uses uninitialized tep when type=1.
// Line: `while(i<vet-tep)` — same.

// Also, in main: `memset(visit,0,100);` — should be `sizeof(visit)` or `100*sizeof(int)`, but as reasoned, may not cause failure in small n.

// Given the test case fails on second line (BFS before deletion), the culprit is `tep` uninitialized.

// So annotate:

// In function wfs:
// Line: `int i=0,i1=0,stack[100],point=1,finger=0,tep;` → tep uninitialized for type=1
// But we can only add @@ after the line.

// Also, the while loop condition lines use tep.

// However, the root is the declaration.

// Additionally, in main, the input loop for deletion is wrong.

// Per instructions, add @@ after any line that has or causes an error.

// So:

// In main:
// Line: `while(~scanf("%d",&type))` → should read only once
// Line: `i=0;del++;` → del is incremented per input, but should be set to 1 (or just use 1 directly)
// But the immediate effect is that for one input, del=1, which is okay. However, the loop is still logically incorrect.

// But the BFS failure is due to tep.

// Let's annotate the tep-related lines.

// Final decision: annotate the declaration of tep and the two loop conditions, and the input loop.

// However, the problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

// So:

// Line in main: `while(~scanf("%d",&type))` → error: reads multiple vertices but only one should be read
// Line in wfs: `int i=0,i1=0,stack[100],point=1,finger=0,tep;` → error: tep uninitialized when type==1
// Line in wfs: `while(finger<vet-tep)` → error: uses uninitialized tep when type==1
// Line in wfs: `while(i<vet-tep)` → error: same

// Also, note: in the first call to wfs(0,1), type=1, so tep is never set.

// Now, write the full code with @@ after those lines.