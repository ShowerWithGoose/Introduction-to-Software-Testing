#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d %d\n",a,b);
    }
    return 0;
} // @@ [The entire program is completely wrong and unrelated to the problem. It merely echoes input lines instead of implementing graph traversal (DFS/BFS) before and after vertex deletion. The reference program shows the expected structure, but this code does not even attempt to build a graph, perform traversals, or handle vertex deletion.]