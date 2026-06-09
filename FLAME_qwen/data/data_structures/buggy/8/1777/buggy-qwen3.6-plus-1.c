#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ The problem specifies a single test case input format, and this loop incorrectly attempts to read multiple cases. It also fails to read the m edges and the vertex to be deleted.
    {
        printf("%d %d\n",n,m); // @@ This only prints n and m, completely failing to implement the required DFS and BFS traversals before and after vertex deletion, and does not match the expected output format.
    }
    return 0;
}