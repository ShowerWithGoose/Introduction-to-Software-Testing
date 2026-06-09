#include <stdio.h>

int main()
{
    char s[100] = ""; // @@ The program completely lacks the implementation for graph representation, DFS/BFS traversal, and vertex deletion as required.
    while (gets(s) != NULL) // @@ `gets` is removed in C11 standard causing compilation error; also fails to parse input graph data.
        puts(s); // @@ Merely echoes input instead of outputting the correct DFS and BFS sequences.
    return 0;
}