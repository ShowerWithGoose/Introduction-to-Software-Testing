#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The loop condition `while(~scanf(...))` causes infinite looping on EOF or input failure, and the program does not implement graph traversal logic as required. Additionally, it merely prints n and m instead of performing DFS/BFS before and after vertex deletion.]
    {
        printf("%d %d\n",n,m); // @@ [This line only outputs the input values n and m, not the DFS/BFS traversal sequences as required by the problem. The entire logic for building the graph, performing traversals, deleting a vertex, and re-traversing is missing.]
    }
    return 0;
}