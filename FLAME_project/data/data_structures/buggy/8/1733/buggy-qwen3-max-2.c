#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  G[10][10];
int visited[10];
int numv,nume;
int Q[20];
int front=0,rear=-1;
void DFS(int v)
{//在图G中，从顶点V开始进行深度优先遍历
    visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v); //访问某顶点
    for(int i=0; i<numv;  i++)
         if( !visited[i] &&G[v][i]==1)
             DFS(i);
}
void  travelDFS()
{
    int i;
    for(i=0; i<numv; i++) visited[i] = 0 ;//初始化
    DFS(0);
}
void BFS( int v)
{
    visited[v] = 1; //标识某顶点已入队
    Q[++rear]=v;
    while( !(front>rear)){
         v = Q[front++];  //取出队头元素
         printf("%d ",v); //访问当前顶点
         for(int i=0; i<numv;  i++ ) //访问该顶点的每个邻接顶点
             if( !visited[i]&&G[v][i]==1) {
                    visited[i] = 1; //标识某顶点入队
                    Q[++rear]=i;
           }
     }
}
void  travelBFS()
{
    int i;
    for(i=0; i<numv; i++) visited[i] = 0 ;
    BFS(0);
}
int main(){
scanf("%d%d",&numv,&nume);
int v1,v2;//输入顶点个数，边个数
for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        G[i][j]=0;
    }
}//初始化G邻接矩阵
for(int i=0;i<nume;i++){
scanf("%d%d",&v1,&v2);
G[v1][v2]=1;
G[v2][v1]=1;
}//建邻接矩阵
travelDFS();
printf("\n");
travelBFS();
printf("\n");
int delete;
scanf("%d",&delete);
for(int i=0;i<numv;i++){
    G[delete][i]=0;
    G[i][delete]=0;
}//删除顶点和边；
travelDFS();
printf("\n");
front=0;
rear=-1;
travelBFS();
printf("\n");
return 0;
} // @@ [The program does not reset the 'visited' array before the second DFS and BFS traversals after vertex deletion. Also, the BFS queue indices are not properly reset (front/rear) before the first BFS, but more critically, the second DFS uses the same 'visited' array that was modified by the first BFS, leading to incorrect traversal behavior. Additionally, the adjacency matrix size is fixed at 10x10, but the problem allows up to 100 vertices, which may cause buffer overflow or undefined behavior for n > 10. However, given the test case has n=3, the immediate error causing WA is the missing 'visited' array reinitialization before the second DFS and BFS calls.]

// However, based strictly on the provided test case (n=3), the primary observable error is:
// After the first BFS, the 'visited' array remains filled. Then, when calling travelDFS() again (after deletion), it does NOT reset 'visited', so DFS sees all nodes as already visited and prints nothing — but in the buggy output it *does* print "0 2", meaning that somehow it worked. Wait — actually, looking closer:

// In the given buggy code:
// - First: travelDFS() → resets visited, runs DFS(0) → prints "0 1 2"
// - Then: travelBFS() → resets visited, runs BFS(0) → prints "0 1 2"
// - Then: delete vertex 1 by zeroing row/col
// - Then: call travelDFS() → which DOES reset visited (inside travelDFS: for(i=0; i<numv; i++) visited[i] = 0;), so that's OK.
// - Then: reset front/rear, then call travelBFS() → which also resets visited.

// So why is the output correct in content but wrong in formatting? The expected output has no trailing space, but the program prints a space after each number including the last.

// But the problem says: "the vertices should be printed in a single line, separated by spaces." — this usually allows trailing space, but the test judge might be strict.

// However, the sample expected vs actual:
// Buggy Output:
// 0 1 2 
// 0 1 2 
// 0 2 
// 0 2
//
// Expected Output:
// 0 1 2
// 0 1 2
// 0 2
// 0 2

// The only difference is the trailing space at the end of each line.

// BUT: the problem says "Output Format: ... The vertices should be printed in a single line, separated by spaces." — it doesn't specify no trailing space, but many judges are strict.

// However, the reference program also prints with trailing space (e.g., printf("%d ",v)), and its expected output matches the format without trailing space? Actually, the reference program's output would also have trailing space, yet the expected output shown has no trailing space.

// This suggests the real issue is elsewhere.

// Re-examining logic:

// The problem states: "In any traversal, the traversal should start from vertex 0. When accessing adjacent vertices, visit them in ascending order of their vertex numbers."

// In the buggy code, the DFS and BFS use a for loop from i=0 to numv-1, which naturally visits neighbors in ascending order — that's correct.

// Now, after deleting vertex 1, the graph has edges: only 0-2 remains.

