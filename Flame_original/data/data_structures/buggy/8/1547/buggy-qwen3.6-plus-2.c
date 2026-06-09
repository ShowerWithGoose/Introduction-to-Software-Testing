#include<stdio.h>
#include<stdlib.h>
int main()
{
    char data[1005]; // @@ Unused variable; the program lacks necessary graph data structures (e.g., adjacency matrix/list) and traversal algorithms.
    char c;
    while(scanf("%c",&c)!=EOF) // @@ Fails to read the specified input format (n, m, edges, vertex to delete) and does not implement any graph processing logic.
    {
        printf("%c",c); // @@ Merely echoes input characters instead of computing and printing the required DFS and BFS vertex sequences before and after deletion.
    }
    return 0;
    
}