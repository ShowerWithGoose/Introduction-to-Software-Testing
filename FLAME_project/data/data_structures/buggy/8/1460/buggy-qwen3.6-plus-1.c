//
//  main.c
//  print
//
//  Created by  on 2024/6/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a; // @@ The program only reads a single integer and prints it, completely ignoring the graph structure, edges, deletion vertex, and required DFS/BFS traversal logic. It fails to implement the problem requirements.
    scanf("%d",&a); // @@ This reads only the first integer (number of vertices n) but ignores the number of edges m, the edge list, and the vertex to delete.
    printf("%d ",a); // @@ This outputs only the number of vertices, whereas the expected output requires DFS and BFS traversal sequences before and after deleting a vertex.
    return 0;
}