#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ This loop reads all input including the graph edges and the delete vertex, but the program should only read the delete vertex after reading the graph structure. The program completely ignores the graph construction and traversal logic, just printing each integer read.
    
    printf("%d\n",x); // @@ This prints each integer on a separate line, but the expected output requires formatted sequences of vertices on single lines with spaces. The program lacks any graph representation, DFS/BFS implementation, or deletion logic.
    return 0;
}