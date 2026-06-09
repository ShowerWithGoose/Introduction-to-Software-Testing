#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [Error: This loop continuously reads pairs from input, but the program should read n and m once, then process the graph edges and deletion vertex. It also fails to handle partial reads, causing incorrect behavior.]
    {
        printf("%d %d\n",n,m); // @@ [Error: Output should be the DFS and BFS sequences (before and after deletion), not the input numbers. The entire graph traversal and deletion logic is missing.]
    }
    return 0;
}