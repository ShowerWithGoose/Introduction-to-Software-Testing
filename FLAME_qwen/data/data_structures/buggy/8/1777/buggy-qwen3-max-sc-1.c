#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The program uses an infinite loop with `while(~scanf(...))`, which is incorrect for the problem's input format that specifies a single test case. This causes the program to either loop indefinitely or behave unexpectedly, and it does not implement DFS/BFS logic at all. Additionally, the output merely prints n and m instead of traversal sequences.]
    {
        printf("%d %d\n",n,m); // @@ [This line outputs the number of vertices and edges, which is not part of the required output. The program completely lacks graph construction, traversal (DFS/BFS), vertex deletion, and proper output formatting as per the problem description.]
    }
    return 0;
}