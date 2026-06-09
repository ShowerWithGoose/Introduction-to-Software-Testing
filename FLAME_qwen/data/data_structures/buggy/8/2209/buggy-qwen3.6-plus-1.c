#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ The 'gets' function has been removed from the C11 standard, causing a compilation error in modern compilers. Additionally, the code completely lacks the required logic to parse graph input, perform DFS/BFS traversals, and handle vertex deletion.
        puts(s); // @@ The program merely echoes the input lines instead of computing and outputting the required traversal sequences before and after vertex deletion.
    return 0;
}