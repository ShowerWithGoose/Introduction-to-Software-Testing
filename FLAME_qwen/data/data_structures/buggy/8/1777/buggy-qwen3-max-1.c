#include <math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)) // @@ [The program uses an infinite loop with while(~scanf(...)), which will not terminate properly for a single test case as required. The problem expects only one graph input, not multiple. Additionally, the output format is completely wrong—it just prints n and m instead of performing DFS/BFS traversals before and after deletion.]
    {
        printf("%d %d\n",n,m); // @@ [This line outputs the number of vertices and edges, which is not part of the expected output. The expected output should be four lines of vertex traversal sequences (DFS before, BFS before, DFS after, BFS after).]
    }
    return 0;
}