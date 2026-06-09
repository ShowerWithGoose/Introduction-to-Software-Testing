#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b; // @@ Only declares two integers, lacking necessary data structures for graph representation, visited tracking, and traversal queues/stacks.
    while(scanf("%d %d",&a,&b)!=EOF) // @@ Incorrectly uses an EOF loop and only reads n and m, completely ignoring the input of m edges and the vertex to delete.
    {
        printf("%d %d\n",a,b); // @@ Simply echoes the input values instead of performing DFS and BFS traversals to output the required vertex sequences.
    }
    return 0;
}