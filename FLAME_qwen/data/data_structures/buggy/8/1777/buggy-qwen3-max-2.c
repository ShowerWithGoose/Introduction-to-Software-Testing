#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The program uses an infinite loop with `while(~scanf(...))`, which will keep reading input indefinitely instead of processing a single test case as required. This causes incorrect behavior and does not match the expected output format. Additionally, it prints n and m instead of performing graph traversal operations.]
    {
        printf("%d %d\n",n,m); // @@ [This line merely echoes the input values n and m, rather than implementing DFS/BFS traversals before and after vertex deletion as required by the problem.]
    }
    return 0;
}