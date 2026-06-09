#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF) // @@ Error: This loop reads all integers sequentially without parsing graph structure. No adjacency list or matrix built. No DFS/BFS implemented.
    {
        printf("%d ",a); // @@ Error: Prints all input numbers instead of the required traversal sequences. Should output DFS and BFS sequences both before and after deletion.
    }
    return 0;
}