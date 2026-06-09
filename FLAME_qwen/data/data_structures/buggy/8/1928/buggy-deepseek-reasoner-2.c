#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ This loop only reads integers and does not process the graph input, missing reading of vertices, edges, and deletion vertex.
    
    printf("%d\n",x); // @@ This prints each integer but does not perform DFS/BFS traversal as required by the problem.
    return 0;
}