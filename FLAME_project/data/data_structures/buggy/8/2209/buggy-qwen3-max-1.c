#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL)
        puts(s);
    return 0;
} // @@ [The entire program is completely unrelated to the problem. It simply echoes input lines, whereas the problem requires implementing DFS and BFS traversals on a graph before and after vertex deletion. This explains the wrong answer: it does not process graph input, build adjacency lists, or perform any traversal logic as required.]