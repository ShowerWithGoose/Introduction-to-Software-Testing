#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ Error: gets() is unsafe and removed in C11; program does not implement DFS/BFS traversals.
        puts(s); // @@ Error: only echoes input, does not produce required output format.
    return 0;
}