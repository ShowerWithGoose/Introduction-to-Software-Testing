#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)@@ // The loop reads all input integers but does not store or process the graph structure or deletion vertex; it just overwrites 'x' repeatedly.
    
    printf("%d\n",x);@@ // Only prints the last integer read (which is the vertex to delete), instead of performing DFS/BFS traversals before and after deletion.
    return 0;
}