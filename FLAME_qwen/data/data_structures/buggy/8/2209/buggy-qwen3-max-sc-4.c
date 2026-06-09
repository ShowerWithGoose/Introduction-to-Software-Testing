#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. Additionally, the problem requires implementing DFS/BFS traversal logic, but this code merely echoes input lines without any graph processing.]
        puts(s);
    return 0;
}