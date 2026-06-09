#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The program uses an infinite loop with `while(~scanf(...))`, which will keep reading input indefinitely instead of processing a single test case as required. Additionally, it only prints n and m, not performing any graph traversal or vertex deletion logic.]
    {
        printf("%d %d\n",n,m); // @@ [This line merely echoes the input values n and m, but the problem requires DFS and BFS traversals before and after vertex deletion. The entire logic for building the graph, performing traversals, and handling vertex deletion is missing.]
    }
    return 0;
}