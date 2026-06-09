#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a; // @@ [Error: Only a single integer variable declared; need to declare variables for graph representation and traversal.]
    scanf("%d",&a); // @@ [Error: Only reads one integer; should read n, m, then edges, then delete vertex.]
    printf("%d ",a); // @@ [Error: Outputs only one integer; should output DFS and BFS sequences before and after deletion.]
    return 0;
}