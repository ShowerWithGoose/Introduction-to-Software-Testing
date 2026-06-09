#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ The program only reads input integers and prints them, completely ignoring the graph structure, traversal algorithms (DFS/BFS), and vertex deletion logic required by the problem. It fails to implement the core functionality.
    
    printf("%d\n",x); // @@ This line is executed outside the intended loop body due to missing braces, or even if inside, it just echoes input instead of performing graph traversals. The output format and content are entirely incorrect.
    return 0;
}