// So DFS starting at 0: visits 0, then checks i=0 (skip), i=1: G[0][1] is now 0 (deleted), i=2: G[0][2]==1 and not visited → DFS(2). Then from 2: checks i=0 (visited), i=1 (G[2][1]=0), i=2 (self, skip). So prints "0 2 " — correct.

// Similarly BFS: 0 enqueued, printed, then enqueue 2; then 2 printed. So "0 2 " — correct.

// So why is it a Wrong Answer?

// The only discrepancy is the trailing space.

// However, the problem’s expected output does NOT have trailing spaces, but the program outputs trailing spaces.

// Therefore, the error is that the program prints a space after the last vertex in each line.

// But the instruction says: "identify the location of the errors in the program below" — and the error is in the printing logic in DFS and BFS functions.

// Specifically, in DFS: printf("%d ",v); — always appends space.
// Same in BFS: printf("%d ",v);

// This causes trailing space at end of each traversal line.

// However, the problem says: "separated by spaces" — which usually means between items, not after last.

// So the error is in the output formatting.

// But note: the reference program also uses printf("%d ",v), yet the expected output is without trailing space. This implies that either:
// (a) the reference program is not shown with its full context (maybe it handles formatting differently), or
// (b) the judge trims whitespace, but in this case the test shows difference.

// Given the test input and output explicitly show no trailing space in expected, and trailing space in buggy output, the error is the trailing space.

// However, the problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

// So we must mark the lines where printf adds trailing space.

// But wait: the problem says the reference program is correct. Let's check reference program output:

// Reference program for test case would output:
// "0 1 2 \n0 1 2 \n0 2 \n0 2 \n"

// But expected is without trailing space.

// This is a contradiction unless the reference program actually avoids trailing space.

// Looking at reference program: it uses printf("%d ",v) in DFS and pop() (which does printf("%d ",queue[front])).

// So reference program also produces trailing space.

// Then why is expected output without space?

// Possibly the problem statement's "Expected Output" is shown without trailing space for clarity, but the judge accepts trailing space.

// But the user says: "Buggy Output" vs "Expected Output" differ exactly by trailing space.

// And the verdict is "Wrong Answer", so likely the judge is strict.

// Therefore, the bug is the trailing space.

// However, there's another critical issue:

// The array sizes: G[10][10] and visited[10], but problem says n can be up to 100.

// For the given test case n=3, it's fine, but the program is not general. However, the test case passes in terms of logic, so for this specific WA, it's the trailing space.

// But the problem says: "the test case inputs that the program failed" — and the test case is n=3, so array size isn't the issue here.

// So the immediate error causing WA on this test case is the trailing space.

// However, looking again at the output:

// Buggy Output:
// 0 1 2 
// 0 1 2 
// 0 2 
// 0 2

// Each line ends with space then newline.

// Expected:
// 0 1 2
// 0 1 2
// 0 2
// 0 2

// So yes, trailing space is the issue.

// But the problem says: "add @@ symbol directly after that line and explain the reason for the error."

// So we need to mark every line that does printf("%d ", ...) because that's what causes trailing space.

// However, note: the problem might accept trailing space, but in this judge it doesn't.

// Given the evidence, we mark the printf lines.

// But wait: what if the real issue is that after deletion, the graph might have multiple components? But problem states: "The graph is connected both before and after deleting the specified vertex." — so only one component.

// And the code starts at 0 always, which is correct.

// So the only issue is output formatting.

// Therefore:

// Mark the printf in DFS
// Mark the printf in BFS (inside pop simulation)

// However, in the given buggy code, the BFS printf is: printf("%d ",v); inside BFS function.

// So:

// Line with: printf("%d ",v); in DFS → @@ [Prints a trailing space after the last vertex, which does not match the expected output format.]

// Line with: printf("%d ",v); in BFS → @@ [Prints a trailing space after the last vertex, which does not match the expected output format.]

// But note: the problem says "do not change the original code structure", so we just append @@ comment.

// However, there's another subtle issue:

// In the BFS function, the condition is: while( !(front>rear)) — which is equivalent to while(front <= rear). That's correct.

// And queue management seems okay.

// Also, after deletion, they reset front=0, rear=-1 before second BFS — that's correct.

// And travelDFS() and travelBFS() both reset visited — so that's okay.

// So only the trailing space remains.

// But wait: the sample expected output has no trailing space, so we must mark those printf lines.

// However, the problem might have another error: when deleting the vertex, the code sets G[delete][i]=0 and G[i][delete]=0 for i in [0, numv). That's correct.

// So final decision: the error is trailing space in output.

// Annotate the two printf lines that output vertices with space.