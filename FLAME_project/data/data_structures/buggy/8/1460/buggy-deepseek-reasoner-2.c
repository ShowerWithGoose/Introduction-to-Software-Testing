#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a; // @@ [Declares only one integer variable, insufficient for storing graph data, visited arrays, etc.]
    scanf("%d",&a); // @@ [Only reads the first integer from input (n), but the program should read n, m, then m edges, then the vertex to delete. This leads to incomplete data and wrong output.]
    printf("%d ",a); // @@ [Prints only the first integer, but the program should output DFS and BFS sequences for the graph before and after deletion, as described in the problem.]
    return 0;
}