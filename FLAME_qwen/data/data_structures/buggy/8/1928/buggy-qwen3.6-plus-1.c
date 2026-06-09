#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ Missing braces for the loop body, and the code completely lacks the required graph data structure, DFS/BFS traversal implementation, and vertex deletion logic.
    
    printf("%d\n",x); // @@ The program merely echoes input integers instead of reading the graph edges, performing the specified traversals, and outputting the correct vertex sequences.
    return 0;
}