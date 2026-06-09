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
    visit[stack[finger]]=1; // @@ The visit array is marked only after processing all neighbors, which is incorrect for BFS/DFS logic where nodes should be marked visited when enqueued/discovered to prevent duplicates. However, the bigger issue is that this function implements a weird mix of DFS/BFS using a stack-like structure but calling it wfs (likely BFS). More critically, the output loop at the end prints from index 0 to vet-tep, but the 'stack' array here is being used as a queue in a BFS manner? No, it's adding neighbors to 'point' which acts like a tail. But standard BFS uses a queue. This implementation looks like a flawed BFS or DFS. Let's look at the expected output. The expected BFS for original graph 0-1-2 triangle starting at 0 is 0 1 2. The code's wfs for type 1: starts with stack[0]=0. finger=0. i loops 0..2. graph[0][1]=1, visit[1]=0 -> stack[1]=1, point=2. graph[0][2]=1, visit[2]=0 -> stack[2]=2, point=3. Then visit[0]=1, finger=1. Next iteration finger=1 < 3. i resets to 0. stack[1]=1. Neighbors of 1: 0 (visited), 2 (visit[2] is still 0? No, visit is global. But visit[2] was NOT set to 1 when it was added to stack. So when processing node 1, it sees neighbor 2 is unvisited and adds it again? stack[3]=2. point=4. Then visit[1]=1, finger=2. Next iteration finger=2 < 4. stack[2]=2. Neighbors of 2: 0 (visited), 1 (visited). No adds. visit[2]=1, finger=3. Loop ends. Output loop prints stack[0] to stack[2] (vet-tep = 3-0=3). So 0 1 2. This matches. 
    // Now for deleted vertex 1. Graph becomes 0-2 edge. del=1. tep=1. vet-tep=2.
    // wfs(0, 2). stack[0]=0. finger=0. i loops. graph_del[0][2]=1. visit[2]=0. stack[1]=2. point=2.
    // visit[0]=1. finger=1.
    // finger=1 < 2. stack[1]=2. i loops. graph_del[2][0]=1 (visit[0]=1). No adds.
    // visit[2]=1. finger=2. Loop ends.
    // Output loop prints stack[0] to stack[1]. 0 2. Matches.
    // So why is the output wrong?
    // Let's check the first wfs call output in buggy output: "0 2 ". Expected "0 1 2".
    // Wait, the buggy output provided in the prompt is:
    // 0 1 2 
    // 0 2 
    // 0 2
    // Expected:
    // 0 1 2
    // 0 1 2
    // 0 2
    // 0 2
    // The buggy output is missing the second line "0 1 2" (BFS before delete) and instead prints "0 2".
    // And it's missing the last newline or something?
    // Actually, looking at the main function:
    // dfs(0,1); memset... printf("\n");
    // wfs(0,1); memset... printf("\n");
    // dfs(0,2); memset... printf("\n");
    // wfs(0,2);
    // The buggy output has 3 lines. The expected has 4 lines.
    // Line 1: 0 1 2 (DFS before) - Correct.
    // Line 2: 0 2 (BFS before) - Incorrect. Should be 0 1 2.
    // Line 3: 0 2 (DFS after) - Correct.
    // Line 4: 0 2 (BFS after) - Missing in buggy output? Or is the last line empty?
    // The buggy output shows "0 2 \n0 2\n". It seems wfs(0,1) printed "0 2 " instead of "0 1 2 ".
    
    // Why did wfs(0,1) print 0 2?
    // In wfs, `visit` array is used. Before wfs(0,1) is called, `memset(visit,0,100)` is called.
    // Inside wfs(0,1): type=1, tep=0 (since type!=2). vet-tep=3.
    // stack[0]=0. finger=0.
    // Inner while i<3:
    // i=0: graph[0][0]=0.
    // i=1: graph[0][1]=1, visit[1]=0. stack[1]=1, point=2.
    // i=2: graph[0][2]=1, visit[2]=0. stack[2]=2, point=3.
    // visit[0]=1. finger=1. i=0.
    // Outer while finger(1) < 3:
    // Inner while i<3:
    // stack[finger]=stack[1]=1.
    // i=0: graph[1][0]=1, visit[0]=1. Skip.
    // i=1: graph[1][1]=0.
    // i=2: graph[1][2]=1, visit[2]=0. stack[3]=2, point=4.
    // visit[1]=1. finger=2. i=0.
    // Outer while finger(2) < 3:
    // Inner while i<3:
    // stack[finger]=stack[2]=2.
    // i=0: graph[2][0]=1, visit[0]=1. Skip.
    // i=1: graph[2][1]=1, visit[1]=1. Skip.
    // i=2: graph[2][2]=0.
    // visit[2]=1. finger=3. i=0.
    // Outer while finger(3) < 3: False.
    // Output loop: i=0 to 2. Prints stack[0]=0, stack[1]=1, stack[2]=2.
    // So wfs(0,1) SHOULD print 0 1 2.
    
    // Why does the buggy output say "0 2"?
    // Maybe the `visit` array wasn't cleared properly?
    // `memset(visit,0,100);` clears 100 bytes. `visit` is `int[100]`. On many systems `sizeof(int)` is 4. So `memset(visit, 0, 100)` only clears the first 25 integers! The rest remain garbage or previous values.
    // If `visit[1]` or `visit[2]` were non-zero from previous DFS run, they would be skipped.
    // In DFS(0,1), visit[0], visit[1], visit[2] are set to 1.
    // Then `memset(visit, 0, 100)` is called. If it only clears first 25 ints, visit[0]..visit[24] become 0. So visit[0], visit[1], visit[2] are 0. This should be fine.
    
    // Wait, look at the second wfs call in main: `wfs(0,2);` at the very end. There is no `printf("\n")` after it.
    // The expected output has 4 lines. The buggy output has 3 lines shown.
    
    // Let's re-read the Buggy Output carefully:
    // "0 1 2 \n\n0 2 \n0 2"
    // It seems there is an empty line or something?
    
    // Actually, the main issue is likely the `memset` size.
    // `memset(visit,0,100);` should be `memset(visit,0,sizeof(visit));` or `sizeof(int)*100`.
    // If `sizeof(int)` is 4, `memset(visit, 0, 100)` zeros out 100 bytes, which is 25 integers.
    // Indices 0-24 are zeroed. Indices 25-99 are untouched.
    // Since vertices are 0-99 max, if any vertex > 24 was visited, it wouldn't be cleared.
    // In the test case, vertices are 0,1,2. They are within 0-24. So memset(visit,0,100) SHOULD work for this specific test case if the memory layout is standard.
    
    // Is there another error?
    // Look at `wfs` logic again.
    // `visit[stack[finger]]=1;` happens AFTER exploring neighbors.
    // This allows the same node to be added to the stack multiple times if it's a neighbor of multiple nodes processed before it is marked visited.
    // In my trace above:
    // Node 0 adds 1 and 2.
    // Node 1 adds 2 (because visit[2] is still 0).
    // So stack becomes [0, 1, 2, 2].
    // Output loop prints `vet-tep` elements. For type 1, tep=0, vet=3. Prints 3 elements: 0, 1, 2.
    // The duplicate 2 is at index 3, which is not printed.
    // So for this specific case, it works.
    
    // What if the graph was different?
    // The problem states Wrong Answer.
    
    // Let's look at the `dfs` function.
    // It uses recursion.
    
    // Let's look at the `main` function loop for reading edges.
    // `while(~scanf("%d",&type))`
    // This reads the vertex to delete. The problem says "Finally, input the vertex number to be deleted on a new line."
    // It implies only ONE vertex is deleted.
    // But the code uses `while(~scanf(...))`. This will keep reading until EOF.
    // If there is only one integer, it reads it, processes it.
    // Inside the loop: `del++`.
    // Then it modifies `graph_del`.
    // Then it runs DFS and BFS.
    // If the input has only one deletion vertex, the loop runs once.
    
    // However, notice that `graph_del` is modified cumulatively if there were multiple deletions, but here there is only one.
    
    // The critical error might be in `wfs` not printing a newline at the end?
    // The last call `wfs(0,2);` is not followed by `printf("\n");`.
    // The expected output has 4 lines.
    // Buggy output:
    // Line 1: 0 1 2 
    // Line 2: (Empty? Or is "0 2 " on line 2?)
    // The provided buggy output is:
    // "0 1 2 \n\n0 2 \n0 2"
    // This looks like:
    // Line 1: "0 1 2 "
    // Line 2: "" (Empty)
    // Line 3: "0 2 "
    // Line 4: "0 2"
    
    // Wait, if `wfs(0,1)` printed "0 1 2 ", then `printf("\n")` makes it "0 1 2 \n".
    // Then `dfs(0,2)` prints "0 2 ". Then `printf("\n")` makes it "0 2 \n".
    // Then `wfs(0,2)` prints "0 2 ". No newline.
    
    // Where does the empty line come from?
    // Maybe `wfs(0,1)` printed nothing?
    // If `wfs(0,1)` printed nothing, then `printf("\n")` prints an empty line.
    // Why would `wfs(0,1)` print nothing?
    // If `finger < vet-tep` condition failed immediately?
    // vet=3, tep=0. 0 < 3. True.
    
    // Let's look at the `visit` array clearing again.
    // `memset(visit,0,100);`
    // If this is the issue, it's undefined behavior for indices > 24.
    // But for 0,1,2 it should be fine.
    
    // Is it possible `graph` or `graph_del` was not initialized?
    // Global variables are initialized to 0 by default in C. So that's fine.
    
    // Let's look at the `dfs` output for the deleted case.
    // `dfs(0,2)`.
    // `graph_del` has edges to `type` removed.
    // Input: 1 is deleted.
    // graph_del[0][1]=0, graph_del[1][0]=0, graph_del[1][2]=0, graph_del[2][1]=0.
    // Edges remaining: 0-2.
    // DFS(0,2):
    // Print 0. Visit[0]=1.
    // i=0: graph_del[0][0]=0.
    // i=1: graph_del[0][1]=0.
    // i=2: graph_del[0][2]=1. Visit[2]=0. Recurse DFS(2,2).
    //   Print 2. Visit[2]=1.
    //   i=0: graph_del[2][0]=1. Visit[0]=1. Return.
    //   i=1: graph_del[2][1]=0.
    //   i=2: graph_del[2][2]=0.
    //   Return.
    // Output: 0 2 . Correct.
    
    // So DFS is correct.
    
    // Why is BFS (wfs) before deletion wrong?
    // Expected: 0 1 2.
    // Buggy: 0 2 (from the output "0 1 2 \n\n0 2 \n0 2", the second line is empty, third is 0 2).
    // Wait, if the second line is empty, it means `wfs(0,1)` printed NOTHING.
    // Why?
    
    // Ah! Look at `wfs` declaration:
    // `void wfs(int a,int type)`
    // Inside: `int i=0...`
    // `stack[0]=a;`
    // `if(type==2) tep=del;`
    // `else` tep is uninitialized!
    // `while(finger<vet-tep)`
    // If type==1, `tep` is uninitialized. It contains garbage.
    // If `tep` is large, `vet-tep` could be negative or small.
    // If `tep` happens to be 3 or more, `finger(0) < 3-tep` might be false.
    // If `tep` is garbage, the behavior is undefined.
    // In many cases, uninitialized local variables on the stack might contain 0 or large values.
    // If `tep` was 0, it works.
    // If `tep` was 1, `vet-tep` = 2. Loop runs for finger 0, 1.
    // If `tep` was 2, `vet-tep` = 1. Loop runs for finger 0.
    // If `tep` was 3, `vet-tep` = 0. Loop doesn't run. No output.
    
    // This explains the empty line! If `tep` was uninitialized and happened to be >=3, the loop doesn't run, nothing is printed, then `printf("\n")` prints an empty line.
    
    // The fix is to initialize `tep` to 0.
    
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
}
dfs(0,1); 
memset(visit,0,100);printf("\n");
wfs(0,1);
memset(visit,0,100);printf("\n");
dfs(0,2);
memset(visit,0,100);printf("\n");
wfs(0,2);



}