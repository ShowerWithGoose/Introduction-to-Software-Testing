#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ This loop incorrectly reads all input as pairs, ignoring the problem's input format. Should read n and m once, then loop m times for edges, then read vertex to delete.
    {
        printf("%d %d\n",n,m); // @@ This prints the raw input, not the required DFS/BFS sequences. Should implement graph traversal and output sequences before and after deletion.
    }
    return 0;
}