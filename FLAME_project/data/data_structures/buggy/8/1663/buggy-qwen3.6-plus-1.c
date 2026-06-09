#include<stdio.h>
int main()
{
    int a; // @@ The program fails to implement the required graph traversal logic (DFS/BFS) and vertex deletion. It merely echoes the input integers instead of processing the graph structure and producing the specified traversal sequences.
    while(scanf("%d",&a)!=EOF) // @@ The input reading loop consumes all input without storing the graph structure (adjacency matrix/list) or the vertex to delete, making it impossible to perform the required computations.
    {
        printf("%d ",a); // @@ This line incorrectly prints the raw input values instead of the calculated DFS and BFS traversal results before and after vertex deletion.
    }
    return 0;
}