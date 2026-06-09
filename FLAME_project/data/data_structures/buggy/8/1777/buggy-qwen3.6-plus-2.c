#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ The program fails to implement the graph logic, DFS, BFS, and vertex deletion. It only reads and prints n and m, ignoring edges and traversal requirements.
    {
        printf("%d %d\n",n,m); // @@ This output is incorrect; the program should output traversal sequences, not just the input dimensions.
    }
    return 0;
}