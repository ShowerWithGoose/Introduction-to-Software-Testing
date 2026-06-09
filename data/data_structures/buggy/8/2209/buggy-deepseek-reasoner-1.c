#include <stdio.h>

int main()
{
    char s[100] = ""; // @@ The program does not read the graph structure; instead it reads lines and prints them, failing to implement DFS/BFS as required.
    while (gets(s) != NULL) // @@ This loop reads input lines but does not process them according to problem requirements (graph construction, traversal). Should read n, m, edges, and delete vertex.
        puts(s); // @@ This outputs the input lines, not the required traversal sequences.
    return 0;
}