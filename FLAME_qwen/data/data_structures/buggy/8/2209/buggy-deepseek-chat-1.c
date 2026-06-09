#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [gets() is unsafe and removed in C11 standard; also, the program logic is wrong - it just echoes input instead of solving the graph problem]
        puts(s); // @@ [This just prints the input back, not the required DFS/BFS sequences]
    return 0;
}