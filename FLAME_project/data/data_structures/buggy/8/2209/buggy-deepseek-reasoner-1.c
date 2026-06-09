#include <stdio.h>

int main()
{
    char s[100] = "";  // @@ This does not follow input format; should parse n,m, edges, and d.
    while (gets(s) != NULL)  // @@ Incorrect input handling; should read graph structure and perform DFS/BFS.
        puts(s);  // @@ Outputs raw input instead of vertex sequences as required.
    return 0;
}