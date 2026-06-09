#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ [This loop consumes all input including n, m, edges, and the vertex to delete, but does not store or process the graph structure. It only retains the last integer read in x.]
    
    printf("%d\n",x); // @@ [This prints only the last integer read (the vertex to delete), instead of performing DFS/BFS traversals before and after deletion as required. The output format is completely wrong.]
    return 0;
}