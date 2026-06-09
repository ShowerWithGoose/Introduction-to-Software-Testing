#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [Logical Error: The program completely lacks the implementation for reading the edge list and the target vertex, building the graph data structure, and performing DFS/BFS traversals. It only reads n and m.]
    {
        printf("%d %d\n",n,m); // @@ [Logical Error: The output does not match the required format. It should print four lines containing the DFS and BFS vertex sequences before and after deleting the specified vertex, not just echo n and m.]
    }
    return 0;
}