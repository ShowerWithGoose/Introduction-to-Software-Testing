#include <stdio.h>

int main()
{
    char s[100] = ""; // @@ The provided source code is completely unrelated to the problem description (graph traversal). It simply echoes input lines. The correct implementation requires graph data structures, DFS, BFS, and vertex deletion logic as shown in the reference program. This entire main function is incorrect for the given problem.
    while (gets(s) != NULL) // @@ gets is unsafe and deprecated; furthermore, the logic here does not perform any graph operations.
        puts(s); // @@ This just prints the input back, failing to produce the required DFS/BFS traversal sequences.
    return 0;
}