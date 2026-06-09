#include<stdio.h>

int main()
{
    int x; // @@ Missing necessary variables for graph representation (n, e, adjacency list/matrix, visited arrays, etc.). Only declares a single integer.
    while(scanf("%d",&x)!=EOF) // @@ Incorrect input reading. Should first read n and e, then m edges, then the deleted vertex. This loop reads all integers as a flat stream, losing the graph structure.
    
    printf("%d\n",x); // @@ Should output DFS and BFS sequences before and after deletion in the specified format, not just each integer on a separate line.
    return 0;
}