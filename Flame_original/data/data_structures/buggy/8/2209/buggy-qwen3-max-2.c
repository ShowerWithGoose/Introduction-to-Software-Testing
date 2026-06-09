#include <stdio.h>

int main()
{
    char s[100] = "";
    while (gets(s) != NULL) // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. Additionally, the problem requires implementing DFS/BFS traversal logic, but this code merely echoes input lines without any graph processing.]
        puts(s);
    return 0;
}