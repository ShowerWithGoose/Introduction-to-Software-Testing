#include <stdio.h>

int main()
{
    char s[100] = ""; // @@ Error: This array is not used for the required graph operations; it only stores input lines temporarily.
    while (gets(s) != NULL) // @@ Error: The program should parse integer input for graph vertices and edges, not treat whole lines as strings.
        puts(s); // @@ Error: This outputs the raw input instead of the DFS/BFS traversal sequences expected by the problem.
    return 0;
}