#include<stdio.h>

int main()
{
    int x; // @@ [The variable x is used to read input but no graph data structure is defined; the program does not implement the required graph traversal.]
    while(scanf("%d",&x)!=EOF) // @@ [This loop reads all integers from input, but it does not parse the graph structure (n, e, edges, delete vertex) correctly; it simply echoes numbers instead of constructing the graph and performing DFS/BFS.]
    
    printf("%d\n",x); // @@ [This prints each read integer on its own line, which is not the expected output format. The program should output four lines of space-separated vertex sequences, not individual numbers.]
    return 0;
}