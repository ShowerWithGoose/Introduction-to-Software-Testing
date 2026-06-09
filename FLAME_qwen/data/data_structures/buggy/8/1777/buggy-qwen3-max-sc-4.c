#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The program uses an infinite loop with `while(~scanf(...))`, which causes it to read until EOF, but the problem specifies a single test case. This leads to incorrect behavior and potential runtime issues. Additionally, the output format does not match the problem's requirements—it just prints n and m instead of performing DFS/BFS traversals.]
    {
        printf("%d %d\n",n,m); // @@ [This line outputs the input values instead of the required DFS and BFS traversal sequences before and after vertex deletion. The entire logic for graph construction, traversal, and vertex deletion is missing.]
    }
    return 0;
}