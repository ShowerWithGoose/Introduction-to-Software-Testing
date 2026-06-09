#include <stdio.h>

int main()
{
    char s[100] = ""; // @@ [The provided source code is completely unrelated to the problem description. It simply echoes input lines instead of implementing graph traversal (DFS/BFS) and vertex deletion logic.]
    while (gets(s) != NULL) // @@ [This loop reads all input and prints it back, which explains why the "Buggy Output" matches the "Test Case Input" exactly. It fails to perform any graph operations.]
        puts(s); // @@ [The program should implement adjacency list construction, DFS, BFS, and vertex deletion as described in the reference program, not just echo input.]
    return 0;
}