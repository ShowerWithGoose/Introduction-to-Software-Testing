#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b; // @@ Insufficient variable declarations; needs arrays/structures to store the graph, visited status, and traversal queues/stacks.
    while(scanf("%d %d",&a,&b)!=EOF) // @@ Incorrect input handling; should read n and m once, then read m edges and the target vertex, rather than looping until EOF.
    {
        printf("%d %d\n",a,b); // @@ Fails to implement graph construction, DFS, BFS, or vertex deletion; only prints n and m instead of the required traversal sequences.
    }
    return 0;
}